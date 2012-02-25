#include <iostream>
#include "include/td3Utility.hpp"
#include "include/testcases.hpp"

using namespace std;

int main()
{
    int errors = 0;
    srand(time(NULL));
    int i1 = testcases::randi();
    double d1 = testcases::randd();
    int i2 = td3Utility::stoi(td3Utility::toString(i1));
    double d2 = td3Utility::stof(td3Utility::toString(d1));
    if (i1 != i2)
    {
        errors++;
        cout << i1 << " ?= " << i2 << endl;
    }
    if (d1 != d2)
    {
        errors++;
        cout << d1 << " ?= " << d2 << endl;
    }
    return errors;
}
