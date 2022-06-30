#ifndef GRAPHEXCEPTION_HPP
#define GRAPHEXCEPTION_HPP

#include <exception>
#include <sstream>
#include <source_location>

class GraphException : public std::exception {
public:
    GraphException(const char *_errorMsg, int _index1,  int _index2 = -1,
        const std::source_location _location = std::source_location::current())
        :
        errorMsg(_errorMsg),
        index1(_index1),
        index2(_index2),
        location(_location) {}

    const char *what() const noexcept;

private:
    const char *errorMsg;
    int index1;
    int index2;
    const std::source_location location;
    mutable std::string whatBuffer;
};

#endif // GRAPHEXCEPTION_HPP