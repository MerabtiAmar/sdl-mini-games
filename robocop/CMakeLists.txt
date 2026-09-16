add_executable(robocop main.cpp)
target_include_directories(robocop PRIVATE ${SDL_PARENT_INCLUDE} ${SDL_INCLUDE_DIR})
target_link_libraries(robocop PRIVATE ${SDL_LIBRARY} ${SDL_IMAGE_LIBRARIES} ${SDL_TTF_LIBRARIES})
