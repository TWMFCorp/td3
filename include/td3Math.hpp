#ifndef TD3_MATH_HPP_INCLUDED
#define TD3_MATH_HPP_INCLUDED

#include <vector>
#include <string>
#include <map>

class td3Math
{
    using std::map;
    using std::string;
    using std::vector;
private:
    map<string, string (*)(vector<vector<string> >) > functions;
    static string plus(vector<vector<string> >);
    static string minus(vector<vector<string> >);
    static string mult(vector<vector<string> >);
    static string div(vector<vector<string> >);
    static string pow(vector<vector<string> >);
    static string mod(vector<vector<string> >);
public:
    void setFunctions(string);
    void setFunctions(string, string (* func)(vector<vector<string> >));
    string wrapper(vector<vector<string> >, string);
};

#endif // TD3_MATH_HPP_INCLUDED
