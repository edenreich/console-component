#include "include/console/output.h"
#include "include/console/progress_bar.h"

#include <iostream>
#include <format>

using namespace Console;

/**
 * Initialize the application interface.
 *
 * @param Interfaces::ApplicationInterface * app
 */
Output::Output(Interfaces::ApplicationInterface* app) noexcept { m_app = app; }

/**
 * Print the help message.
 *
 * @return void
 */
void Output::printHelp() noexcept
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
void Output::printCommandHelp(Interfaces::CommandInterface* command) noexcept
{
    // Usage
    writeLine(Types::Colors::YELLOW, "Usage:");
    writeLine(std::format("  {} [options]\n", command->getName()));

    // Options
    writeLine(Types::Colors::YELLOW, "Options:");
    writeLine("  -h, --help\tDisplay this help message");
    for (auto& [optKey, optVal] : command->getOptions())
    {
        writeLine(std::format("  {}, {}\t{}", optKey, optVal.first, optVal.second));
    }
}

/**
 * Write a string to the console.
 *
 * @param std::string_view message
 * @return void
 */
void Output::write(std::string_view message) noexcept
{
    std::cout << message;
}

/**
 * Write a colored string to the console.
 *
 * @param Types::Colors color
 * @param std::string_view message
 * @return void
 */
void Output::write(Types::Colors color, std::string_view message) noexcept
{
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    FlushConsoleInputBuffer(hConsole);

    switch (color)
    {
    case Types::Colors::NORMAL:
        std::cout << message;
        break;
    case Types::Colors::RED:
        SetConsoleTextAttribute(hConsole, COLOR_RED);
        std::cout << message;
        break;
    case Types::Colors::YELLOW:
        SetConsoleTextAttribute(hConsole, COLOR_YELLOW);
        std::cout << message;
        break;
    case Types::Colors::GREEN:
        SetConsoleTextAttribute(hConsole, COLOR_GREEN);
        std::cout << message;
        break;
    default:
        std::cout << message;
        break;
    }

    SetConsoleTextAttribute(hConsole, 15);
#else
    switch (color)
    {
    case Types::Colors::NORMAL:
        std::cout << message;
        break;
    case Types::Colors::RED:
        std::cout << COLOR_RED << message << COLOR_RESET;
        break;
    case Types::Colors::YELLOW:
        std::cout << COLOR_YELLOW << message << COLOR_RESET;
        break;
    case Types::Colors::GREEN:
        std::cout << COLOR_GREEN << message << COLOR_RESET;
        break;
    default:
        std::cout << message;
        break;
    }
#endif
}

/**
 * Write a line to the console.
 *
 * @param std::string_view line
 * @return void
 */
void Output::writeLine(std::string_view line) noexcept
{
    std::cout << line << '\n';
}

/**
 * Write a colored line to the console.
 *
 * @param Types::Colors color
 * @param std::string_view line
 * @return void
 */
void Output::writeLine(Types::Colors color, std::string_view line) noexcept
{
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    FlushConsoleInputBuffer(hConsole);

    switch (color)
    {
    case Types::Colors::NORMAL:
        std::cout << line << '\n';
        break;
    case Types::Colors::RED:
        SetConsoleTextAttribute(hConsole, COLOR_RED);
        std::cout << line << '\n';
        break;
    case Types::Colors::YELLOW:
        SetConsoleTextAttribute(hConsole, COLOR_YELLOW);
        std::cout << line << '\n';
        break;
    case Types::Colors::GREEN:
        SetConsoleTextAttribute(hConsole, COLOR_GREEN);
        std::cout << line << '\n';
        break;
    default:
        std::cout << line << '\n';
        break;
    }

    SetConsoleTextAttribute(hConsole, 15);
#else
    switch (color)
    {
    case Types::Colors::NORMAL:
        std::cout << line << '\n';
        break;
    case Types::Colors::RED:
        std::cout << COLOR_RED << line << COLOR_RESET << '\n';
        break;
    case Types::Colors::YELLOW:
        std::cout << COLOR_YELLOW << line << COLOR_RESET << '\n';
        break;
    case Types::Colors::GREEN:
        std::cout << COLOR_GREEN << line << COLOR_RESET << '\n';
        break;
    default:
        std::cout << line << '\n';
        break;
    }
#endif
}

/**
 * Write an error to the console.
 *
 * @param std::string_view line
 * @return void
 */
void Output::error(std::string_view line) noexcept
{
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    FlushConsoleInputBuffer(hConsole);
    SetConsoleTextAttribute(hConsole, COLOR_RED);
    std::cout << line << '\n';
    SetConsoleTextAttribute(hConsole, 15);
#else
    std::cout << COLOR_RED << line << COLOR_RESET << '\n';
#endif
}

/**
 * Write an info to the console.
 *
 * @param std::string_view line
 * @return void
 */
void Output::info(std::string_view line) noexcept
{
    std::cout << line << '\n';
}

/**
 * Write a warning to the console.
 *
 * @param std::string_view line
 * @return void
 */
void Output::warning(std::string_view line) noexcept
{
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    FlushConsoleInputBuffer(hConsole);
    SetConsoleTextAttribute(hConsole, COLOR_YELLOW);
    std::cout << line << '\n';
    SetConsoleTextAttribute(hConsole, 15);
#else
    std::cout << COLOR_YELLOW << line << COLOR_RESET << '\n';
#endif
}

/**
 * Create a progress bar instance.
 *
 * @param const unsigned int items
 * @return ProgressBar *
 */
ProgressBar* Output::createProgressBar(const unsigned int items) noexcept { return new ProgressBar(this, items); }

/**
 * Print the title of the application.
 *
 * @return void
 */
void Output::printApplicationTitle()
{
    writeLine(Types::Colors::GREEN, m_app->getApplicationName());
    writeLine(Types::Colors::YELLOW, std::format("Version: {}", m_app->getApplicationVersion()));
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
    writeLine(std::format("  {}", m_app->getApplicationUsage()));
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
    for (auto& [optKey, optVal] : m_app->getAvailableGlobalOptions())
    {
        writeLine(std::format("  {}, {}\t{}", optKey, optVal.first, optVal.second));
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
    for (auto& [ns, commands] : m_app->getAvailableCommands())
    {
        write(Types::Colors::YELLOW, std::format(" {}\n", ns));
        for (auto& [cmdName, cmd] : commands)
        {
            write(Types::Colors::GREEN, std::format("  {}", cmd->getName()));
            write("\t");
            writeLine(cmd->getDescription());
        }
    }
    write("\n");
}
