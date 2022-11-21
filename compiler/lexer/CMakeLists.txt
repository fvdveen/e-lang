add_library(lexer)

target_sources(lexer
	PRIVATE
		lexer.cpp
		token.cpp
	PUBLIC
		lexer.h
		token.h
)

target_include_directories(lexer PUBLIC "${CMAKE_SOURCE_DIR}/compiler")

target_link_libraries(lexer PUBLIC span error)