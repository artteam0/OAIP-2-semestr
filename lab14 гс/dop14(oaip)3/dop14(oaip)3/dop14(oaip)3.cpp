#include<iostream>
#include<fstream>
#include<vector>
#include<list>

using namespace std;

int hashFunction(int value, int tableSize) {
    return value% tableSize; // Простейшая хеш-функция, использующая остаток от деления на размер таблицы
}

void addNumber(vector<list<int>>& hashTable, int value) {
    int index = hashFunction(value, hashTable.size());
    hashTable[index].push_back(value);
}

bool searchNumber(const vector<list<int>>& hashTable, int value) {
    int index = hashFunction(value, hashTable.size());
    for (const auto& num : hashTable[index]) {
        if (num == value) {
            return true;
        }
    }
    return false;
}

void printHashTable(const vector<list<int>>& hashTable) {
    for (int i = 0; i < hashTable.size(); ++i) {
        cout << "Хеш " << i << ": ";
        for (const auto& num : hashTable[i]) {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main() {
    setlocale(LC_CTYPE, "rus");
    const int tableSize = 10; // Размер хеш-таблицы
    vector<list<int>>hashTable(tableSize);

    ifstream inputFile("numbers.txt");
    int number;
    while (inputFile >> number) {
        addNumber(hashTable, number);
    }
    inputFile.close();

    cout << "Хеш-таблица после добавления чисел:" << endl;
    printHashTable(hashTable);

    int searchValue;
    cout << "Введите число для поиска в хеш-таблице: ";
    cin >> searchValue;

    if (searchNumber(hashTable, searchValue)) {
        cout << "Число " << searchValue << " найдено в хеш-таблице." << endl;
    }
    else {
        cout << "Число " << searchValue << " не найдено в хеш-таблице." << endl;
    }

    return 0;
}
