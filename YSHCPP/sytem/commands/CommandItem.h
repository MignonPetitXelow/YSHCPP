#pragma once
#include <string>

class CommandItem
{
    public:
        virtual void execute() = 0;
        virtual std::string name() = 0;
        virtual std::string description() = 0;
};