#include "../CommandItem.h"

class foda : public CommandItem
{
    public:
        int execute(std::vector<std::string> args)
        {
            if(args.size() >= 2)
            {
                std::cout << "Invalid command" << std::endl;
                return 4;
            }

            FilesManager fm;
            std::vector<std::string> read = fm.read("YSHCppFiles/yshcppconfig.yco");

            if(fm.folderExists(read[3]+"/"+args[0]))
            {
                std::cout << "Invalid path [folder already exist]" << std::endl;
                return 9;
            }
            fm.createFolder(read[3]+"/"+args[0]);
            std::cout << "[TASK] " << read[3]+"/"+args[0] << "has been created." << std::endl;
            return 0;
        }

        std::string name()
        {
            return "Foda";
        }
        std::string description()
        {
            return "Create a new directory";
        }
};