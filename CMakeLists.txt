cmake_minimum_required(VERSION 3.10)
project(AmbientWiFiPro)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenSSL REQUIRED)
find_package(CURL REQUIRED)

add_executable(app
    src/main.cpp

    src/core/Config.cpp
    src/core/Logger.cpp

    src/net/HttpServer.cpp
    src/net/Router.cpp
    src/net/ThreadPool.cpp

    src/security/TLS.cpp
    src/security/Jwt.cpp

    src/services/AuthService.cpp
    src/services/CaptiveService.cpp
    src/services/StripeService.cpp

    src/api/AuthController.cpp
    src/api/CaptiveController.cpp

    src/edge/Gateway.cpp
)

target_link_libraries(app OpenSSL::SSL OpenSSL::Crypto CURL::libcurl pthread)
