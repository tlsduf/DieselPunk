

#include "BTService_RotateToTarget.h"

#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "DieselPunk/Character/CharacterBase.h"
#include "Kismet/KismetMathLibrary.h"


UBTService_RotateToTarget::UBTService_RotateToTarget()
{
	NodeName = "Rotate To Target";
}

void UBTService_RotateToTarget::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	if(OwnerComp.GetAIOwner() == nullptr)
		return;

	// AIController , self
	AAIController *AIController = OwnerComp.GetAIOwner();
	ACharacterBase* AICharacter = Cast<ACharacterBase>(AIController->GetPawn());
	if(AICharacter == nullptr)
		return;
	
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (BlackboardComp)
	{
		UObject* TargetObject = BlackboardComp->GetValueAsObject(GetSelectedBlackboardKey());
		FVector TargetLocation;
		if (AActor* TargetActor = Cast<AActor>(TargetObject))
		{
			TargetLocation = TargetActor->GetActorLocation();
		}
		else if (BlackboardComp->IsVectorValueSet(GetSelectedBlackboardKey()))
		{
			TargetLocation = BlackboardComp->GetValueAsVector(GetSelectedBlackboardKey());
		}
		else
		{
			return; // If no valid target, return
		}
		
		FRotator LookAtRotation = UKismetMathLibrary::FindLookAtRotation(AIController->GetPawn()->GetActorLocation(), TargetLocation);
		//AIController->GetPawn()->SetActorRotation(LookAtRotation);
		AICharacter->SetActorRotation(LookAtRotation);
	}
}
