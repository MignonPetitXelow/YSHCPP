#include <iostream>
#include "sytem/commands/Command.cpp"

// Main function
int main()
{
    std::cout << "\033[1;30;107mYSHELL Prototype shell\033[0m\n";
    std::cout << "\033[1;30;107mType help to show commands\033[0m\n\n";

	Command command;
	command.init();
    
    command.Console();
}