add_executable(tic-tac-toe main.cpp)
target_include_directories(tic-tac-toe PRIVATE ${SDL_PARENT_INCLUDE} ${SDL_INCLUDE_DIR})
target_link_libraries(tic-tac-toe PRIVATE ${SDL_LIBRARY} ${SDL_IMAGE_LIBRARIES} ${SDL_TTF_LIBRARIES})
