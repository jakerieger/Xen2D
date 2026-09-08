//
// Created by Jake Rieger on 9/8/2026.
//

#include "BallComponent.hpp"

BallComponent::BallComponent() {}

void BallComponent::Reflect(Xen::IReflector& R) {
    R.Property("Velocity", _Velocity);
}

void BallComponent::BeginPlay() {
    // Center ball on screen and give it an initial random velocity
    GetOwner()->SetPosition({0.0f, 0.0f});

    std::random_device Rd;
    std::mt19937 Gen(Rd());

    constexpr Xen::f32 MinVelocity = -1.0f;
    constexpr Xen::f32 MaxVelocity = 1.0f;
    std::uniform_real_distribution Dst(MinVelocity, MaxVelocity);

    _Velocity = {
      Dst(Gen),
      Dst(Gen),
    };
}

void BallComponent::Tick(const Xen::f32 DeltaTime) {
    // Update position based on current velocity
    const auto CurrentPosition = GetOwner()->GetPosition();
    GetOwner()->SetPosition({
      CurrentPosition.x + _Velocity.x * DeltaTime,
      CurrentPosition.y + _Velocity.y * DeltaTime,
    });
}

void BallComponent::EndPlay() {}