//
// Created by Jake Rieger on 9/8/2026.
//

#include <Engine/Game.hpp>
#include <PAK/AssetMount.hpp>

int main(int argc, char* argv[]) {
    Xen::PAK::AssetMountConfig MountConfig;

#ifdef NDEBUG
    MountConfig.PakFiles.push_back(SANDBOX_PAK_FILENAME);
#else
    MountConfig.LooseDirs.push_back(SANDBOX_CONTENT_DIR);
#endif

    Xen::Game Sandbox(MountConfig);

    return Sandbox.Run();
}