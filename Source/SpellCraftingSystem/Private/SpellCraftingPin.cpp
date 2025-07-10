#include "SpellCraftingPin.h"

#include "../Public/SpellCraftingSystem.h"
#include "../Public/SpellEffect.h"

USpellEffect* USpellCraftingPin::SetData() {
    USpellEffect* NewEffect = NewObject<USpellEffect>(this);
    this->SpellData = NewEffect;
    return NewEffect;
}

USpellEffect* USpellCraftingPin::SetData(USpellEffect* Template) {
    if (Template == nullptr) {
        UE_LOG(LogCraftingSystem, Error, TEXT("Cannot create spell effect from null template!"));
        return nullptr;
    }
    
    USpellEffect* NewEffect = NewObject<USpellEffect>(this);
    Template->CloneTo(NewEffect);
    this->SpellData = NewEffect;
    return NewEffect;
}

USpellEffect* USpellCraftingPin::FetchDataFrom(USpellCraftingPin* Source) {
    if (!Source->SpellData.IsValid()) {
        UE_LOG(LogCraftingSystem, Error, TEXT("Cannot fetch data from a pin with no data"));
        USpellEffect* NewEffect = NewObject<USpellEffect>(this);
        this->SpellData = NewEffect;
        return NewEffect;   
    }
        
    USpellEffect* Effect = Source->SpellData.Get();
    this->SpellData = Effect;
    return Effect;
}

USpellEffect* USpellCraftingPin::CloneDataFrom(USpellCraftingPin* Source) {
    if (Source == nullptr || !Source->SpellData.IsValid()) {
        UE_LOG(LogCraftingSystem, Error, TEXT("Cannot clone data from a pin with no data"));
        return nullptr;  
    }
    
    return this->SetData(Source->SpellData.Get());
}

USpellEffect* USpellCraftingPin::MergeDataFrom(const TArray<USpellCraftingPin*>& Sources) {
    USpellEffect* Effect = this->SetData();
    for (const USpellCraftingPin* Source : Sources) {
        if (!Source->SpellData.IsValid()) {
            UE_LOG(LogCraftingSystem, Warning, TEXT("Skipped a pin with no data while merging effects."));
            continue;
        }
        
        Effect->Merge(Source->SpellData.Get());
    }

    return Effect;  
}
