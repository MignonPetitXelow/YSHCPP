#include <iostream>
#include "system/commands/Command.cpp"
#include <string>

FilesManager fiMa;
// Main function
int main()
{
    std::cout << "\033[1;97mYSHELL Prototype shell\033[0m\n";
    std::cout << "\033[1;97mType help to display commands\033[0m\n\n";
    
    fiMa.initSystemFiles();
    fiMa.writeLine("YSHCppFiles/yshcppconfig.yco", 4, "/mnt/");

	Command command;
	command.init();    
    command.Console();

}