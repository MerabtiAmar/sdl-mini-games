add_executable(serpent main.cpp)
target_include_directories(serpent PRIVATE ${SDL_PARENT_INCLUDE} ${SDL_INCLUDE_DIR})
target_link_libraries(serpent PRIVATE ${SDL_LIBRARY} ${SDL_IMAGE_LIBRARIES} ${SDL_TTF_LIBRARIES})
