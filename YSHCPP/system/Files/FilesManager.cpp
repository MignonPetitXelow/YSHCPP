#include <sys/stat.h>
#include <string>
#include <vector>
#include <sys/stat.h>
#include <iostream>
#include <fstream>

#include "../utils/StringExtension.cpp"

class FilesManager
{
    public: 
        std::string dir = "";

        bool folderExists(std::vector<std::string> folder)
        {
            StringExtension stringExtension;
            std::string path = "";

            for(int i = 0; i < folder.size(); i++)
                path += folder[i];

            path = stringExtension.replace(path, " ", "/");

            struct stat buffer;
            bool result (stat (path.c_str(), &buffer) == 0);

            std::cout << path << std::endl;
            std::cout << result << std::endl;
            
            return result;
        }

        std::vector<std::string> read(std::string path)
        {
            std::ifstream file;
            std::vector<std::string> res;

            file.open(path,std::ios::in);
            if (file.is_open())
            {   
                std::string line;
                while(getline(file, line))
                {
                    res.push_back(line);
                    std::cout << line << std::endl;
                }
                file.close(); 
            }
            return res;
        } 

        void writeLine(std::string path, int lineToWrite, std::string thingToWrite)
        {
            std::ifstream file;
            std::string cont;
            std::string line;

            file.open(path);
            
            for(int i = 0; i < lineToWrite-1; i++)
            {
                std::getline(file, line);
                cont += line + "\n";
            }
            std::getline(file, line);

            cont += thingToWrite + "\n";

            while(std::getline(file, line))
                cont += line + "\n";

            file.close();

            std::ofstream fileWrite(path);

            fileWrite << cont;
        }

        void write(std::string path, std::vector<std::string> lines)
        {
            std::string line;

            for(int i = 0; i < lines.size(); ++i)
            {
                line += lines[i] + "\n";
            }

            std::ofstream fileWrite(path);
            fileWrite << line;
        }

        std::string getVarFromFile(std::string path, int line)
        {
            return read(path)[line];
        }

        void Goto(std::string arg)
        {
            dir = arg;
            std::cout << dir << std::endl;
        }

        std::string getExecDir()
        {
            return dir;
        }

};