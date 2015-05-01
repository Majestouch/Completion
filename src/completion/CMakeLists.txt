# CMAKE_MINIMUM_REQUIRED(VERSION 2.9)
# PROJECT(completion)

ADD_EXECUTABLE(main main.cc ast_analyser.cc script_generator.cc script_manager.cc)

TARGET_LINK_LIBRARIES(main clidoc_ast_build)
