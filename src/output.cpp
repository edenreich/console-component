#include "include/console/output.h"
#include "include/console/progress_bar.h"

#include <iostream>
#include <cstdarg>

using namespace Console;

/**
 * Initialize the application interface.
 *
 * @param Interfaces::ApplicationInterface * app
 */
Output::Output(Interfaces::ApplicationInterface* app) { m_app = app; }

/**
 * Print the help message.
 *
 * @return void
 */
void Output::printHelp()
{
    printApplicationTitle();

    printApplicationUsage();

    printApplicationOptions();

    printAvailableCommands();
}

/**
 * Print the command help message.
 *
 * @param Interfaces::CommandInterface * command
 * @return void
 */
void Output::printCommandHelp(Interfaces::CommandInterface* command)
{
    // Usage
    writeLine(Types::Colors::YELLOW, "Usage:");
    writeLine("  %s [options]\n", command->getName().c_str());

    // Options
    writeLine(Types::Colors::YELLOW, "Options:");
    writeLine("  -h, --help\tDisplay this help message");
    for (auto& option : command->getOptions())
    {
        writeLine("  %s, %s\t%s", option.first.c_str(), option.second.first.c_str(), option.second.second.c_str());
    }
}

/**
 * Write a string to the console.
 *
 * @param const std::string message
 * @param ...
 * @return void
 */
void Output::write(const std::string message, ...)
{
    va_list args;

    va_start(args, message);
    vprintf(message.c_str(), args);
    va_end(args);
}

/**
 * Write a colored string to the console.
 *
 * @param Types::Colors color
 * @param const std::string message
 * @param ... any
 * @return void
 */
void Output::write(Types::Colors color, const std::string message, ...)
{
    va_list args;

    va_start(args, message);
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    FlushConsoleInputBuffer(hConsole);

    switch (color)
    {
    case Types::Colors::NORMAL:
        vprintf(message.c_str(), args);
        break;
    case Types::Colors::RED:
        SetConsoleTextAttribute(hConsole, COLOR_RED);
        vprintf(message.c_str(), args);
        break;
    case Types::Colors::YELLOW:
        SetConsoleTextAttribute(hConsole, COLOR_YELLOW);
        vprintf(message.c_str(), args);
        break;
    case Types::Colors::GREEN:
        SetConsoleTextAttribute(hConsole, COLOR_GREEN);
        vprintf(message.c_str(), args);
        break;
    default:
        vprintf(message.c_str(), args);
        break;
    }

    SetConsoleTextAttribute(hConsole, 15);
#else
    switch (color)
    {
    case Types::Colors::NORMAL:
        vprintf(message.c_str(), args);
        break;
    case Types::Colors::RED:
        printf(COLOR_RED);
        vprintf(message.c_str(), args);
        printf(COLOR_RESET);
        break;
    case Types::Colors::YELLOW:
        printf(COLOR_YELLOW);
        vprintf(message.c_str(), args);
        printf(COLOR_RESET);
        break;
    case Types::Colors::GREEN:
        printf(COLOR_GREEN);
        vprintf(message.c_str(), args);
        printf(COLOR_RESET);
        break;
    default:
        vprintf(message.c_str(), args);
        break;
    }
#endif
    va_end(args);
}

/**
 * Write a line to the console.
 *
 * @param const std::string line
 * @param ... any
 * @return void
 */
void Output::writeLine(const std::string line, ...)
{
    va_list args;

    va_start(args, line);
    vprintf(line.c_str(), args);
    va_end(args);

    printf("\n");
}

/**
 * Write a colored line to the console.
 *
 * @param Types::Colors color
 * @param const std::string line
 * @param ... any
 * @return void
 */
void Output::writeLine(Types::Colors color, const std::string line, ...)
{
    va_list args;

    va_start(args, line);
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    FlushConsoleInputBuffer(hConsole);

    switch (color)
    {
    case Types::Colors::NORMAL:
        vprintf(line.c_str(), args);
        break;
    case Types::Colors::RED:
        SetConsoleTextAttribute(hConsole, COLOR_RED);
        vprintf(line.c_str(), args);
        break;
    case Types::Colors::YELLOW:
        SetConsoleTextAttribute(hConsole, COLOR_YELLOW);
        vprintf(line.c_str(), args);
        break;
    case Types::Colors::GREEN:
        SetConsoleTextAttribute(hConsole, COLOR_GREEN);
        vprintf(line.c_str(), args);
        break;
    default:
        vprintf(line.c_str(), args);
        break;
    }

    SetConsoleTextAttribute(hConsole, 15);
#else
    switch (color)
    {
    case Types::Colors::NORMAL:
        vprintf(line.c_str(), args);
        break;
    case Types::Colors::RED:
        printf(COLOR_RED);
        vprintf(line.c_str(), args);
        printf(COLOR_RESET);
        break;
    case Types::Colors::YELLOW:
        printf(COLOR_YELLOW);
        vprintf(line.c_str(), args);
        printf(COLOR_RESET);
        break;
    case Types::Colors::GREEN:
        printf(COLOR_GREEN);
        vprintf(line.c_str(), args);
        printf(COLOR_RESET);
        break;
    default:
        vprintf(line.c_str(), args);
        break;
    }
#endif
    va_end(args);

    printf("\n");
}

/**
 * Write an error to the console.
 *
 * @param const std::string line
 * @param ... any
 * @return void
 */
void Output::error(const std::string line, ...)
{
    va_list args;

    va_start(args, line);
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    FlushConsoleInputBuffer(hConsole);
    SetConsoleTextAttribute(hConsole, COLOR_RED);
    vprintf(line.c_str(), args);
    SetConsoleTextAttribute(hConsole, 15);
#else
    printf(COLOR_RED);
    vprintf(line.c_str(), args);
    printf(COLOR_RESET);
#endif
    va_end(args);

    printf("\n");
}

/**
 * Write an info to the console.
 *
 * @param const std::string line
 * @param ... any
 * @return void
 */
void Output::info(const std::string line, ...)
{
    va_list p_args;

    va_start(p_args, line);
    vprintf(line.c_str(), p_args);
    va_end(p_args);

    printf("\n");
}

/**
 * Write a warning to the console.
 *
 * @param const std::string line
 * @param ... any
 * @return void
 */
void Output::warning(const std::string line, ...)
{
    va_list args;

    va_start(args, line);
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    FlushConsoleInputBuffer(hConsole);
    SetConsoleTextAttribute(hConsole, COLOR_YELLOW);
    vprintf(line.c_str(), args);
    SetConsoleTextAttribute(hConsole, 15);
#else
    printf(COLOR_YELLOW);
    vprintf(line.c_str(), args);
    printf(COLOR_RESET);
#endif
    va_end(args);

    printf("\n");
}

/**
 * Create a progress bar instance.
 *
 * @param const unsigned int items
 * @return ProgressBar *
 */
ProgressBar* Output::createProgressBar(const unsigned int items) { return new ProgressBar(this, items); }

/**
 * Print the title of the application.
 *
 * @return void
 */
void Output::printApplicationTitle()
{
    writeLine(Types::Colors::GREEN, m_app->getApplicationName());
    writeLine(Types::Colors::YELLOW, "Version: %s", m_app->getApplicationVersion().c_str());
    writeLine(m_app->getApplicationDescription());
}

/**
 * Print the usage line of the application.
 *
 * @return void
 */
void Output::printApplicationUsage()
{
    writeLine(Types::Colors::YELLOW, "Usage:");
    writeLine("  %s", m_app->getApplicationUsage().c_str());
    write("\n\n");
}

/**
 * Print the global options of the application.
 *
 * @return void
 */
void Output::printApplicationOptions()
{
    writeLine(Types::Colors::YELLOW, "Options:");
    writeLine("  -h, --help\tDisplay this help message");
    for (auto& option : m_app->getAvailableGlobalOptions())
    {
        writeLine("  %s, %s\t%s", option.first.c_str(), option.second.first.c_str(), option.second.second.c_str());
    }
    write("\n");
}

/**
 * Print the available commands.
 *
 * @return void
 */
void Output::printAvailableCommands()
{
    writeLine(Types::Colors::YELLOW, "Available Commands:");
    for (auto& commandNamespace : m_app->getAvailableCommands())
    {
        write(Types::Colors::YELLOW, " %s\n", commandNamespace.first.c_str());
        for (auto& command : commandNamespace.second)
        {
            write(Types::Colors::GREEN, "  %s", command.second->getName().c_str());
            write("\t");
            writeLine(command.second->getDescription());
        }
    }
    write("\n");
}
