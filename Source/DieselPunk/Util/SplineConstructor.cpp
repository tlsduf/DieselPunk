// Fill out your copyright notice in the Description page of Project Settings.


#include "SplineConstructor.h"

// 생성자
FSplinePath::FSplinePath()
	: Transform(FTransform::Identity)
{
}

// Path 유효성 검사
bool FSplinePath::IsValid() const
{
	return Path.GetSplineLength() > 0.0f;
}

// Spline 에 포인트를 추가합니다.
void FSplinePath::AddSplinePoint(const FVector& InPosition, ESplineCoordinateSpace::Type InCoordinateSpace, ESplinePointType::Type InCurveMode)
{
	const FVector TransformedPosition = (InCoordinateSpace == ESplineCoordinateSpace::World) ?
		Transform.InverseTransformPosition(InPosition) : InPosition;

	// Add the spline point at the end of the array, adding 1.0 to the current last input key.
	// This continues the former behavior in which spline points had to be separated by an interval of 1.0.
	const float InKey = Path.Position.Points.Num() ? Path.Position.Points.Last().InVal + 1.0f : 0.0f;

	EInterpCurveMode&& InterpCurveMode = ConvertSplinePointTypeToInterpCurveMode(InCurveMode);

	Path.Position.Points.Emplace(InKey, TransformedPosition, FVector::ZeroVector, FVector::ZeroVector, InterpCurveMode);
	Path.Rotation.Points.Emplace(InKey, FQuat::Identity, FQuat::Identity, FQuat::Identity, InterpCurveMode);
	Path.Scale.Points.Emplace(InKey, FVector(1.0f), FVector::ZeroVector, FVector::ZeroVector, InterpCurveMode);
}

// Spline 의 포인트를 모두 지웁니다.
void FSplinePath::ClearSplinePoints()
{
	Path.Position.Points.Reset();
	Path.Rotation.Points.Reset();
	Path.Scale.Points.Reset();

	UpdateSpline();
}

// Spline의 변경사항을 업데이트합니다.
void FSplinePath::UpdateSpline()
{
	const bool bClosedLoop = false;
	const bool bStationaryEndpoints = false;
	bool bLoopPositionOverride = false;
	float LoopPosition = 0.0f;
	const FVector& Scale3D = FVector(1.0f);

	// leave, arrive tangent가 세팅되도록 Update를 한 번 해줍니다.
	Path.UpdateSpline(bClosedLoop, bStationaryEndpoints, s_ReparamStepsPerSegment, bLoopPositionOverride, LoopPosition, Scale3D);
}

float FSplinePath::GetSplineLength()
{
	return Path.GetSplineLength();
}

FVector FSplinePath::GetLocationAtDistanceAlongSpline(float Distance)
{
	const float Param = Path.ReparamTable.Eval(Distance, 0.0f);
	
	FVector location =  Path.Position.Eval(Param, FVector::ZeroVector);
	
	location = Transform.TransformPosition(location);
	
	return location;
}

FRotator FSplinePath::GetRotationAtDistanceAlongSpline(float Distance)
{
	const float Param = Path.ReparamTable.Eval(Distance, 0.0f);
	
	FQuat Quat = Path.Rotation.Eval(Param, FQuat::Identity);
	Quat.Normalize();
	
	const FVector Direction = Path.Position.EvalDerivative(Param, FVector::ZeroVector).GetSafeNormal();
	const FVector UpVector = Quat.RotateVector(FVector(0,0,1));
	
	FQuat Rot = (FRotationMatrix::MakeFromXZ(Direction, UpVector)).ToQuat();
	
	Rot = Transform.GetRotation() * Rot;

	return Rot.Rotator();
}

// 주어진 월드 위치(InWorldLocation)로부터 가장 가까운 Spline Distance 리턴
float FSplinePath::GetDistanceClosestPointToWorldLocation(const FVector& InWorldLocation) const
{
	const FVector LocalLocation = Transform.InverseTransformPosition(InWorldLocation);
	float Dummy;
	float&& InputKey = Path.Position.FindNearest(LocalLocation, Dummy);

	const int32 NumPoints = Path.Position.Points.Num();
	const int32 NumSegments = NumPoints - 1;

	if ((InputKey >= 0) && (InputKey < NumSegments))
	{
		const int32 PointIndex = FMath::FloorToInt(InputKey);
		const float Fraction = InputKey - PointIndex;
		const int32 ReparamPointIndex = PointIndex * s_ReparamStepsPerSegment;
		const float Distance = Path.ReparamTable.Points[ReparamPointIndex].InVal;
		return Distance + Path.GetSegmentLength(PointIndex, Fraction, false, Transform.GetScale3D());
	}
	else if (InputKey >= NumSegments)
	{
		return Path.GetSplineLength();
	}

	return 0.0f;
}