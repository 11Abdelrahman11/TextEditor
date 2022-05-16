#include <iostream>
#include <cstring>
#include <fstream>
#include "TexteditorFunctionsheaders.h"

using namespace std;

int main()
{
    ifstream sourceFile;
    string data;
    loadFile(data, sourceFile);
    displayMenu(data, sourceFile);
    sourceFile.close();
    return 0;
}
