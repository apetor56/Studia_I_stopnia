#include "GraphException.hpp"

const char *GraphException::what() const noexcept {
    std::stringstream ss;
    ss << "[FILE]: " << location.file_name() << '\n'
    << "[FUNC]: " << location.function_name() << '\n'
    << "[LINE]: " << location.line() << '\n'
    << errorMsg << ": [" << index1 << ']';
    if(index2 != -1) {
        ss << ", [" << index2 << ']';
    }
    whatBuffer = ss.str();
    return whatBuffer.c_str();
}

