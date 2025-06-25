project(Sandbox)

add_executable(Sandbox
    src/SandboxApp.cpp
)

target_include_directories(Sandbox PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(Sandbox PRIVATE
    Meiro
)
