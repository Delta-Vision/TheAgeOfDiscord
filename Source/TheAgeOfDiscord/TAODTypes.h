#pragma once

#include "UObject/PrimaryAssetId.h"
#include "TAODTypes.generated.h"

class UTAODItem;

USTRUCT(BlueprintType)
struct FTAODItemSlot
{
	GENERATED_BODY()

	FTAODItemSlot()
		: SlotNumber(-1)
	{}

	FTAODItemSlot(const FPrimaryAssetType& InItemType, int32 InSlotNumber)
		: ItemType(InItemType)
		, SlotNumber(InSlotNumber)
	{}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
	FPrimaryAssetType ItemType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
	int32 SlotNumber;

	bool operator==(const FTAODItemSlot& Other) const
	{
		return ItemType == Other.ItemType && SlotNumber == Other.SlotNumber;
	}
	bool operator!=(const FTAODItemSlot& Other) const
	{
		return !(*this == Other);
	}

	friend inline uint32 GetTypeHash(const FTAODItemSlot& Key)
	{
		uint32 Hash = 0;

		Hash = HashCombine(Hash, GetTypeHash(Key.ItemType));
		Hash = HashCombine(Hash, (uint32)Key.SlotNumber);
		return Hash;
	}

	bool IsValid() const
	{
		return ItemType.IsValid() && SlotNumber >= 0;
	}
};

USTRUCT(BlueprintType)
struct FTAODItemData
{
	GENERATED_BODY()

	FTAODItemData()
		: ItemCount(1)
		, ItemLevel(1)
	{}

	FTAODItemData(int32 InItemCount, int32 InItemLevel)
		: ItemCount(InItemCount)
		, ItemLevel(InItemLevel)
	{}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
	int32 ItemCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
	int32 ItemLevel;

	bool operator==(const FTAODItemData& Other) const
	{
		return ItemCount == Other.ItemCount && ItemLevel == Other.ItemLevel;
	}
	bool operator!=(const FTAODItemData& Other) const
	{
		return !(*this == Other);
	}

	bool IsValid() const
	{
		return ItemCount > 0;
	}

	void UpdateItemData(const FTAODItemData& Other, int32 MaxCount, int32 MaxLevel)
	{
		if (MaxCount <= 0)
		{
			MaxCount = MAX_int32;
		}

		if (MaxLevel <= 0)
		{
			MaxLevel = MAX_int32;
		}

		ItemCount = FMath::Clamp(ItemCount + Other.ItemCount, 1, MaxCount);
		ItemLevel = FMath::Clamp(Other.ItemLevel, 1, MaxLevel);
	}
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnInventoryItemChanged, bool, bAdded, UTAODItem*, Item);
DECLARE_MULTICAST_DELEGATE_TwoParams(FOnInventoryItemChangedNative, bool, UTAODItem*);


DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSlottedItemChanged, FTAODItemSlot, ItemSlot, UTAODItem*, Item);
DECLARE_MULTICAST_DELEGATE_TwoParams(FOnSlottedItemChangedNative, FTAODItemSlot, UTAODItem*);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInventoryLoaded);
DECLARE_MULTICAST_DELEGATE(FOnInventoryLoadedNative);