//
// Created by Vlad on 18.01.2024.
//

#include "titanfall2_sdk/EntityList.h"
#include <Windows.h>


namespace titanfall2_sdk
{

    const EntityList& EntityList::Get()
    {
        static const auto& entList = *reinterpret_cast<const EntityList*>((uintptr_t)GetModuleHandleA("client.dll") + 0xDC9E28);

        return entList;
    }

    BaseEntity *EntityList::GetEntityById(size_t id)
    {
        return GetByOffset<BaseEntity*>(static_cast<std::ptrdiff_t>(id) * 0x20);
    }
} // titanfall2_sdk