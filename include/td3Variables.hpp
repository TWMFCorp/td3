#ifndef TD3_VARIABLES_HPP_INCLUDED
#define TD3_VARIABLES_HPP_INCLUDED

#include <map>
#include <string>
#include <vector>

class td3Variables
{
private:
    struct less { bool operator() (std::vector< std::string > first, std::vector< std::string> second); };
    std::map< std::vector<std::string>,std::string, less> VarContainer;
    unsigned int currentDimensions(std::string name);
    bool contains(std::vector<std::string> needle, std::vector<std::string> haystack);
    bool caseInsensitiveCompare(std::vector< std::string > first, std::vector< std::string > second);
    static std::string toLower(std::string stol);
public:
    std::string getValue(std::vector<std::string> dimensions);
    std::string getValue(std::string name);
    void setValue(std::vector<std::string> dimensions, std::string value = "");
    void setValue(std::string name, std::string value = "");
    void unset(std::vector<std::string> dimensions);
    void unset(std::string name);
    bool isSet(std::vector<std::string> dimensions);
    bool isSet(std::string name);
    std::vector< std::vector< std::string > > nextDimension(std::vector<std::string> dimensions);
    std::vector< std::vector< std::string > > nextDimension(std::string name);

};

#endif // TD3_VARIABLES_HPP_INCLUDED
