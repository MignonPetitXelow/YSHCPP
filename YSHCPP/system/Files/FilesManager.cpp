#include <sys/stat.h>
#include <string>
#include <vector>
#include <sys/stat.h>
#include <iostream>
#include <fstream>
#include <unistd.h>

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

            
            return result;
        }

        bool folderExists(std::string folder)
        {
            StringExtension stringExtension;
            std::string path = folder;

            path = stringExtension.replace(path, " ", "/");

            struct stat buffer;
            bool result (stat (path.c_str(), &buffer) == 0);

            
            return result;
        }

        std::vector<std::string> read(std::string path)
        {
            std::ifstream file;
            std::vector<std::string> res;
            StringExtension str;

            file.open(path,std::ios::in);
            if (file.is_open())
            {   
                std::string line;
                while(getline(file, line))
                {
                    res.push_back(str.replace(line, " ", ""));
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
            std::string tempsVar = read(path)[line];
            return tempsVar;
        }

        void Goto(std::string arg)
        {
            writeLine("YSHCppFiles/yshcppconfig.yco",4,arg);
        }

        std::string getExecDir()
        {
            return read("YSHCppFiles/yshcppconfig.yco")[3];
        }

        void initSystemFiles()
        {
            StringExtension str;
            std::string directory = "YSHCppFiles";
            std::vector<std::string> configContents = str.split("#Username: ?yshcpp ?#Directory: ?/mnt/", "?");

            if(!folderExists(directory))
            {
                std::cout << "\033[0;97;43m[Warning] " <<"creating system files..." << "\033[0m" << std::endl;
                createFolder(directory);
                createFile(directory+"/yshcppconfig.yco", configContents);


                std::cout << "\033[0;97;42m[Success] " << "every files has been created" << "\033[0m" << std::endl << std::endl;
            }
        }

        int createFolder(std::string path)
        {
            return mkdir(path.c_str(), 7777);
        }

        int removeFolder(std::string path)
        {
            return rmdir(path.c_str());
        }

        void createFile(std::string path)
        {
            std::ofstream file(path);
            file.close();
        }

        void createFile(std::string path, std::vector<std::string> contents)
        {
            std::ofstream file(path);
            std::string content;
            for(int i = 0; i < contents.size(); ++i)
            {
                content += contents[i] + "\n";
            }
            file << content;
            file.close();
        }

};