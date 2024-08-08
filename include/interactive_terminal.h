#pragma once

#include "Bit.h"
#include <string>

class InteractiveTerminal
{
public:
    Bit bit;
    InteractiveTerminal(Bit bit);
    // Main function
    void run();

private:
    // Display menu
    void print_menu();
    // Function to handle all the commands
    void handle_command(const std::string &command);
};
