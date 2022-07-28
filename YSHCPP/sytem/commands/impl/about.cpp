#include "../CommandItem.h"
#include <iostream>

class about : public CommandItem
{
    public:
        void execute(std::vector<std::string> args)
        {
            std::cout << "YSHCPP build " << 2 << std::endl;
        }

        std::string name()
        {
            return "About";
        }
        std::string description()
        {
            return "About YSHCPP";
        }
};