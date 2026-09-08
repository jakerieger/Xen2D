//
// Created by Jake Rieger on 9/8/2026.
//

#pragma once

#include <PAK/AssetMount.hpp>
#include <PAK/AssetRegistry.hpp>

namespace Xen {
    class Game {
    public:
        explicit Game(const PAK::AssetMountConfig& MountConfig);

        int Run() {
            return 0;
        }

    private:
        std::unique_ptr<PAK::AssetRegistry> _AssetRegistry;
    };
}  // namespace Xen
