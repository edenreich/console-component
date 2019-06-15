#ifndef COLORS_H
#define COLORS_H


#define COLOR_RESET     "\u001b[0m"

#define COLOR_CRITICAL  "\u001b[41m"
#define COLOR_YELLOW    "\u001b[33m"
#define COLOR_GREEN     "\u001b[32m"

namespace Console {
    namespace Types {

        enum class Colors {
            WHITE,
            RED,
            YELLOW,
            GREEN
        };

    }
}


#endif // COLORS_H
