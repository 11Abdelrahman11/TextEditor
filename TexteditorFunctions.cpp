#include <iostream>
#include <cstring>
#include <fstream>
#include "TexteditorFunctionsheaders.h"

using namespace std;

string fileName;

void displayMenu(string& data, ifstream& file){
    bool loop = true;
    int choice;
    while(loop){
        cout << "Enter the Number of the Operation: \n";
        cout << "1- Print Data \n";
        cout << "2- Data to Upper Case \n";
        cout << "3- Data to Lower Case \n";
        cout << "4- Data to Camel Case \n";
        cout << "5- Find Word \n";
        cout << "6- Word Repetition \n";
        cout << "7- erase data \n";
        cout << "8- number of letters in file \n";
        cout<< "9- add words to the file \n";
        cout << "10- Words Count \n";
        cout << "11- Merge Files \n";
        cout << "12- Encrypt Data \n";
        cout << "13- Decrypt Data \n";
        cout << "14- Lines Count \n";
        cout << "15- Save File \n";
        cout << "16- Exit \n";
        cin >> choice;
        if (choice == 1){
            cout << data << endl;
        }

        else if (choice == 2){
            textToUpper(data);
        }

        else if (choice == 3){
            textToLower(data);
        }

        else if (choice == 4){
            camelCase(data);
        }
        else if (choice == 5){
            if(findWord(data) == 0){
               cout << "Not Found";
            }
            else{
                cout << "Found";
            }
        }

        else if (choice == 6){
                int result = wordRepetition(data);
                if(result == 0){
                    cout << "Word Is Not Found!" << endl;
                }
                else{
                    cout << "This Word Is Repeated " << result << " Time/s" << endl;
                }
        }

        else if (choice==7){
        eraseData(data);
        }

        else if (choice ==8 ){
        numberOfCharacters(data);
        }

        else if (choice == 9){
        addWordsToFile(data);
        }

        else if (choice == 10){
            cout << "This File Contains " << wordsCount(data) << " Word/s" << endl;
        }

        else if (choice == 11){
            mergeFiles(data);
        }

        else if (choice == 12){
            data = encrypt(data);
        }

        else if (choice == 13){
            data = decrypt(data);
        }
        else if (choice == 14){
            cout << "Number of Lines In This File Is: " << LinesCount(data) << endl;
        }
        else if (choice == 15){
            saveFile(data);
        }
        else if (choice == 16){
            loop = false;
        }
    }
}
void loadFile(string &text, ifstream &file){
    char srcFileName[100], word[101];
    cout << "Enter File Name: ";
    cin >> srcFileName;
    file.open(strcat(srcFileName, ".txt"));
    fileName = srcFileName;
    if (file.fail()){
        cout << "File not found !" << endl;
        cout << "New File Will Be Created at the End";
    }
    else{
        cout << "File found !" << endl;
        while(!file.eof()){
            file.getline(word, 100, '\n');
            text.append(string(word));
            text.append("\n");
        }
    }
}
void textToUpper(string &text){
    for(int chr = 0; chr < text.length(); chr++){
        text[chr] = toupper(text[chr]);
    }
}
void textToLower(string &text){
    for(int chr = 0; chr < text.length(); chr++){
        text[chr] = tolower(text[chr]);
    }
}
void camelCase(string &text){
    for(int chr = 0; chr < text.length(); chr++){
        if(chr == 0){
            text[chr] = toupper(text[chr]);
        }
        else if(text[chr - 1] == ' '){
            text[chr] = toupper(text[chr]);
        }
        else{
            text[chr] = tolower(text[chr]);
        }
    }
}
bool findWord(string &text){
    bool found;
    string word;

    cout << "Enter the Word You Want to Find: ";
    cin >> word;
    found = text.find(word);
    return found;
}
int wordRepetition(string &text){
    string cWord, word;
    int counter = 0;

    cout << "Enter the Word You Want to Count: ";
    cin >> cWord;
    for (int i = 0; i < text.length(); i++){
        if(text[i] != ' '){
            word += text[i];
            if (i == (text.length() - 1)){
                if(word == cWord){
                    counter++;
                }
            }
        }
        else if(text[i] == ' '){
            if(word == cWord){
                counter++;
            }
            word = "";
        }
    }
    return counter;
}
void saveFile(string &text){
    ofstream editedFile;
    editedFile.open(fileName);
    editedFile << text;
    editedFile.close();
}
int wordsCount(string &text){
    string word;
    int counter = 0;

    for (int i = 0; i < text.length(); i++){
        if(text[i] != ' '){
            word += text[i];
            if (i == (text.length() - 1)){
                counter++;
            }
        }
        else if(text[i] == ' '){
            counter++;
            word = "";
        }
    }
    return counter;
}
void mergeFiles(string &text){
    fstream file;
    string text2;
    char srcFileName[100], word[101];
    cout << "Enter Second File Name: ";
    cin >> srcFileName;
    file.open(strcat(srcFileName, ".txt"));
    if (file.fail()){
        cout << "File not found !" << endl;
        cout << "New File Will Be Created at the End";
    }
    else{
        cout << "File found !" << endl;
        while(!file.eof()){
            file.getline(word, 100, '\n');
            text2.append(string(word));
        }
    }
    text.append(text2);
}
string encrypt(string &text){
    int key = 2,dSize;
    string encrypted;
    dSize = text.length();
    char arr [key][dSize];
    for (int k = 0; k < key; ++k){ // 2D array with number of rows == encryption key and number of columns == message size (number of characters);
        for (int s = 0; s < dSize; ++s){
            arr [k][s] = 0;
        }
    }
    for (int k = 0,s = 0,d = 1; s < dSize; k+= d,++s){ //d for direction, s for message size, k for encryption key
        arr [k][s] = text[s];
        if (k == key-1){ // changing the direction
            d = -1;
        }
        else if (k == 0) { // taking the char/s in the bottom of the rows
            d = 1;
        }
    }
    for (int k = 0; k < key; ++k){
        for (int s = 0; s < dSize; ++s){
            if (arr [k][s] != 0){
                encrypted += (arr [k][s]-20);
            }
        }
    }
    return encrypted;
}
string decrypt(string &text){
    int key = 2,edSize;
    string message;
    edSize = text.length();
    char arr [key][edSize];
    for (int k = 0; k < key; ++k){ // 2D array with number of rows == encryption key and number of columns == encrypted message size (number of characters);
        for (int s = 0; s < edSize; ++s){
            arr [k][s] = 0;
        }
    }
    for (int k = 0,s = 0,d = 1; s < edSize; k += d,++s){ //d for direction, s for encrypted message size, k for encryption key
        arr [k][s] = '*'; // putting '*' char in the right positions of the encryption method
        if (k == key-1){ // changing the direction
            d = -1;
        }
        else if (k == 0) { // taking the char/s in the bottom of the rows
            d = 1;
        }
    }
    int counter = 0;
    for (int k = 0; k < key; ++k){ //d for direction, s for encrypted message size, k for encryption key
        for (int s = 0; s < edSize; ++s){
            if (arr [k][s] == '*'){
                arr [k][s] = text[counter++];
            }
        }
    }
    for (int k = 0,s = 0,d = 1; s < edSize; k += d,++s){ //d for direction, s for message size, k for encryption key
        message += (arr [k][s]+20);
        if (k == key-1){ // changing the direction
            d = -1;
        }
        else if (k == 0) { // taking the char/s in the bottom of the rows
            d = 1;
        }
    }
    return message;
}
int LinesCount(string &text){
    string line;
    int counter = 0;

    for (int i = 0; i < text.length(); i++){
        if(text[i] != '\n'){
            if (i == (text.length() - 1)){
                counter++;
            }
        }
        else if(text[i] == '\n'){
            counter++;
        }
    }
    return counter;
}
void addWordsToFile(string &text){
    string newWords;
    cin.ignore();
    getline(cin,newWords);
    text.append(newWords);
}
void eraseData(string &text){
    text.erase();
}
void numberOfCharacters(string &text){
    cout<<text.length();
}
