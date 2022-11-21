#include "error.h"

namespace error {
std::string Error::description() { return ""; }

std::optional<error::Error> Error::cause() { return std::nullopt; }
}