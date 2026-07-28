#ifndef OUTPUT_H
#define OUTPUT_H

#include "interfaces/output_interface.h"
#include "interfaces/application_interface.h"

#include <string_view>

namespace Console
{
    /**
     * The Output Class
     */
    class Output : public Interfaces::OutputInterface
    {

    public:
        /**
         * Initialize the application interface.
         *
         * @param Interfaces::ApplicationInterface * app
         */
        Output(Interfaces::ApplicationInterface* app) noexcept;

        /**
         * Print the help message.
         *
         * @return void
         */
        void printHelp() noexcept override;

        /**
         * Print the command help message.
         *
         * @param Interfaces::CommandInterface * command
         * @return void
         */
        void printCommandHelp(Interfaces::CommandInterface* command) noexcept override;

        /**
         * Write a string to the console.
         *
         * @param std::string_view message
         * @return void
         */
        void write(std::string_view message) noexcept override;

        /**
         * Write a colored string to the console.
         *
         * @param Types::Colors color
         * @param std::string_view message
         * @return void
         */
        void write(Types::Colors color, std::string_view message) noexcept override;

        /**
         * Write a line to the console.
         *
         * @param std::string_view line
         * @return void
         */
        void writeLine(std::string_view line) noexcept override;

        /**
         * Write a colored line to the console.
         *
         * @param Types::Colors color
         * @param std::string_view line
         * @return void
         */
        void writeLine(Types::Colors color, std::string_view line) noexcept override;

        /**
         * Write an error to the console.
         *
         * @param std::string_view line
         * @return void
         */
        void error(std::string_view line) noexcept override;

        /**
         * Write an info to the console.
         *
         * @param std::string_view line
         * @return void
         */
        void info(std::string_view line) noexcept override;

        /**
         * Write a warning to the console.
         *
         * @param std::string_view line
         * @return void
         */
        void warning(std::string_view line) noexcept override;

        /**
         * Create a progress bar instance.
         *
         * @param const unsigned int items
         * @return ProgressBar
         */
        ProgressBar* createProgressBar(const unsigned int items) noexcept override;

    private:
        /**
         * Print the title of the application.
         *
         * @return void
         */
        void printApplicationTitle();

        /**
         * Print the usage line of the application.
         *
         * @return void
         */
        void printApplicationUsage();

        /**
         * Print the global options of the application.
         *
         * @return void
         */
        void printApplicationOptions();

        /**
         * Print the available commands.
         *
         * @return void
         */
        void printAvailableCommands();

    private:
        /**
         * Store the application interface.
         *
         * @var Interfaces::ApplicationInterface * m_app
         */
        Interfaces::ApplicationInterface* m_app;
    };
}

#endif // OUTPUT_H