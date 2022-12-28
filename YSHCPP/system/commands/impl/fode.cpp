#include "../CommandItem.h"

class fode : public CommandItem
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

            if(!fm.folderExists(read[3]+"/"+args[0]))
            {
                std::cout << "Invalid path [folder doesn't exist]" << std::endl;
                return 8;
            }

            fm.removeFolder(read[3]+"/"+args[0]);
            std::cout << "[TASK] Directory \"" <<read[3]+"/"+args[0] << "\" has been removed."; 
            return 0;
        }

        std::string name()
        {
            return "Fode";
        }
        std::string description()
        {
            return "Delete directory";
        }
};