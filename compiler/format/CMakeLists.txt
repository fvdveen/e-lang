add_library(format)

target_sources(format
	PRIVATE
		format.cpp
	PUBLIC
		format.h
)

target_include_directories(format PUBLIC "${CMAKE_SOURCE_DIR}/compiler")

target_link_libraries(format PUBLIC span lexer)