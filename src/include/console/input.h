#ifndef INPUT_H
#define INPUT_H

#include "interfaces/input_interface.h"


class Input : public InputInterface {

public:

    /**
     * Retrieve an input from the user.
     *
     * @param const std::string & question
     * @return std::string
     */
    std::string ask(const std::string & question) override;

};

#endif // INPUT_H