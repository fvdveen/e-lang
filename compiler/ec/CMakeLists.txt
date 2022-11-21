add_executable (ec "ec.cpp" "ec.h")

target_link_libraries(ec PRIVATE span lexer format)