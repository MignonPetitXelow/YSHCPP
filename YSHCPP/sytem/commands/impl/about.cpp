#include "../CommandItem.h"
#include <iostream>

class about : public CommandItem
{
    public:
        void execute()
        {
            std::cout << "YSHCPP version " << 1 << std::endl;
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