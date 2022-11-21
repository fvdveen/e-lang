add_library(span)

target_sources(span
	PRIVATE
		span.cpp
		source_map.cpp
	PUBLIC
		span.h
		source_map.h
)

target_include_directories(span PUBLIC "${CMAKE_SOURCE_DIR}/compiler")

target_link_libraries(span PUBLIC error)