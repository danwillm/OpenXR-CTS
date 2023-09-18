// Copyright (c) 2017-2023, The Khronos Group Inc.
//
// SPDX-License-Identifier: Apache-2.0

#pragma once

#include <openxr/openxr.h>

#include <vector>

namespace Conformance
{
    /**
     * @defgroup cts_rgba RGBA image support
     * @ingroup cts_framework
     */
    ///@{
    union RGBA8Color
    {
        struct
        {
            uint8_t R;
            uint8_t G;
            uint8_t B;
            uint8_t A;
        } Channels;

        uint32_t Pixel;
    };

    static_assert(sizeof(RGBA8Color) == 4, "Incorrect RGBA8Color size");

    /// A 2D, 32 bit-per-pixel RGBA image
    struct RGBAImage
    {
        RGBAImage(int width, int height);

        static RGBAImage Load(const char* path);

        void PutText(const XrRect2Di& rect, const char* text, int pixelHeight, XrColor4f color);
        void DrawRect(int x, int y, int w, int h, XrColor4f color);
        void DrawRectBorder(int x, int y, int w, int h, int thickness, XrColor4f color);
        void ConvertToSRGB();

        bool isSrgb = false;
        std::vector<RGBA8Color> pixels;
        int width;
        int height;
    };
    /// @}
}  // namespace Conformance
