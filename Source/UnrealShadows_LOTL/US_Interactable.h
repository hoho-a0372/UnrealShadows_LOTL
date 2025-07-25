#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "US_Interactable.generated.h"

UINTERFACE(MinimalAPI, Blueprintable)
class UUS_Interactable : public UInterface
{
	GENERATED_BODY()
};

class UNREALSHADOWS_LOTL_API IUS_Interactable
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Interation", meta = (DisplayName = "Interact"))
	void Interact(class AUS_Character* CharacterInstigator);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Interation", meta = (DisplayName = "Can Interact"))
	void CanInteract(AUS_Character* CharacterInstigator) const;
};