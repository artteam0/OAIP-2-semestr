#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<cctype>

using namespace std;

int main() {
    setlocale(LC_CTYPE, "rus");
    string input_string;
    cout << "Введите строку: ";
    getline(cin, input_string);

    vector<list<pair<char, int>>>hash_table(26); // Используем 26 корзин для хранения букв от 'a' до 'z'

    // Заполнение хеш-таблицы с подсчетом количества вхождений каждой буквы
    for (char c : input_string) {
        if (isalpha(c)) {
            char lowercase_c = tolower(c);
            int index = lowercase_c - 'a'; // Вычисляем индекс корзины
            bool found = false;
            for (auto& pair : hash_table[index]) {
                if (pair.first == lowercase_c) {
                    pair.second++;
                    found = true;
                    break;
                }
            }
            if (!found) {
                hash_table[index].push_back(make_pair(lowercase_c, 1));
            }
        }
    }

    // Вывод хеш-таблицы
    cout << "Хеш-таблица (буква : количество вхождений):" << endl;
    for (int i = 0; i < 26; ++i) {
        for (const auto& pair : hash_table[i]) {
            cout << pair.first << " : " << pair.second << endl;
        }
    }

    // Поиск буквы в хеш-таблице
    char search_letter;
    cout << "Введите букву для поиска: ";
    cin >> search_letter;
    search_letter = tolower(search_letter);
    int index = search_letter - 'a';
    bool found = false;
    for (const auto& pair : hash_table[index]) {
        if (pair.first == search_letter) {
            cout << "Буква '" << search_letter << "' найдена. Количество вхождений: " << pair.second << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Буква '" << search_letter << "' не найдена." << endl;
    }

    return 0;
}
