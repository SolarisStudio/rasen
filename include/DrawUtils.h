#pragma once

#include <raylib.h>

namespace DrawUtils {

    // Draws a rectangle that appears to pop out of the screen
    inline void DrawRectangleOutset(Rectangle rect, float thickness, Color baseColor) {
        Color light = ColorBrightness(baseColor, 0.4f);
        Color shadow = ColorBrightness(baseColor, -0.4f);

        // Background
        DrawRectangleRec(rect, baseColor);

        // Top Edge
        DrawRectangle(rect.x, rect.y, rect.width, thickness, light);
        // Left Edge
        DrawRectangle(rect.x, rect.y, thickness, rect.height, light);

        // Bottom Edge
        DrawRectangle(rect.x, rect.y + rect.height - thickness, rect.width, thickness, shadow);
        // Right Edge
        DrawRectangle(rect.x + rect.width - thickness, rect.y, thickness, rect.height, shadow);
    }

    // Draws a rectangle that appears sunken into the screen
    inline void DrawRectangleInset(Rectangle rect, float thickness, Color baseColor) {
        Color light = ColorBrightness(baseColor, 0.4f);
        Color shadow = ColorBrightness(baseColor, -0.4f);

        // Background
        DrawRectangleRec(rect, baseColor);

        // Top Edge (Shadow for Inset)
        DrawRectangle(rect.x, rect.y, rect.width, thickness, shadow);
        // Left Edge (Shadow for Inset)
        DrawRectangle(rect.x, rect.y, thickness, rect.height, shadow);

        // Bottom Edge (Highlight for Inset)
        DrawRectangle(rect.x, rect.y + rect.height - thickness, rect.width, thickness, light);
        // Right Edge (Highlight for Inset)
        DrawRectangle(rect.x + rect.width - thickness, rect.y, thickness, rect.height, light);
    }

    // Draws a circle that pops out. Light hits the top-left.
    inline void DrawCircleOutset(Vector2 center, float radius, float thickness, Color baseColor) {
        Color light = ColorBrightness(baseColor, 0.4f);
        Color shadow = ColorBrightness(baseColor, -0.4f);

        // 1. Draw the "rim" or border sectors
        // Top-left sector (Light)
        DrawCircleSector(center, radius, 135, 315, 36, light);
        // Bottom-right sector (Shadow)
        DrawCircleSector(center, radius, 315, 495, 36, shadow);

        // 2. Draw the main face of the circle
        DrawCircleV(center, radius - thickness, baseColor);
    }

    // Draws a circle that looks sunken. Shadow is on the top-left.
    inline void DrawCircleInset(Vector2 center, float radius, float thickness, Color baseColor) {
        Color light = ColorBrightness(baseColor, 0.4f);
        Color shadow = ColorBrightness(baseColor, -0.4f);

        // 1. Draw the "rim" or border sectors
        // Top-left sector (Shadow for Inset)
        DrawCircleSector(center, radius, 135, 315, 36, shadow);
        // Bottom-right sector (Light for Inset)
        DrawCircleSector(center, radius, 315, 495, 36, light);

        // 2. Draw the inner face
        DrawCircleV(center, radius - thickness, baseColor);
    }

    // Draws a hollow rectangle that pops out (border only)
    inline void DrawRectangleLinesOutset(Rectangle rect, float thickness, Color baseColor) {
        Color light = ColorBrightness(baseColor, 0.4f);
        Color shadow = ColorBrightness(baseColor, -0.4f);

        // --- Outer Bevel ---
        // Top and Left (Light)
        DrawRectangle(rect.x, rect.y, rect.width, thickness, light);
        DrawRectangle(rect.x, rect.y, thickness, rect.height, light);
        // Bottom and Right (Shadow)
        DrawRectangle(rect.x, rect.y + rect.height - thickness, rect.width, thickness, shadow);
        DrawRectangle(rect.x + rect.width - thickness, rect.y, thickness, rect.height, shadow);

        // --- Inner Bevel (Inverted colors to create the "ridge") ---
        float innerX = rect.x + thickness;
        float innerY = rect.y + thickness;
        float innerW = rect.width - (thickness * 2);
        float innerH = rect.height - (thickness * 2);

        // Top and Left (Shadow)
        DrawRectangle(innerX, innerY, innerW, thickness, shadow);
        DrawRectangle(innerX, innerY, thickness, innerH, shadow);
        // Bottom and Right (Light)
        DrawRectangle(innerX, innerY + innerH - thickness, innerW, thickness, light);
        DrawRectangle(innerX + innerW - thickness, innerY, thickness, innerH, light);
    }

    // Draws a hollow rectangle that looks sunken (border only)
    inline void DrawRectangleLinesInset(Rectangle rect, float thickness, Color baseColor) {
        Color light = ColorBrightness(baseColor, 0.4f);
        Color shadow = ColorBrightness(baseColor, -0.4f);

        // --- Outer Bevel ---
        // Top and Left (Shadow)
        DrawRectangle(rect.x, rect.y, rect.width, thickness, shadow);
        DrawRectangle(rect.x, rect.y, thickness, rect.height, shadow);
        // Bottom and Right (Light)
        DrawRectangle(rect.x, rect.y + rect.height - thickness, rect.width, thickness, light);
        DrawRectangle(rect.x + rect.width - thickness, rect.y, thickness, rect.height, light);

        // --- Inner Bevel ---
        float innerX = rect.x + thickness;
        float innerY = rect.y + thickness;
        float innerW = rect.width - (thickness * 2);
        float innerH = rect.height - (thickness * 2);

        // Top and Left (Light)
        DrawRectangle(innerX, innerY, innerW, thickness, light);
        DrawRectangle(innerX, innerY, thickness, innerH, light);
        // Bottom and Right (Shadow)
        DrawRectangle(innerX, innerY + innerH - thickness, innerW, thickness, shadow);
        DrawRectangle(innerX + innerW - thickness, innerY, thickness, innerH, shadow);
    }
}


