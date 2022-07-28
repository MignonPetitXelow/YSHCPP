#include "../CommandItem.h"
#include <string>
#include <iostream>

class say : public CommandItem
{
    public:
        void execute(std::vector<std::string> args)
        {
            if(args.size() == 0)
            {
                //! TODO IMPORTANT: check if args contains \n \r ect...
                std::cout << "\033[0;97;43m[Warning] " << "say [args]" << "\033[0m" << std::endl; 
                return;
            }

            std::string message = "";

            for(int i = 0; i < args.size(); i++)
            {
                message += args[i] + " ";
            }

            std::cout << message << std::endl;
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