#pragma once

#include "CoreMinimal.h"
#include "SpellCraftingSystem.h"
#include "SpellCraftingPin.generated.h"

class USpell;
class USpellCraftingNode;
class USpellEffect;

UCLASS(BlueprintType)
class SPELLCRAFTINGSYSTEM_API USpellCraftingPin : public UObject {
    GENERATED_BODY()
    
private:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = true))
    FText Name;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = true))
    bool IsOptional;

    TWeakObjectPtr<USpellEffect> SpellData;

public:
    UPROPERTY()
    TObjectPtr<USpellCraftingNode> OwnerNode;
    
    TWeakObjectPtr<USpellCraftingPin> ConnectedPin;

    FORCEINLINE USpellCraftingPin* WithName(const FText& NewName) {
        this->Name = NewName;
        return this;
    }
    
    FORCEINLINE bool IsConnected() const {
        return this->ConnectedPin.IsValid();
    }

    FORCEINLINE bool IsExecutable() const {
        return this->IsOptional || this->IsConnected();
    }

    USpellEffect* SetData();

    USpellEffect* SetData(USpellEffect* Template);

    USpellEffect* FetchDataFrom(USpellCraftingPin* Source);

    USpellEffect* CloneDataFrom(USpellCraftingPin* Source);

    USpellEffect* MergeDataFrom(const TArray<USpellCraftingPin*>& Sources);
};
