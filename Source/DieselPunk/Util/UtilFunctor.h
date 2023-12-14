


#pragma once


// 확률계산 함수 // 입력한 확률(0 ~ 1)로 성공여부 반환
FORCEINLINE bool CalProbability(float inPercentage)
{
	bool success = (FMath::RandRange(0 , 100000) <= 100000 * inPercentage);
	
	return success;
}

// 입력한 방향(InRot)이 InDirection.Yaw - InYaw 과 InDirection.Yaw + InYaw 사이에 있는지 판별합니다.
FORCEINLINE bool IsBetweenYaw(FRotator InRot, FRotator InDirection, float InYaw)
{
	// + Yaw =======================================================================
	const float yawInRot = InRot.Yaw;
	const float checkYaw = yawInRot + InYaw;
	const float normalCheckYaw = FRotator::NormalizeAxis(yawInRot + InYaw);
	
	const float min = (yawInRot > normalCheckYaw) ? normalCheckYaw : yawInRot;
	const float max = (yawInRot > normalCheckYaw) ? yawInRot : normalCheckYaw;
	
	bool nealyEqual = abs( checkYaw - normalCheckYaw ) <= 0.1;

	bool inRange = nealyEqual ?
		((min <= InDirection.Yaw) && (InDirection.Yaw <= max))
	:	((min < InDirection.Yaw) && (InDirection.Yaw < max));
	
	bool isBetweenPlus =  nealyEqual ? inRange : !inRange;

	// - Yaw =======================================================================
	const float yawInRot2 = InRot.Yaw;
	const float checkYaw2 = yawInRot2 - InYaw;
	const float normalCheckYaw2 = FRotator::NormalizeAxis(yawInRot2 - InYaw);
	
	const float min2 = (yawInRot2 > normalCheckYaw2) ? normalCheckYaw2 : yawInRot2;
	const float max2 = (yawInRot2 > normalCheckYaw2) ? yawInRot2 : normalCheckYaw2;

	
	bool nealyEqual2 = abs(checkYaw2 - normalCheckYaw2) <= 0.1;

	bool inRange2 = nealyEqual2 ?
		((min2 <= InDirection.Yaw) && (InDirection.Yaw <= max2))
	:	((min2 < InDirection.Yaw) && (InDirection.Yaw < max2));
	
	bool isBetweenMinus =  nealyEqual2 ? inRange2 : !inRange2;

	// return ======================================================================
	return isBetweenPlus || isBetweenMinus;
}