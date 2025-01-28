add_executable(BlockTest
    BlockTest.cpp
)

# turn on -g flag
set(CMAKE_BUILD_TYPE Debug)

add_custom_command(TARGET BlockTest POST_BUILD
    COMMAND ./BlockTest)