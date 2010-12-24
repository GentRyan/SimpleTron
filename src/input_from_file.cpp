#include "sml.h"

using namespace std;

void SimpleTron::ST_input_from_file(char* SourceFileName)
{
    cout << "Loading file." << endl;
    fstream SourceFile;
    SourceFile.open(SourceFileName, ios::in);
    int SourceFileLine = 0;
    while (SourceFile.eof() != true)
    {
        SourceFile >> memory[SourceFileLine];
        SourceFileLine++;
    }
    SourceFile.close();
}
