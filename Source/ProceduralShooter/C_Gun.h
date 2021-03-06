// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "C_Gun.generated.h"

UCLASS()
class PROCEDURALSHOOTER_API AC_Gun : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AC_Gun();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void BindToInput();
	void PullTrigger();
	float GetGunDamage();
	int32 GetCurrentNumberOfBulletsInMagazine();
	int32 GetMagazineSize();
	void Reload();
	
private:
	bool BulletTrace(FHitResult& Hit, FVector& ShotDirection);
	AController* GetOwnerController() const;


	UPROPERTY(VisibleAnywhere)
		USceneComponent* Root;

	UPROPERTY(EditAnywhere)
		class UParticleSystem* MuzzleFlash;
	UPROPERTY(EditAnywhere)
		class USoundBase* MuzzleSound;
	UPROPERTY(EditAnywhere)
		class USoundBase* ErrorSound;
	UPROPERTY(EditAnywhere)
		class USoundBase* CoolingDownSound;

	UPROPERTY(EditAnywhere)
		UParticleSystem* HitEffect;
	UPROPERTY(EditAnywhere)
		USoundBase* HitSound;
	UPROPERTY(EditAnywhere)
		float MaxRange = 5000.f;
	UPROPERTY(EditAnywhere)
		float GunDamage = 10.f;
	UPROPERTY(EditAnywhere)
		int32 MagazineSize = 30;
	UPROPERTY()
		int32 BulletsInMagazine = 30;

};
