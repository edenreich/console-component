#include "console/output.h"
#include "console/progress_bar.h"

#include <iostream>

using namespace Console;


/**
 * Initialize the application interface.
 * 
 * @param Interfaces::ApplicationInterface * app
 */
Output::Output(Interfaces::ApplicationInterface * app)
{
    m_app = app;
}

/**
 * Print the help message.
 *
 * @return void
 */
void Output::printHelp()
{
    writeLine(m_app->getApplicationName(), Types::Colors::GREEN);
    write("Version: ");
    writeLine(m_app->getApplicationVersion(), Types::Colors::YELLOW);
    writeLine(m_app->getApplicationDescription());
    writeLineBreak();

    // Usage
    writeLine("Usage:", Types::Colors::YELLOW);
    write("  ");
    writeLine(m_app->getApplicationUsage());
    writeLineBreak();
    
    // Options
    writeLine("Options:", Types::Colors::YELLOW);
    write("  ");
    writeLine("-h, --help\tDisplay this help message");
    for (auto & option : m_app->getAvailableGlobalOptions())
    {
        write("  ");
        write(option.first);
        write(", ");
        write(option.second.first);
        write("\t");
        write(option.second.second);
        writeLineBreak();
    }

    writeLineBreak();

    // Available Commands
    writeLine("Available Commands:", Types::Colors::YELLOW);
    for (auto & command : m_app->getAvailableCommands())
    {
        write("  ");
        write(command.second->getName(), Types::Colors::GREEN);
        write("\t");
        write(command.second->getDescription());
        writeLineBreak();
    }
}

/**
 * Print the command help message.
 *
 * @param Interfaces::CommandInterface * command
 * @return void
 */
void Output::printCommandHelp(Interfaces::CommandInterface * command)
{
    // Usage
    writeLine("Usage:", Types::Colors::YELLOW);
    write("  ");
    write(command->getName());
    write(" [options]");
    writeLineBreak();

    // Options
    writeLine("Options:", Types::Colors::YELLOW);
    write("  ");
    writeLine("-h, --help\tDisplay this help message");
    for (auto & option : command->getOptions())
    {
        write("  ");
        write(option.first);
        write(", ");
        write(option.second.first);
        write("\t");
        write(option.second.second);
        writeLineBreak();
    }
}

/**
 * Write a string to the console.
 *
 * @param const std::string & line
 * @param Types::Colors color
 * @return void
 */
void Output::write(const std::string & line, Types::Colors color)
{
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
        HANDLE hConsole;
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        FlushConsoleInputBuffer(hConsole);

        switch (color)
        {
        case Types::Colors::NORMAL:
            printf("%s", line.c_str());
            break;
        case Types::Colors::RED:
            SetConsoleTextAttribute(hConsole, COLOR_CRITICAL);
            printf("%s", line.c_str());
            break;
        case Types::Colors::YELLOW:
            SetConsoleTextAttribute(hConsole, COLOR_YELLOW);
            printf("%s", line.c_str());
            break;
        case Types::Colors::GREEN:
            SetConsoleTextAttribute(hConsole, COLOR_GREEN);
            printf("%s", line.c_str());
            break;
        default:
            printf("%s", line.c_str());
            break;
        }

        SetConsoleTextAttribute(hConsole, 15);
    #else
        switch (color)
        {
        case Types::Colors::NORMAL:
            printf("%s", line.c_str());
            break;
        case Types::Colors::RED:
            printf("%s%s%s", COLOR_CRITICAL, line.c_str(), COLOR_RESET);
            break;
        case Types::Colors::YELLOW:
            printf("%s%s%s", COLOR_YELLOW, line.c_str(), COLOR_RESET);
            break;
        case Types::Colors::GREEN:
            printf("%s%s%s", COLOR_GREEN, line.c_str(), COLOR_RESET);
            break;
        default:
            printf("%s", line.c_str());
            break;
        }
    #endif
}

/**
 * Write a line to the console.
 *
 * @param const std::string & line
 * @param Types::Colors color
 * @return void
 */
void Output::writeLine(const std::string & line, Types::Colors color)
{
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
        HANDLE hConsole;
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        FlushConsoleInputBuffer(hConsole);

        switch (color)
        {
        case Types::Colors::NORMAL:
            printf("%s\n", line.c_str());
            break;
        case Types::Colors::RED:
            SetConsoleTextAttribute(hConsole, COLOR_CRITICAL);
            printf("%s\n", line.c_str());
            break;
        case Types::Colors::YELLOW:
            SetConsoleTextAttribute(hConsole, COLOR_YELLOW);
            printf("%s\n", line.c_str());
            break;
        case Types::Colors::GREEN:
            SetConsoleTextAttribute(hConsole, COLOR_GREEN);
            printf("%s\n", line.c_str());
            break;
        default:
            printf("%s\n", line.c_str());
            break;
        }

        SetConsoleTextAttribute(hConsole, 15);
    #else
        switch (color)
        {
        case Types::Colors::NORMAL:
            printf("%s\n", line.c_str());
            break;
        case Types::Colors::RED:
            printf("%s%s%s\n", COLOR_CRITICAL, line.c_str(), COLOR_RESET);
            break;
        case Types::Colors::YELLOW:
            printf("%s%s%s\n", COLOR_YELLOW, line.c_str(), COLOR_RESET);
            break;
        case Types::Colors::GREEN:
            printf("%s%s%s\n", COLOR_GREEN, line.c_str(), COLOR_RESET);
            break;
        default:
            printf("%s\n", line.c_str());
            break;
        }
    #endif
}

/**
 * Write a line break to the console.
 * 
 * @return void
 */
void Output::writeLineBreak()
{
    std::cout << '\n';
}

/**
 * Create a progress bar instance.
 * 
 * @param const unsigned int items
 * @return ProgressBar *
 */
ProgressBar * Output::createProgressBar(const unsigned int items)
{
    return new ProgressBar(this, items);
}
