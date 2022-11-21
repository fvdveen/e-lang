#include "io.h"

namespace error::io {

Error::Error(ErrorKind kind, int code) 
    : kind(kind)
    , code(code)
{
}

Error Error::from_errno(int error)
{
    ErrorKind kind;

    switch (error) {
    case ENOENT:
        kind = ErrorKind::NotFound;
        break;
    case ENOMEM:
        kind = ErrorKind::OutOfMemory;
        break;
    case EACCES:
        kind = ErrorKind::PermissionDenied;
        break;
    default:
        kind = ErrorKind::Other;
        break;
    }

    return Error(kind, error);
}

std::string error_kind_description(ErrorKind kind)
{
    switch (kind) {
    case error::io::ErrorKind::NotFound:
        return "entity not found";
    case error::io::ErrorKind::PermissionDenied:
        return "permission denied";
    case error::io::ErrorKind::OutOfMemory:
        return "out of memory";
    case error::io::ErrorKind::Other:
        return "other error";
    default:
        return "unknown error kind";
    }
}

std::string Error::description() {
    return error_kind_description(kind); }

std::optional<error::Error> Error::cause() {
	return std::nullopt;
}

}