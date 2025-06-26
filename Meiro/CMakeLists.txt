project(Meiro)

add_library(Meiro STATIC
    src/Meiro/Core/Application.cpp
    src/Meiro/Core/Log.cpp
)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(Meiro PUBLIC
        MEIRO_LOGGING_ENABLED
    )
endif()

target_include_directories(Meiro PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

find_package(spdlog REQUIRED)

target_link_libraries(Meiro PRIVATE
    spdlog::spdlog
)
