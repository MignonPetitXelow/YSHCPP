#include "../CommandItem.h"

#include <string>
#include <iostream>

class test : public CommandItem
{
    public:
        void execute(std::vector<std::string> args)
        {
            std::cout << "Normal message" << std::endl;
            std::cout << "\033[0;97;43m[Warning] " << "Warning message" << "\033[0m" << std::endl;            
            std::cout << "\033[0;97;41m[Error] "<< "Error message" << "\033[0m" << std::endl;
            std::cout << "\033[0;97;42m[Success] " << "Success message" << "\033[0m" << std::endl;
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