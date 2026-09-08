project(Xen2D)

add_library(XenEngine STATIC
        # Vendor
        ${VENDOR_ROOT}/nlohmann/json.hpp
        # Engine
        Actor.cpp
        Actor.hpp
        ActorHandle.hpp
        Component.hpp
        ComponentRegistry.cpp
        ComponentRegistry.hpp
        EngineCommon.hpp
        Game.cpp
        Game.hpp
        Reflection.hpp
        Scene.cpp
        Scene.hpp
        SceneSerializer.cpp
        SceneSerializer.hpp
        SpriteComponent.cpp
        SpriteComponent.hpp
        Transform.hpp
        Window.cpp
        Window.hpp
)

target_link_libraries(XenEngine PUBLIC XenPAK glm::glm-header-only glfw)
target_include_directories(XenEngine PRIVATE ${MODULES_ROOT}/XenPAK/Code ${VENDOR_ROOT})