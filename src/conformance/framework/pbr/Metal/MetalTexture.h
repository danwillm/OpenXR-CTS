// Copyright 2022-2024, The Khronos Group Inc.
//
// Based in part on code that is:
//
// Copyright (C) Microsoft Corporation.  All Rights Reserved
// Licensed under the MIT License. See License.txt in the project root for license information.
//
// SPDX-License-Identifier: MIT AND Apache-2.0

#pragma once

#include "MetalResources.h"

#include "../PbrCommon.h"

#include "utilities/metal_utils.h"

#include <Foundation/Foundation.hpp>
#include <Metal/Metal.hpp>
#include <QuartzCore/QuartzCore.hpp>

#include <array>

namespace Pbr
{
    namespace MetalTexture
    {
        std::array<uint8_t, 4> LoadRGBAUI4(RGBAColor color);

        NS::SharedPtr<MTL::Texture> LoadTextureImage(MetalResources& pbrResources, const uint8_t* fileData, uint32_t fileSize,
                                                     const NS::String* label);

        NS::SharedPtr<MTL::Texture> CreateFlatCubeTexture(MetalResources& pbrResources, RGBAColor color, MTL::PixelFormat format,
                                                          const NS::String* label);

        NS::SharedPtr<MTL::Texture> CreateTexture(MetalResources& pbrResources, const uint8_t* rgba, int elemSize, int width, int height,
                                                  MTL::PixelFormat format, const NS::String* label);

        NS::SharedPtr<MTL::Texture> CreateTexture(MTL::Device* device, const uint8_t* rgba, int elemSize, int width, int height,
                                                  MTL::PixelFormat format, const NS::String* label);

        NS::SharedPtr<MTL::SamplerDescriptor> DefaultSamplerDesc();
        NS::SharedPtr<MTL::SamplerState> CreateSampler(MTL::Device* device,
                                                       MTL::SamplerAddressMode addressMode = MTL::SamplerAddressModeClampToEdge);
    }  // namespace MetalTexture
}  // namespace Pbr