//
// Created by Vlad on 18.01.2024.
//

#pragma once
#include "titanfall2_sdk/BaseEntity.h"


namespace titanfall2_sdk
{

    class EntityList : public BaseObject
    {
    public:
        EntityList() = delete;
        EntityList(const EntityList&) = delete;

        [[nodiscard]] [[maybe_unused]] static const EntityList& Get();
        [[nodiscard]] [[maybe_unused]] BaseEntity* GetEntityById(size_t id) const;

    };

} // titanfall2_sdk
