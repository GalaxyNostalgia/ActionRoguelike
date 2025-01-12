// Fill out your copyright notice in the Description page of Project Settings.


#include "SExplosiveBarrel.h"

#include "Components/BoxComponent.h"
#include "PhysicsEngine/RadialForceComponent.h"
#include "ProfilingDebugging/CookStats.h"

// Sets default values
ASExplosiveBarrel::ASExplosiveBarrel()
{
 	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>("MeshComp");
	MeshComp->SetSimulatePhysics(true);
	RootComponent = MeshComp;

	ForceComp = CreateDefaultSubobject<URadialForceComponent>("ForceComp");
	ForceComp->SetupAttachment(MeshComp);

	ForceComp->SetAutoActivate(false);

	ForceComp->Radius = 200;
	ForceComp->ImpulseStrength = 2500.0f;
	ForceComp->bImpulseVelChange = false;

	ForceComp->AddCollisionChannelToAffect(ECC_WorldDynamic);
	
}

void ASExplosiveBarrel::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	MeshComp->OnComponentHit.AddDynamic(this, &ASExplosiveBarrel::OnActorHit);
}

void ASExplosiveBarrel::OnActorHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	ForceComp->FireImpulse();
}

