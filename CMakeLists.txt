cmake_minimum_required(VERSION 3.20) # Изменена версия CMake
project(Coursework)

set(CMAKE_CXX_STANDARD 20)

find_package(CURL REQUIRED)
find_package(nlohmann_json REQUIRED) # Или используйте include_directories() и target_link_libraries() с путями, если нужно

add_executable(Coursework main.cpp createBase.cpp) # Убран заголовочный файл

target_link_libraries(Coursework nlohmann_json::nlohmann_json)
target_link_libraries(Coursework CURL::libcurl)