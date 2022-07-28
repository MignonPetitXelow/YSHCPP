#include <iostream>
#include "sytem/commands/Command.cpp"

// Main function
int main()
{
    std::cout << "\033[1;97mYSHELL Prototype shell\033[0m\n";
    std::cout << "\033[1;97mType help to display commands\033[0m\n\n";

	Command command;
	command.init();
    
    command.Console();
}