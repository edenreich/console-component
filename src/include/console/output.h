#ifndef OUTPUT_H
#define OUTPUT_H

#include "interfaces/output_interface.h"
#include "interfaces/application_interface.h"

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
        Output(Interfaces::ApplicationInterface* app);

        /**
         * Print the help message.
         *
         * @return void
         */
        void printHelp() override;

        /**
         * Print the command help message.
         *
         * @param Interfaces::CommandInterface * command
         * @return void
         */
        void printCommandHelp(Interfaces::CommandInterface* command) override;

        /**
         * Write a string to the console.
         *
         * @param const std::string line
         * @param ... any
         * @return void
         */
        void write(const std::string message, ...) override;

        /**
         * Write a colored string to the console.
         *
         * @param Types::Colors color
         * @param const std::string message
         * @param ... any
         * @return void
         */
        void write(Types::Colors color, const std::string message, ...) override;

        /**
         * Write a line to the console.
         *
         * @param const std::string & line
         * @param ... any
         * @return void
         */
        void writeLine(const std::string line, ...) override;

        /**
         * Write a colored line to the console.
         *
         * @param Types::Colors color
         * @param const std::string line
         * @param ... any
         * @return void
         */
        void writeLine(Types::Colors color, const std::string line, ...) override;

        /**
         * Write an error to the console.
         *
         * @param const std::string line
         * @param ... any
         * @return void
         */
        void error(const std::string line, ...) override;

        /**
         * Write an info to the console.
         *
         * @param const std::string line
         * @param ... any
         * @return void
         */
        void info(const std::string line, ...) override;

        /**
         * Write a warning to the console.
         *
         * @param const std::string line
         * @param ... any
         * @return void
         */
        void warning(const std::string line, ...) override;

        /**
         * Create a progress bar instance.
         *
         * @param const unsigned int items
         * @return ProgressBar
         */
        ProgressBar* createProgressBar(const unsigned int items) override;

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