#ifndef SML_H_INCLUDED
#define SML_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>

class SimpleTron
{
private:
    int memory[100];
    int newword;
    int location;
    int counter;
    int operationCode;
    int operand;
    int instructionRegister;
    int accumulator;
public:
    SimpleTron();
    void ST_ManInput();
    void ST_Interpret();
    void ST_Operations(int);
    void computer_dump();
    void ST_input_from_file(char *);
    int ST_AbortRetryFail();
};


#endif // SML_H_INCLUDED
