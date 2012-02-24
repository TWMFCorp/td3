#include <iostream>
#include "include/td3Variables.hpp"

namespace td3
{
    td3Variables variables;
}

using td3::variables;
using std::vector;
using std::string;
using std::cout;
using std::endl;

int main()
{
    variables[(vector<string>){"A","string","goes","here"}] = "and it should work";
    cout << variables[(vector<string>){"A","string","goes","here"}] << endl;
    variables["Hello"] = "World";
    cout << variables["Hello"] << endl;
    return 0;
}
