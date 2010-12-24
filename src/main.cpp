#include <iostream>
#include <iomanip>
#include "sml.h"
using namespace std;

int main(int argc, char *argv[])
{
    SimpleTron smp;
    if  (argc > 1)
    {
        smp.ST_input_from_file(argv[1]);
    }
    else
    {
        smp.ST_ManInput();
    }

    smp.ST_Interpret();
    smp.computer_dump();

}
