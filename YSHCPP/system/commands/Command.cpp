#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

// Including system files
#include "CommandItem.h"

// Including the command items
#include "impl/test.cpp"
#include "impl/yexit.cpp"
#include "impl/about.cpp"
#include "impl/say.cpp"
#include "impl/cd.cpp"
#include "impl/foda.cpp"
#include "impl/fode.cpp"

// Command class (mostly coded by Venodez (ty))
class Command
{
	public:
        FilesManager fm;
        std::unordered_map<std::string, CommandItem*> commands;

		void init()
		{
			commands["test"] = new test();
            commands["exit"] = new yexit();
            commands["about"] = new about();
            commands["say"] = new say();
            commands["cd"] = new cd();
            commands["foda"] = new foda();
            commands["fode"] = new fode();
		}

        void execute(std::string command)
        {
            if(command == "" || command.size() > 64)
            {
                std::cout << "\n\033[0;97;43m[Warning] " << "Illegal arguments" << "\033[0m" << std::endl; 

                Console(); 
                return;
            }
            StringExtension stringExtension;

            std::vector<std::string> args = stringExtension.split(command, " ");

            std::unordered_map<std::string, CommandItem*>::iterator cmd = commands.find(command);
            bool hasBeenFound = false;

            if(stringExtension.caseInsensitiveStringCompare(command, "help"))
            {
                    printHelp();
                    hasBeenFound = true;
            }   

            for (std::unordered_map<std::string, CommandItem*>::iterator cmd = commands.begin(); cmd != commands.end(); ++cmd)
            {   
                if(!hasBeenFound)
                {
                    if(stringExtension.caseInsensitiveStringCompare(args[0], cmd->first))
                    {
                        args.erase(args.begin());

                        int retcode = cmd->second->execute(args);
                        hasBeenFound = true;

                        if(retcode > 0)
                            std::cout << "\n\033[0;97;41m[TASK-ERR] "<< "Task \'cmd@"+cmd->second->name()+"\' ended with error code: "<< retcode << "\033[0m" << std::endl;
                    }
                }
            }
            if(!hasBeenFound)
                std::cout << "\n\033[0;97;41m[Error] "<< "Command not found" << "\033[0m" << std::endl;

            std::cout << std::endl;
            Console();     
        }

        void printHelp()
        {
            std::string out = "YSHCPP commands: \n";
            out += " > help - show all commands\n";
            for (std::unordered_map<std::string, CommandItem*>::iterator cmd = commands.begin(); cmd != commands.end(); ++cmd)
            {
                out += " > "+cmd->first+" - "+cmd->second->description()+"\n";
            }
            std::cout << out;
        }

        void Console()
        {
            std::vector<std::string> read = fm.read("YSHCppFiles/yshcppconfig.yco");
            std::string command;
            std::cout << "\033[0;92m"+read[1]+"@YshCpp\033[0m:\033[0;94m"+read[3]+"\033[0m$ ";
            std::getline(std::cin, command);
            execute(command);
        }
};