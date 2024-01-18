//
// Created by Vlad on 18.01.2024.
//

#include "../include/titanfall2_sdk/BaseEntity.h"

namespace titanfall2_sdk
{
    int BaseEntity::GetHealth() const
    {
        return GetByOffset<int>(0x390);
    }

    uml::Vector3 BaseEntity::GetOrigin() const
    {
        return GetByOffset<uml::Vector3>(0x90);
    }

    int BaseEntity::GetTeamNumber() const
    {
        return GetByOffset<int>(0x3A4);
    }

    int BaseEntity::GetMaxHealth() const
    {
        return GetByOffset<int>(0x4a8);
    }

    uml::Vector3 BaseEntity::GetCameraViewOffset() const
    {
        return GetByOffset<uml::Vector3>(0x460);
    }

    uml::Vector3 BaseEntity::GetCameraViewPosition() const
    {
        return GetOrigin() + GetCameraViewOffset();
    }

    bool BaseEntity::IsInTitan() const
    {
        return GetByOffset<bool>(0x3EC);
    }
} // titanfall2_sdk