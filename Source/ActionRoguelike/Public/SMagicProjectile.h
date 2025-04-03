

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SMagicProjectile.generated.h"


class USphereComponent;
class UProjectileMovementComponent;
class UParticleSystemComponent;
UCLASS()
class ACTIONROGUELIKE_API ASMagicProjectile : public ASProjectileBase
{
	GENERATED_BODY()
	
public:
	ASMagicProjectile();

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:	

	// Called every frame
	virtual void Tick(float DeltaTime) override;
};