//
// Created by Vlad on 18.01.2024.
//
#pragma once
#include "titanfall2_sdk/BaseObject.h"
#include <uml/Vector3.h>


namespace titanfall2_sdk
{

    class [[maybe_unused]] BaseEntity : public BaseObject
    {
    public:
        BaseEntity() = delete;

        [[nodiscard]] [[maybe_unused]] int GetHealth() const;
        [[nodiscard]] [[maybe_unused]] uml::Vector3 GetOrigin() const;
        [[nodiscard]] [[maybe_unused]] int GetTeamNumber() const;
        [[nodiscard]] [[maybe_unused]] int GetMaxHealth() const;
        [[nodiscard]] [[maybe_unused]] uml::Vector3 GetCameraViewOffset() const;
        [[nodiscard]] [[maybe_unused]] uml::Vector3 GetCameraViewPosition() const;
        [[nodiscard]] [[maybe_unused]] bool IsInTitan() const;
    };

} // titanfall2_sdk
