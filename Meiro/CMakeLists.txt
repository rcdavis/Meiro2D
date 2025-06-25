project(Meiro)

add_library(Meiro STATIC
    src/Meiro/Core/Application.cpp
)

target_include_directories(Meiro PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
