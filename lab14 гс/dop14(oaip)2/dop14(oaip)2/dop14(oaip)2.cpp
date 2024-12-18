#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<cctype>

using namespace std;

struct Entry{
    string word;
    string help = "HELP";
};

int hashFunction(const string& word) {
    return tolower(word[0]) - 'a'; // Простейшая хеш-функция, использующая первую букву слова
}

void addWord(vector<list<Entry>>& hashTable, const string& word) {
    int index = hashFunction(word);
    hashTable[index].push_back({ word });
}

int main() {
    setlocale(LC_CTYPE, "rus");
    vector<list<Entry>>hashTable(26); // 26 корзин для хранения слов от 'a' до 'z'

    // Заполнение хеш-таблицы зарезервированными словами и подсказками
    addWord(hashTable, "auto");
    addWord(hashTable, "break");
    addWord(hashTable, "case");
    // Добавьте другие зарезервированные слова по аналогии

    string input_word;
    cout << "Введите слово (для выхода введите 'exit'): ";
    while (cin >> input_word) {
        if (input_word == "exit") {
            break;
        }

        int index = hashFunction(input_word);
        bool found = false;
        for (const auto& entry : hashTable[index]) {
            if (entry.word == input_word) {
                cout << "Подсказка для '" << input_word << "': " << entry.help << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Слово '" << input_word << "' не найдено. Добавьте подсказку: ";
            string new_help;
            cin >> new_help;
            addWord(hashTable, input_word);
            cout << "Слово '" << input_word << "' добавлено в таблицу с подсказкой '" << new_help << "'" << endl;
        }

        cout << "Введите следующее слово (для выхода введите 'exit'): ";
    }

    return 0;
}
