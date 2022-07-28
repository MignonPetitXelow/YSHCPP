#pragma once
#include <string>
#include <vector>

class CommandItem
{
    public:
        virtual void execute(std::vector<std::string>) = 0; // add args
        virtual std::string name() = 0;
        virtual std::string description() = 0;
};