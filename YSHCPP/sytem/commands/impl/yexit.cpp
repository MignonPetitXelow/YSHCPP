#include "../CommandItem.h"
#include <iostream>
#include <stdlib.h>
#include <string>

class yexit : public CommandItem
{
    public:
        void execute()
        {
            std::cout << "\033[0;30;43m[Warning] " << "Exiting..." << "\033[0m" << std::endl;  
            std::exit(0);
        }

        std::string name()
        {
            return "Kill";
        }
        std::string description()
        {
            return "Kill the program";
        }
};