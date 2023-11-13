//
// Created by Reyes on 2023/11/13.
//

#ifndef GM_AREATOOLARGEEXCEPTION_H
#define GM_AREATOOLARGEEXCEPTION_H

#include <exception>

namespace gm {

    class AreaTooLargeException : public std::exception {
    private:
        static constexpr const char* message = "The area of the graph is too large.";
    public:
        AreaTooLargeException() = default;
        ~AreaTooLargeException() override = default;

        const char* what() const noexcept override {
            return message;
        }
    };

} // gm

#endif //GM_AREATOOLARGEEXCEPTION_H
