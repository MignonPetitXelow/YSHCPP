#include "../CommandItem.h"

class cd : public CommandItem
{
    public:
        int execute(std::vector<std::string> args)
        {
            std::string result = "";
            FilesManager fm;
            for(int i = 0; i < args.size(); ++i) 
            {
                result += args[i];
            }
            if(fm.folderExists(fm.getExecDir()+result))
            {
                fm.Goto(fm.getExecDir()+result);
                return 0;
            }
            std::cout << "Directory does not exist" << std::endl;
            return 8;
        }
        std::string name()
        {
            return "cd";
        }
        std::string description()
        {
            return "go to a folder location";
        }
};