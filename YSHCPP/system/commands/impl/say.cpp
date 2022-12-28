#include "../CommandItem.h"
#include <string>
#include <iostream>

class say : public CommandItem
{
    public:
        int execute(std::vector<std::string> args) 
        {
            if(args.size() == 0)
            {
                std::cout << "\033[0;97;43m[Warning] " << "say [args]" << "\033[0m" << std::endl; 
                return 4;
            }

            std::string message = "";

            for(int i = 0; i < args.size(); i++)
            {
                message += args[i] + " "; 
            }

            std::cout << message << std::endl;
            return 0;
        }

        std::string name()
        {
            return "say";
        }
        std::string description()
        {
            return "it say something";
        }
};