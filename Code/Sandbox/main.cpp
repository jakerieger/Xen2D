//
// Created by Jake Rieger on 9/8/2026.
//

#include "BallComponent.hpp"
#include "Engine/SpriteComponent.hpp"

#include <iostream>
#include <Engine/Game.hpp>
#include <Engine/Scene.hpp>
#include <Engine/SceneSerializer.hpp>
#include <PAK/AssetMount.hpp>

using namespace Xen;

int main(int argc, char* argv[]) {
    PAK::AssetMountConfig MountConfig;

#ifdef NDEBUG
    MountConfig.PakFiles.push_back(SANDBOX_PAK_FILENAME);
#else
    MountConfig.LooseDirs.push_back(SANDBOX_CONTENT_DIR);
    Xen::PAK::AppendContentDirsFromArgs(MountConfig, argc, argv);
#endif

    Scene MainScene("TestScene");
    ActorHandle BallHandle = MainScene.Spawn("Ball");
    Actor* Ball            = MainScene.Get(BallHandle);

    constexpr AssetID BallSprite = ASSET("sprites/ball.png");
    Ball->AddComponent<SpriteComponent>(BallSprite);
    Ball->AddComponent<BallComponent>();

    SceneSerializer::SaveToFile(MainScene, "test_scene.json");

    Scene Loaded;
    SceneSerializer::LoadFromFile(Loaded, "test_scene.json");

    Actor* BallActor = Loaded.Get(BallHandle);
    if (!BallActor) return EXIT_FAILURE;

    SpriteComponent* SpriteComp = BallActor->GetComponent<SpriteComponent>();
    if (!SpriteComp) return EXIT_FAILURE;

    AssetID SpriteAsset = SpriteComp->GetSpriteAsset();
    if (SpriteAsset != BallSprite) return EXIT_FAILURE;

    return Game(MountConfig).Run();
}