#include <cstdlib>
#include "testcases.hpp"

int testcases::randi()
{
    return rand() % 20;
}

double testcases::randd()
{
    return rand() % 20 + ((rand() % 10) / (double)10);
}

