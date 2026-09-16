cmake_minimum_required(VERSION 3.16)
project(sdl_mini_games CXX)

set(CMAKE_CXX_STANDARD 11)

# SDL 1.2, SDL_image et SDL_ttf (modules Find fournis avec CMake)
find_package(SDL REQUIRED)
find_package(SDL_image REQUIRED)
find_package(SDL_ttf REQUIRED)

# Le code inclut <SDL/SDL.h> : on ajoute aussi le dossier parent des en-têtes SDL
get_filename_component(SDL_PARENT_INCLUDE "${SDL_INCLUDE_DIR}" DIRECTORY)

add_subdirectory(robocop)
add_subdirectory(serpent)
add_subdirectory(mini-golf)
add_subdirectory(tic-tac-toe)
add_subdirectory(pong)
