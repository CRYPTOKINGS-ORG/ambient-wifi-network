cmake_minimum_required(VERSION 3.10)
project(AmbientWiFi)

set(CMAKE_CXX_STANDARD 17)

add_executable(app
    src/main.cpp
    src/server/HttpServer.cpp
    src/auth/AuthService.cpp
    src/captive/CaptivePortal.cpp
    src/edge/Gateway.cpp
    src/utils/EnvLoader.cpp
    src/security/Jwt.cpp
)
