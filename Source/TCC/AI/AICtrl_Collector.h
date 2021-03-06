// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "AICtrl_Collector.generated.h"

/**
 * 
 */
UCLASS()
class TCC_API AAICtrl_Collector : public AAIController
{
	GENERATED_BODY()

	UBehaviorTreeComponent* BehaviorComp;

	UBlackboardComponent* BlackboardComp;

	UAIPerceptionComponent* PerceptionComp;

	class UAISenseConfig_Sight* Sight;

	AAICtrl_Collector(const class FObjectInitializer& ObjectInitializer);

	// Called to make the AICtrl possess the Character
	virtual void Possess(class APawn* InPawn) override;

	virtual void UnPossess() override;

	UFUNCTION()
	void UpdatePerception(TArray<AActor*> SensedActor);

	UFUNCTION()
	void OnWannaEat();

	UFUNCTION()
	void OnWannaPoop();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	bool CanLookForResource;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	bool UnderAttack;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
	FName LocationKeyName;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
	FName FoundResourceKeyName;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
	FName KnowsWhereToGetResourcesKeyName;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
	FName ResourceKeyName;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
	FName ResourcesLocationKeyName;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
	FName ResourcesRoomKeyName;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
	FName WannaEatKeyName;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
	FName WannaPoopKeyName;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
	FName IsActiveKeyName;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
	FName IsLookingForFoodKeyName;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
	FName FoundFoodKeyName;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
	FName UnderAttackKeyName;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
	FName PlayerMoveToKeyName;

	UFUNCTION(BlueprintCallable, Category = "AI")
	void SetUnderAttack(bool Value);

	UFUNCTION(BlueprintCallable, Category = "AI")
	void OnPlayerMoveTo(FVector Location);

	bool SetTarget(class ABaseCharacter* Target);

	void SetSightRadius(float SightRadius, float LoseSightRadius);
};