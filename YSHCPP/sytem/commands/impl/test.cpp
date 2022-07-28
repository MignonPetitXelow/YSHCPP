#include "../CommandItem.h"

#include <string>
#include <iostream>

class test : public CommandItem
{
    public:
        void execute()
        {
            std::cout << "Normal message" << std::endl;
            std::cout << "\033[0;30;43m[Warning] " << "Warning message" << "\033[0m" << std::endl;            
            std::cout << "\033[0;30;41m[Error] "<< "Error message" << "\033[0m" << std::endl;
        }

        std::string name()
        {
            return "test name";
        }
        std::string description()
        {
            return "description test";
        }
};