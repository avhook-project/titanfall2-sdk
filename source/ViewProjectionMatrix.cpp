//
// Created by Vlad on 18.01.2024.
//

#include "titanfall2_sdk/ViewProjectionMatrix.h"
#include <sigscanner/ModuleScanner.h>
#include <stdexcept>
#include <format>


static const std::string viewProjectionMatrixSignature = "48 8D 0D ? ? ? ? E8 ? ? ? ? 48 8D 0D ? ? ? ? 48 83 C4 28 E9 ?"
                                                         " ? ? ? 48 8D 0D ? ? ? ? E9 ? ? ? ? CC CC CC CC 48 83 EC 28 48"
                                                         " 8D 0D";


uml::matrix titanfall2_sdk::GetViewProjectionMatrix()
{
    static const auto& scanResult =
            signature_scanner::ModuleScanner("client.dll").FindPattern(viewProjectionMatrixSignature);

    if (!scanResult.has_value())
        throw std::runtime_error(std::format("Failed to find view-projection matrix! Pattern: '{}'",
                                             viewProjectionMatrixSignature));

    static const auto offsetToList = *(uint32_t*)(scanResult.value()+3);
    static const auto finalPointer = reinterpret_cast<float*>(scanResult.value()+offsetToList+7);

    return {4, 4, finalPointer};
}
