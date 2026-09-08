//
// Created by Jake Rieger on 9/8/2026.
//

#pragma once

#include "EngineCommon.hpp"
#include "Component.hpp"
#include "ComponentRegistry.hpp"

namespace Xen {
    XEN_DEFINE_COMPONENT(SpriteComponent)

    class SpriteComponent final : public IComponent {
    public:
        COMPONENT_TYPE(SpriteComponent)
        SpriteComponent() {}
        explicit SpriteComponent(const AssetID SpriteAsset) : _SpriteAsset(SpriteAsset) {
            if (!_SpriteAsset.IsValid()) { throw EngineException(Engine_MakeExceptionStr("Invalid sprite asset ID")); }
        }

        void Reflect(IReflector& R) override { R.Property("SpriteAsset", _SpriteAsset); }

        void Tick(const f32 DeltaTime) override {
            // TODO: Render sprite to screen
        }

        AssetID GetSpriteAsset() const { return _SpriteAsset; }

    private:
        AssetID _SpriteAsset {};
    };
}  // namespace Xen
