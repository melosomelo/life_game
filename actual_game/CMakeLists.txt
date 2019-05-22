cmake_minimum_required(VERSION 3.14)
project(life_game)


include_directories(
    ../image_handling/include
    actual_game/include
)


file(GLOB SOURCES "src/*.cpp"
        "../image_handling/src/*.cpp"
)

add_executable(game ${SOURCES})