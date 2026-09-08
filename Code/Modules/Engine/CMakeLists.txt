project(Xen2D)

add_library(XenEngine STATIC
        Actor.cpp
        Actor.hpp
        Component.cpp
        Component.hpp
        EngineCommon.hpp
        Game.cpp
        Game.hpp
        Scene.cpp
        Scene.hpp
        Window.cpp
        Window.hpp
)

target_link_libraries(XenEngine PRIVATE XenPAK)
target_include_directories(XenEngine PRIVATE ${MODULES_ROOT}/XenPAK/Code)
