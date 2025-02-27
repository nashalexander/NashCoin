find_package(OpenSSL REQUIRED)

add_executable(BlockTest
    BlockTest.cpp
    BlockChain.cpp
    Block.cpp
)

target_link_libraries(BlockTest
    PRIVATE
        OpenSSL::Crypto
)

# turn on -g flag
set(CMAKE_BUILD_TYPE Debug)

add_custom_command(TARGET BlockTest POST_BUILD
    COMMAND ./BlockTest)