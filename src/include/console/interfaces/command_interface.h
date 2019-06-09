#ifndef COMMAND_H
#define COMMAND_H

#include "../types/exit_code.h"
#include "input_interface.h"
#include "output_interface.h"


class CommandInterface {

public:

    /**
     * Handle the command.
     *
     * @param InputInterface * input
     * @return ExitCode
     */
    virtual ExitCode handle(InputInterface * input, OutputInterface * output) = 0;

    /**
     * Retrieve the name of the command.
     *
     * @return std::string
     */
    virtual std::string getName() = 0;

    /**
     * Retrieve the description of the command.
     *
     * @return std::string
     */
    virtual std::string getDescription() = 0;

};


#endif // COMMAND_H