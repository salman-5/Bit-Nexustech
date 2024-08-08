#include "interactive_terminal.h"
#include <iostream>

int main(int argc, char **argv)
{

    // Throw error if path to working directory is not mentioned
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << "<Path to working directory>\n";
        return 1;
    }
    std::string path_to_watch = argv[1];
    Bit bit(path_to_watch);
    InteractiveTerminal terminal(bit);
    // Terminal run execution
    terminal.run();
    return 0;
}
