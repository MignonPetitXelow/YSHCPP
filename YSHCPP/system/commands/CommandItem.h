#pragma once
#include <string>
#include <vector>
#include "../Files/FilesManager.cpp"

class CommandItem
{
    public:
        virtual int execute(std::vector<std::string>) = 0; //DEFAULT_RETURN_VALUE: = 0
        virtual std::string name() = 0;
        virtual std::string description() = 0;
};