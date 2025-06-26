project(Meiro)

add_library(Meiro STATIC
    src/Meiro/Core/Application.cpp
    src/Meiro/Core/Log.cpp
    src/Platform/Windows/GlfwWindow.cpp
)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(Meiro PUBLIC
        MEIRO_LOGGING_ENABLED
        MEIRO_ASSERTS_ENABLED
    )
endif()

target_include_directories(Meiro PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

cmake_policy(SET CMP0072 NEW)
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(spdlog REQUIRED)


target_link_libraries(Meiro PRIVATE
    glfw
    spdlog::spdlog
    OpenGL::GL
)
