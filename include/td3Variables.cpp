#include <map>
#include <string>
#include <vector>
#include "td3Variables.hpp"

using std::map;
using std::string;
using std::vector;
using std::tolower;

string td3Variables::getValue(vector<string> dimensions)
{
    if (dimensions.size() < currentDimensions(dimensions.at(0)))
        return "array";
    if (dimensions.size() > currentDimensions(dimensions.at(0)))
        return "";
    return VarContainer[dimensions];
}

string td3Variables::getValue(string name)
{
    vector<string> tmp (1,name);
    return getValue(tmp);
}

void td3Variables::setValue(vector<string> dimensions, string value)
{
    if (dimensions.size() != currentDimensions(dimensions.at(0)))
        unset(dimensions.at(0));
    VarContainer[dimensions] = value;
    return;
}

void td3Variables::setValue(string name, string value)
{
    vector<string> tmp (1,name);
    setValue(tmp,value);
    return;
}

unsigned int td3Variables::currentDimensions(string name)
{
    for (map<vector<string>,string>::iterator it = VarContainer.begin(); it != VarContainer.end(); ++it)
    {
        if (toLower(it->first.at(0)) == toLower(name))
            return it->first.size();
    }
    return 0;
}

void td3Variables::unset(vector<string> dimensions)
{
    if (dimensions.size() == currentDimensions(dimensions.at(0)))
        VarContainer.erase(dimensions);
    else
    {
        vector< vector< string > > tmp = nextDimension(dimensions);
        for ( unsigned int i = 0; i < tmp.size(); ++i)
            unset(tmp.at(i));
    }
    return;
}

void td3Variables::unset(string name)
{
    for (map<vector<string>,string>::iterator it = VarContainer.begin(); it != VarContainer.end(); ++it)
    {
        if (toLower(it->first.at(0)) == toLower(name))
            VarContainer.erase(it);
    }
    return;
}

bool td3Variables::isSet(vector<string> dimensions)
{
    for (map<vector<string>,string>::iterator it = VarContainer.begin(); it != VarContainer.end(); ++it)
    {
        if (contains(dimensions, it->first))
            return true;
    }
    return false;
}

bool td3Variables::isSet(string name)
{
    return currentDimensions(name);
}

vector< vector< string > > td3Variables::nextDimension(vector<string> dimensions)
{
    vector< vector< string > > ret;
    if (dimensions.size() >= currentDimensions(dimensions.at(0)))
        return ret;
    for (map< vector< string >, string>::iterator it = VarContainer.begin(); it != VarContainer.end(); ++it)
    {
        if (!contains(dimensions, it->first))
            continue;
        vector<string> tmp (it->first.begin(),it->first.begin()+dimensions.size()+1);
        if (toLower(tmp.at(dimensions.size())) != toLower(ret.at(ret.size()-1).at(dimensions.size())))
        ret.push_back(tmp);
    }
    return ret;
}

vector< vector< string > > td3Variables::nextDimension(string name)
{
    vector<string> tmp (1,name);
    return nextDimension(tmp);
}

bool td3Variables::contains(vector<string> needle, vector<string> haystack)
{
    if (needle.size() > haystack.size())
        return false;
    for (unsigned int i = 0; i < needle.size(); ++i)
    {
        if (toLower(needle.at(i)) != toLower(haystack.at(i)))
            return false;
    }
    return true;
}

string td3Variables::toLower(string stol)
{
    for(unsigned int i = 0; i != stol.length(); ++i)
        stol[i] = tolower(stol[i]);
    return stol;
}

bool td3Variables::less::operator() (vector< string > first, vector< string> second)
{
    if (first.size() < second.size())
        return true;
    else if (first.size() > second.size())
        return false;
    for (unsigned int i = 0; i < first.size(); ++i)
    {
        if (toLower(first.at(i)) < toLower(second.at(i)))
            return true;
    }
    return false;
}

string& td3Variables::operator[](vector<string> index)
{
    return VarContainer[index];
}

string& td3Variables::operator[](string index)
{
    return VarContainer[(vector<string>){index}];
}
