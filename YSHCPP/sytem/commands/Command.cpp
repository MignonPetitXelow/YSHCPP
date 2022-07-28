#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

// Including system files
#include "CommandItem.h"
#include "../utils/StringExtension.cpp"

// Including the command items
#include "impl/test.cpp"
#include "impl/yexit.cpp"
#include "impl/about.cpp"
#include "impl/say.cpp"

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
            commands["say"] = new say();
		}

        // Execute the command by searching for the command name in the commands map
        void execute(std::string command)
        {
            StringExtension stringExtension;

            //temps
            std::vector<std::string> args = stringExtension.split(command, " ");

            std::unordered_map<std::string, CommandItem*>::iterator cmd = commands.find(command);
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
                    if(stringExtension.caseInsensitiveStringCompare(args[0], cmd->first))
                    {
                        //removing command from the vector list
                        args.erase(args.begin());

                        // Execute the command
                        cmd->second->execute(args);
                        hasBeenFound = true;
                    }
                }
            }
            // If the command is not found
            if(!hasBeenFound)
                std::cout << "\033[0;97;41m[Error] "<< "Command not found" << "\033[0m" << std::endl;

            // When task end, call the console
            std::cout << std::endl;
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
            std::cout << "\033[0;92m@User\033[0m:\033[0;94myshcpp\033[0m$ ";
            std::getline(std::cin, command);
            execute(command);
        }
};