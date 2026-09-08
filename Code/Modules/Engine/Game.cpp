//
// Created by Jake Rieger on 9/8/2026.
//

#include "Game.hpp"

namespace Xen {
    Game::Game(const PAK::AssetMountConfig& MountConfig) {
        try {
            _AssetRegistry = PAK::MountAssets(MountConfig);
        } catch (const std::exception& Ex) {
            std::fprintf(stderr, "%s\n", Ex.what());
            std::abort();
        }
    }
}  // namespace Xen