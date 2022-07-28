#include <iostream>
#include <string>
#include <unordered_map>

// Including system files
#include "CommandItem.h"
#include "../utils/StringExtension.cpp"

// Including the command items
#include "impl/test.cpp"
#include "impl/yexit.cpp"
#include "impl/about.cpp"

// Command class (mostly coded by Venodez (ty))
class Command
{
	public:
        std::unordered_map<std::string, CommandItem*> commands;

        // Initialize the command system
		void init()
		{
            // Adding all the command items
			commands["test"] = new test();
            commands["exit"] = new yexit();
            commands["about"] = new about();
		}

        // Execute the command by searching for the command name in the commands map
        void execute(std::string command)
        {
            std::unordered_map<std::string, CommandItem*>::iterator cmd = commands.find(command);
			StringExtension stringExtension;
            bool hasBeenFound = false;

            // Check if is help command
            if(stringExtension.caseInsensitiveStringCompare(command, "help"))
            {
                    printHelp();
                    hasBeenFound = true;
            }   

            // Trying to found the command
            for (std::unordered_map<std::string, CommandItem*>::iterator cmd = commands.begin(); cmd != commands.end(); ++cmd)
            {   
                if(!hasBeenFound)
                {
                    if(stringExtension.caseInsensitiveStringCompare(command, cmd->first))
                    {
                        // Execute the command
                        cmd->second->execute();
                        hasBeenFound = true;
                    }
                }
            }
            // If the command is not found
            if(!hasBeenFound)
                std::cout << "\033[0;30;41m[Error] "<< "Command not found" << "\033[0m" << std::endl;

            // When task end, call the console
            Console();     
        }

        void printHelp()
        {
            std::cout << "YSHCPP commands:" << std::endl;
            
            // Print all the commands
            for (std::unordered_map<std::string, CommandItem*>::iterator cmd = commands.begin(); cmd != commands.end(); ++cmd)
            {
                std::cout << " > " << cmd->first << " - " << cmd->second->description() << std::endl;
            }
            std::cout << " > " << "help" << " - " << "show all commands" << std::endl;
        }

        void Console()
        {
            std::string command;
            std::cout << "@User:yshcpp> ";
            std::getline(std::cin, command);
            execute(command);
        }
};