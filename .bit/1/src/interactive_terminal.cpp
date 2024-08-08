#include "interactive_terminal.h"
#include <iostream>
#include <sstream>

InteractiveTerminal::InteractiveTerminal(Bit bit) : bit(bit) {}

// Infinite loop until exit
void InteractiveTerminal::run()
{
    std::string command;
    print_menu();
    while (true)
    {
        std::cout << "Enter command: ";
        std::getline(std::cin, command);
        if (command == "exit")
        {
            break;
        }
        handle_command(command);
    }
}
// Display all options in the application
void InteractiveTerminal::print_menu()
{
    std::cout << "Bit - A simple version control system:\n";
    std::cout << "1. help - Show available commands\n";
    std::cout << "2. commit <message> - Commit current to a new version with a message\n";
    std::cout << "3. list versions - List all available versions\n";
    std::cout << "4. list changes - List all current changes\n";
    std::cout << "5. exit - Exit the terminal\n";
}

void InteractiveTerminal::handle_command(const std::string &command)
{
    std::istringstream iss(command);
    std::string command_type;
    iss >> command_type;
    // "help" command
    if (command_type == "help")
    {
        print_menu();
    }
    // "commit" command need a second argument as message
    else if (command_type == "commit")
    {
        std::string message;
        std::getline(iss, message);
        if (message.empty())
        {
            std::cout << "Error: Commit message cannot be empty.\n";
        }
        else
        {
            bit.commit(message);
        }
    }
    // "list versions" command to print out all the available versions
    else if (command == "list versions")
    {
        bit.list_versions();
    }
    // "list changes" command to print out all the current changes
    else if (command == "list changes")
    {
        bit.check_files(false);
    }
    else
    {
        std::cout << "Unknown command: " << command << std::endl;
    }
}
