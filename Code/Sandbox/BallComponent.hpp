//
// Created by Jake Rieger on 9/8/2026.
//

#pragma once

#include <Engine/Actor.hpp>
#include <Engine/Component.hpp>
#include <Engine/ComponentRegistry.hpp>
#include <Engine/EngineCommon.hpp>
#include <random>

XEN_DEFINE_COMPONENT(BallComponent)

class BallComponent final : public Xen::IComponent {
public:
    COMPONENT_TYPE(BallComponent)
    BallComponent();

    void Reflect(Xen::IReflector& R) override;
    void BeginPlay() override;
    void Tick(Xen::f32 DeltaTime) override;
    void EndPlay() override;

private:
    glm::vec2 _Velocity {0.0f, 0.0f};
};