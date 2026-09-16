add_executable(mini-golf main.cpp)
target_include_directories(mini-golf PRIVATE ${SDL_PARENT_INCLUDE} ${SDL_INCLUDE_DIR})
target_link_libraries(mini-golf PRIVATE ${SDL_LIBRARY} ${SDL_IMAGE_LIBRARIES} ${SDL_TTF_LIBRARIES})
