// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "US_BasePickup.generated.h"

UCLASS()
class UNREALSHADOWS_LOTL_API AUS_BasePickup : public AActor
{
	GENERATED_BODY()
	
	// �Ⱦ� ���͸� Ʈ������ Collision Component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class USphereComponent> SphereCollision;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UStaticMeshComponent> Mesh;

public:	
	// Sets default values for this actor's properties
	AUS_BasePickup();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called when this actor overlaps with other actor
	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	// �������Ʈ���� �Լ��� �������� �� ������, ���� ������ �⺻ ����Ƽ�� C++ ���� ȣ���ϵ��� �Ⱦ� �׼� �Լ� �߰�
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Pickup", meta = (DisplayName = "Pickup"))
	void Pickup(class AUS_Character* OwningCharacter);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FORCEINLINE USphereComponent* GetSphereCollision() const { return SphereCollision; }
	FORCEINLINE UStaticMeshComponent* GetMesh() const { return Mesh; }
};
