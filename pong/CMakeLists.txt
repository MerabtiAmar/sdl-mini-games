add_executable(pong main.cpp)
target_include_directories(pong PRIVATE ${SDL_PARENT_INCLUDE} ${SDL_INCLUDE_DIR})
target_link_libraries(pong PRIVATE ${SDL_LIBRARY} ${SDL_IMAGE_LIBRARIES} ${SDL_TTF_LIBRARIES})
