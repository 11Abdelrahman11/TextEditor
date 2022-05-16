#ifndef FUNCTIONSHEADERS_H_INCLUDED
#define FUNCTIONSHEADERS_H_INCLUDED

using namespace std;

void loadFile(string &text, ifstream &file);
void textToUpper(string &text);
void textToLower(string &text);
void camelCase(string &text);
bool findWord(string &text);
int wordRepetition(string &text);
int wordsCount(string &text);
void saveFile(string &text);
void mergeFiles(string&text);
string encrypt(string &text);
string decrypt(string &text);
int LinesCount(string &text);
void addWordsToFile(string &text);
void eraseData(string &text);
void numberOfCharacters(string &text);
void displayMenu(string& data, ifstream& file);

#endif // FUNCTIONSHEADERS_H_INCLUDED
