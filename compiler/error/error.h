#pragma once

#include <string>
#include <optional>

namespace error {

class Error {
public:
	virtual std::string description();
	virtual std::optional<Error> cause();
};

}