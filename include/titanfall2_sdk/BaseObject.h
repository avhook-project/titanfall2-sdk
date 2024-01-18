//
// Created by Vlad on 18.01.2024.
//
#pragma once


#pragma once
#include <cstddef>


namespace titanfall2_sdk
{
    class BaseObject
    {
    public:
        BaseObject() = delete;

    protected:
        template<class type>
        [[nodiscard]] type& GetByOffset(const std::ptrdiff_t offset) const
        {
            return *reinterpret_cast<type*>((uintptr_t)this + offset);
        }
    };
}
