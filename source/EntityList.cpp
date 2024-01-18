//
// Created by Vlad on 18.01.2024.
//

#include "titanfall2_sdk/EntityList.h"
#include <Windows.h>
#include <sigscanner/ModuleScanner.h>
#include <stdexcept>
#include <format>


static std::string clientEntityListSignature = "48 8D 0D ? ? ? ? E8 ? ? ? ? 48 8D 05 ? ? ? ? 48 8D 0D ? ? ? ? 0F 57 "
                                               "C0 48 89 05 ? ? ? ? 48 8D 05 ? ? ? ? 45 33 C0";

namespace titanfall2_sdk
{

    const EntityList& EntityList::Get()
    {
        static const auto& scanResult =
                signature_scanner::ModuleScanner("client.dll").FindPattern(clientEntityListSignature);

        if (!scanResult.has_value())
            throw std::runtime_error(std::format("Failed to find entity list! Pattern: '{}'",
                                                 clientEntityListSignature));

        static const auto offsetToList = *(uint32_t*)(scanResult.value()+3);
        static const auto finalPointer = reinterpret_cast<EntityList*>(scanResult.value()+offsetToList+7);

        return *finalPointer;
    }

    BaseEntity *EntityList::GetEntityById(size_t id) const
    {
        constexpr auto vtableSize = sizeof(uintptr_t);

        return GetByOffset<BaseEntity*>(static_cast<std::ptrdiff_t>(id) * 0x20 + vtableSize);
    }
} // titanfall2_sdk