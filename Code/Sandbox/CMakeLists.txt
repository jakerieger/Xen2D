project(Xen2D)

add_executable(Sandbox
        main.cpp
        BallComponent.cpp
        BallComponent.hpp
        OpponentComponent.cpp
        OpponentComponent.hpp
        PlayerComponent.cpp
        PlayerComponent.hpp
)

set(PAK_FILENAME "Data1.xpak")
set(CONTENT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Content")

add_compile_definitions(
        SANDBOX_PAK_FILENAME=\"${PAK_FILENAME}\"
        SANDBOX_CONTENT_DIR=\"${CONTENT_DIR}\"
)

target_include_directories(Sandbox PRIVATE ${MODULES_ROOT} ${MODULES_ROOT}/XenPAK/Code ${VENDOR_ROOT})
target_link_libraries(Sandbox PRIVATE XenEngine)

add_custom_command(
        TARGET Sandbox
        POST_BUILD
        COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/XenPAK-CLI "${CONTENT_DIR}" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PAK_FILENAME}"
        COMMENT "Pak sandbox content"
)