#ifndef INPUT_INTERFACE_H
#define INPUT_INTERFACE_H

#include <string>


class InputInterface {

public:

    /**
     * Retrieve an input from the user.
     *
     * @param const std::string & question
     * @return std::string
     */
    virtual std::string ask(const std::string & question) = 0;

};


#endif // INPUT_INTERFACE_H