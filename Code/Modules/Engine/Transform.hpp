//
// Created by Jake Rieger on 9/8/2026.
//

#pragma once

#include "EngineCommon.hpp"
#include <glm/glm.hpp>

namespace Xen {
    struct Transform {
        glm::vec2 Position {0.0f, 0.0f};
        f32 Rotation {0.0f};
        glm::vec2 Scale {1.0f, 1.0f};

        /// @brief Composes this transform with a parent's, producing a world transform. Used when actors are attached
        /// to one another.
        Transform ComposedWith(const Transform& Parent) const {
            const f32 C = std::cos(Parent.Rotation);
            const f32 S = std::sin(Parent.Rotation);

            const glm::vec2 Scaled {Position.x * Parent.Scale.x, Position.y * Parent.Scale.y};
            const glm::vec2 Rotated {Scaled.x * C - Scaled.y * S, Scaled.x * S + Scaled.y * C};

            return Transform {
              .Position = Parent.Position + Rotated,
              .Rotation = Parent.Rotation + Rotation,
              .Scale    = Parent.Scale * Scale,
            };
        }

        void Translate(const f32 X, const f32 Y) {
            Position.x += X;
            Position.y += Y;
        }

        void Rotate(const f32 Amount) {
            Rotation += Amount;
        }
    };
}  // namespace Xen