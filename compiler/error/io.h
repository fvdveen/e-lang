#pragma once

#include <expected>
#include <filesystem>

#include "error.h"

namespace error::io {
enum class ErrorKind {
	NotFound,
	PermissionDenied,
	OutOfMemory,
	Other,
};

class Error: public error::Error {
private:
    ErrorKind kind;
    int code;

    Error(ErrorKind kind, int code);

public:
    static Error from_errno(int error);

    std::string description();
	std::optional<error::Error> cause();
};

template<class T>
using Result = std::expected<T, Error>;
}