#ifndef COLORS_H
#define COLORS_H

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#include <windows.h>

#define COLOR_RESET 0x0015

#define COLOR_RED 0x0047
#define COLOR_YELLOW 0x0006
#define COLOR_GREEN 0x0002
#else
#define COLOR_RESET "\u001b[0m"

#define COLOR_RED "\u001b[41m"
#define COLOR_YELLOW "\u001b[33m"
#define COLOR_GREEN "\u001b[32m"
#endif

namespace Console
{
    namespace Types
    {
        enum class Colors
        {
            NORMAL,
            RED,
            YELLOW,
            GREEN
        };
    }
}

#endif // COLORS_H
