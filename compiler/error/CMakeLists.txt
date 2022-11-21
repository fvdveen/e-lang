add_library(error)

target_sources(error
	PRIVATE
		error.cpp
		io.cpp
	PUBLIC
		error.h
		io.h
 "io.h" "io.cpp")

target_include_directories(error PUBLIC "${CMAKE_SOURCE_DIR}/compiler")
