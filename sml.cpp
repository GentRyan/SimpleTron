#include "sml.h"
using namespace std;

SimpleTron::SimpleTron()
{
    for(int count=0; count < 100; count++ )
    {
        memory[count] = 0;
    };
    newword = 0;
    location = 0;
    counter = 0;
    operationCode = 0;
    operand = 0;
    instructionRegister = 0;
    accumulator = 0;
}

void SimpleTron::ST_ManInput()
{
    cout << "*************************************************" << endl;
    cout << "***           Welcome to Simpletron!          ***" << endl;
    cout << "***                                           ***" << endl;
    cout << "*** Please enter your program one instruction ***" << endl;
    cout << "*** (or data word) at a time. I will type the ***" << endl;
    cout << "*** location number and a quesiton mark (?) . ***" << endl;
    cout << "*** You then type the word for that location. ***" << endl;
    cout << "*** Type the sentinel -99999 to stop entering ***" << endl;
    cout << "*** your program.                             ***" << endl;
    cout << "*************************************************" << endl;

    while (newword != -99999)
    {
        cout << setprecision(2) << location << " ? ";
        cin >> newword;
        memory[location] = newword;
        location += 1;
    }
    cout << "*** Program loading complete ***" << endl;
}

void SimpleTron::ST_Interpret()
{
    cout << "*** Program execution begins ***" << endl;

    while (counter != 99)
    {
        instructionRegister = memory[counter];
        operationCode = instructionRegister / 100;
        operand = instructionRegister % 100;
        ST_Operations(operationCode);
        if (operationCode==43)
        {
            break;
        }
    }
}

void SimpleTron::ST_Operations(int operationCode)
{
    location = counter;
    switch (operationCode)
    {
    case 10 :
        cout << "? ";
        cin >> memory[operand];
        ++counter;
        break;
    case 11:
        cout << memory[operand] << endl;
        ++counter;
        break;

    case 20 :
        accumulator = memory[operand];
        ++counter;
        break;
    case 21 :
        memory[operand] = accumulator;
        ++counter;
        break;
    case 30 :
        accumulator += memory[operand];
        ++counter;
        break;
    case 31 :
        accumulator -= memory[operand];
        ++counter;
        break;
    case 32 :
        accumulator *= memory[operand];
        ++counter;
        break;
    case 33 :
        accumulator /= memory[operand];
        ++counter;
        break;
    case 40 :
        counter = operand;
        break;
    case 41 :
        if (accumulator < 0)
        {
            counter = operand;
        }
        break;
    case 42 :
        if (accumulator == 0)
        {
            counter = operand;
        }
        break;
    case 43 :
        cout << "*** Simpletron execution terminated ***";
        break;
    }
    if (counter == location)
    {
        counter++;
    }
}

void SimpleTron::computer_dump()
{
    cout << endl << endl;
    cout << "REGISTERS:" << endl;
    cout << "accumulator" << "            " << accumulator << endl;
    cout << "counter" <<  "                " << counter << endl;
    cout << "instructionRegister" << "    " << instructionRegister << endl;
    cout << "operationCode" << "          " << operationCode << endl;
    cout << "operand" << "                " << operand << endl;
    cout << endl << endl;

    for(int count=0; count < 100; count++ )
    {
        memory[count] = 0;
    }
    newword = 0;
    location = 0;
    counter = 0;
    operationCode = 0;
    operand = 0;
    instructionRegister = 0;
    accumulator = 0;

    ST_AbortRetryFail();
}

int SimpleTron::ST_AbortRetryFail()
{
    cout << "What would you like to do? 1.New Program 2.Load Prgram 3.Retry 4.Quit " << endl;
    int UserChoice;
    cin >> UserChoice;
    switch (UserChoice)
    {
    case 3 :
        ST_Interpret();
        computer_dump();
        break;
    case 1 :
        ST_ManInput();
        ST_Interpret();
        computer_dump();
        break;
    case 2 :
        cout << "Enter File Name: " << endl;
        char NewFile[32];
        cin >> NewFile;
        ST_input_from_file(NewFile);
        ST_Interpret();
        computer_dump();
        break;
    case 4 :
        exit (1);
        break;
    }
    cout << "Invalid choice" << endl;
    return 0;
}
