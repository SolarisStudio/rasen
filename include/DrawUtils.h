#pragma once

#include <raylib.h>
#include <vector>
#include <cmath>

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

// Draws an embossed custom polygon from a set of points
    inline void DrawPolyOutset(const std::vector<Vector2>& points, float thickness, Color baseColor) {
        Color light = ColorBrightness(baseColor, 0.4f);
        Color shadow = ColorBrightness(baseColor, -0.4f);

        // 1. Draw the filled base shape
        DrawTriangleFan(points.data(), (int)points.size(), baseColor);

        // 2. Draw the highlight and shadow edges
        for (size_t i = 0; i < points.size(); i++) {
            Vector2 p1 = points[i];
            Vector2 p2 = points[(i + 1) % points.size()]; // Wrap around to the first point

            // Calculate the normal/direction of the edge
            // Light source assumed at Top-Left (-1, -1)
            float dx = p2.x - p1.x;
            float dy = p2.y - p1.y;

            // Simple dot product logic to determine if the edge faces the light
            // If the edge's normal points generally "up" or "left", it's highlighted
            Vector2 normal = { -dy, dx };
            // We want edges facing towards (-1, -1)
            float dot = (normal.x * -1.0f) + (normal.y * -1.0f);

            if (dot > 0) {
                DrawLineEx(p1, p2, thickness, light);
            } else {
                DrawLineEx(p1, p2, thickness, shadow);
            }
        }
    }

    // Draws a sunken custom polygon from a set of points
    inline void DrawPolyInset(const std::vector<Vector2>& points, float thickness, Color baseColor) {
        Color light = ColorBrightness(baseColor, 0.4f);
        Color shadow = ColorBrightness(baseColor, -0.4f);

        DrawTriangleFan(points.data(), (int)points.size(), baseColor);

        for (size_t i = 0; i < points.size(); i++) {
            Vector2 p1 = points[i];
            Vector2 p2 = points[(i + 1) % points.size()];

            float dx = p2.x - p1.x;
            float dy = p2.y - p1.y;
            Vector2 normal = { -dy, dx };
            float dot = (normal.x * -1.0f) + (normal.y * -1.0f);

            // For Inset, we swap the light and shadow
            if (dot > 0) {
                DrawLineEx(p1, p2, thickness, shadow);
            } else {
                DrawLineEx(p1, p2, thickness, light);
            }
        }
    }

    inline float GetEdgeLightFactor(Vector2 p1, Vector2 p2) {
        float dx = p2.x - p1.x;
        float dy = p2.y - p1.y;
        Vector2 normal = { -dy, dx };
        // Light source at Top-Left (-1, -1)
        return (normal.x * -1.0f) + (normal.y * -1.0f);
    }

    // --- Helper for Triangle Edge Lighting ---
    inline void DrawTriangleBevel(Vector2 v1, Vector2 v2, Vector2 v3, float thickness, bool outset, Color baseColor) {
        Color light = ColorBrightness(baseColor, 0.4f);
        Color shadow = ColorBrightness(baseColor, -0.4f);

        Vector2 edges[3][2] = { {v1, v2}, {v2, v3}, {v3, v1} };

        for (int i = 0; i < 3; i++) {
            Vector2 p1 = edges[i][0];
            Vector2 p2 = edges[i][1];

            // Calculate if the edge faces the Top-Left light source
            float factor = GetEdgeLightFactor(p1, p2);

            Color edgeColor;
            if (outset) {
                edgeColor = (factor > 0) ? light : shadow;
            } else {
                edgeColor = (factor > 0) ? shadow : light;
            }

            DrawLineEx(p1, p2, thickness, edgeColor);
        }
    }

// Helper to draw a triangle and ensure it actually fills regardless of vertex order
    inline void SafeDrawTriangleFilled(Vector2 v1, Vector2 v2, Vector2 v3, Color color) {
        // Raylib's DrawTriangle requires Counter-Clockwise order.
        // We calculate the cross product to check orientation.
        float check = (v2.x - v1.x) * (v3.y - v1.y) - (v2.y - v1.y) * (v3.x - v1.x);
        if (check <= 0) {
            DrawTriangle(v1, v2, v3, color);
        } else {
            // Flip two vertices to fix the order to CCW
            DrawTriangle(v1, v3, v2, color);
        }
    }

    // --- Embossed Filled Triangles ---

    inline void DrawTriangleFilledOutset(Vector2 v1, Vector2 v2, Vector2 v3, float thickness, Color baseColor) {
        // 1. Draw the Fill first
        SafeDrawTriangleFilled(v1, v2, v3, baseColor);

        // 2. Draw the Bevel Edges
        DrawTriangleBevel(v1, v2, v3, thickness, true, baseColor);
    }

    inline void DrawTriangleFilledInset(Vector2 v1, Vector2 v2, Vector2 v3, float thickness, Color baseColor) {
        // 1. Draw the Fill (slightly darker for the "floor")
        SafeDrawTriangleFilled(v1, v2, v3, ColorBrightness(baseColor, -0.15f));

        // 2. Draw the Bevel Edges (inverted for inset)
        DrawTriangleBevel(v1, v2, v3, thickness, false, baseColor);
    }

    // --- Unfilled (Hollow) Embossed Triangles ---

    inline void DrawTriangleLinesOutset(Vector2 v1, Vector2 v2, Vector2 v3, float thickness, Color baseColor) {
        // Outer Rim
        DrawTriangleBevel(v1, v2, v3, thickness, true, baseColor);

        // Calculate Centroid to find "inward" direction
        Vector2 center = { (v1.x + v2.x + v3.x) / 3.0f, (v1.y + v2.y + v3.y) / 3.0f };
        auto shrink = [&](Vector2 v) {
            Vector2 dir = { v.x - center.x, v.y - center.y };
            float mag = sqrtf(dir.x * dir.x + dir.y * dir.y);
            // Move vertex slightly toward center for the inner line
            return Vector2{ v.x - (dir.x / mag) * thickness, v.y - (dir.y / mag) * thickness };
        };

        // Inner Rim (Opposite lighting creates the "ridge" effect)
        DrawTriangleBevel(shrink(v1), shrink(v2), shrink(v3), thickness, false, baseColor);
    }


}


