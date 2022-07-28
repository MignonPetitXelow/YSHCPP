#include <string>
#include <bits/stdc++.h>

class StringExtension
{
    public:
        bool caseInsensitiveStringCompare( const std::string& str1, const std::string& str2 ) 
        {
            std::string str1Cpy( str1 );
            std::string str2Cpy( str2 );
            std::transform( str1Cpy.begin(), str1Cpy.end(), str1Cpy.begin(), ::tolower );
            std::transform( str2Cpy.begin(), str2Cpy.end(), str2Cpy.begin(), ::tolower );
            return ( str1Cpy == str2Cpy );
        }

        std::vector<std::string> split(std::string str, std::string token)
        {
            std::vector<std::string>result;
            while(str.size()){
                int index = str.find(token);
                if(index!=std::string::npos)
                {
                    result.push_back(str.substr(0,index));
                    str = str.substr(index+token.size());
                    if(str.size()==0)result.push_back(str);
                }else{
                    result.push_back(str);
                    str = "";
                }
            }
            return result;
        }
};