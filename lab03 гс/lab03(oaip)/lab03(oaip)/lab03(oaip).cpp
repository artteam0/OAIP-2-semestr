#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {

    ifstream file1("FILE1.txt"); //открываем первый файл для чтения//
    ofstream file2("FILE2.txt"); //открываем второй файл для записи//

    if (!file1.is_open()) {
        cout << "error of opening first file" << endl;
        return -1;
    }
    if (!file2.is_open()) {
        cout << "error of opening second file" << endl;
        return -1;
    }

    string line;
    int lineCount = 0; //присваиваем значение 0 переменной кол-ва строк//

    for (int i = 0; i < 3; ++i) { //пропускаем первые три строки//
        
        if (!getline(file1, line)) { //если в file1 менее//
            cout << "erRor: first file has less than four str" << endl;
            return -1;
        }
    }

    while (getline(file1, line)) { //копируем строки во второй файл//
        file2 << line << endl;
        ++lineCount;
    }

    file1.close(); //закрываем файлы//
    file2.close();

    ifstream file2Read("FILE2.txt"); //открываем второй файл для чтения, для подсчёта кол-ва букв в последем слове//
    if (!file2Read.is_open()) {
        cout << "error of opening second file for reading" << endl;
        return -1;
    }

    string lastWord;
    while (file2Read >> lastWord) {} //последнее слово будет записано в переменную lastWord//

    cout << "num of letters in the last word: " << lastWord.size() << endl;

    file2Read.close(); //закрываем второй файл//

    return 0;
}


#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {

    ofstream fileWrite("FILE.txt");
    ifstream fileRead("file.txt");
    
    if (!fileRead.is_open()) {
        cout << "error of opening read file" << endl;
        return -1;
    }
    if (!fileWrite.is_open()) {
        cout << "error of opening write file" << endl;
        return -1;
    }
    
    char buffer[255];
    string buf;
    cout << "enter the string with zeros: " << endl;
    cin.getline(buffer, 255);
    fileWrite << buffer;
    fileWrite.close();

    fileRead.getline(buffer, 255);
    fileRead.close();

}

