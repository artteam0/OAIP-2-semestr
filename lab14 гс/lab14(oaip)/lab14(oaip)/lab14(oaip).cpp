#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <chrono>

using namespace std;
#define INT_MAX 32767

struct Notebook {
    int key;               // Цена
    string full_name;      // Название товара
};

// Функция хеширования
int hashFunction(int key, int size) {
    return key % size;     // Возвращает индекс на основе ключа
}

// Добавление нового элемента в хеш-таблицу
void Add(vector<list<Notebook>>& notebookArray, int key, string& full_name) {
    int ind = hashFunction(key, notebookArray.size());
    notebookArray[ind].push_back({ key, full_name });
}

// Отображение содержимого хеш-таблицы
void Display(vector<list<Notebook>>& notebookArray) {
    cout << "Price-list" << endl;
    for (int i = 0; i < notebookArray.size(); ++i) {
        cout << "Element " << i << ": ";
        for (auto& element : notebookArray[i]) {
            cout << "Price: " << element.key << ". Product: " << element.full_name << " ";
        }
        cout << endl;
    }
}

// Удаление элемента из хеш-таблицы по ключу
void Del(vector<list<Notebook>>& notebookArray, int key) {
    int ind = hashFunction(key, notebookArray.size());
    for (auto pointer = notebookArray[ind].begin(); pointer != notebookArray[ind].end(); ++pointer) {
        if (pointer->key == key) {
            notebookArray[ind].erase(pointer);
            return;
        }
    }
}

// Поиск элемента в хеш-таблице по ключу
void Search(vector<list<Notebook>>& notebookArray, int key) {
    int ind = hashFunction(key, notebookArray.size());
    for (auto& element : notebookArray[ind]) {
        if (element.key == key) {
            cout << "Price: " << element.key << ". Product: " << element.full_name << endl;
            return;
        }
    }
    cout << "Price " << key << " not found." << endl;
}

int main() {
    int choice;
    int size;
    cout << "Enter size: ";   // Запрос размера хеш-таблицы
    cin >> size;
    vector<list<Notebook>> notebookArray(size);

    auto start_time = chrono::steady_clock::now();  // Время начала поиска
    auto end_time = chrono::steady_clock::now();    // Время окончания поиска

    for (;;) {
        cout << "1. Add" << endl;
        cout << "2. Display" << endl;
        cout << "3. Del" << endl;
        cout << "4. Search" << endl;
        cout << "5. Exit" << endl;
        cin >> choice;

        switch (choice) {
        case 1: {
            int key;
            string full_name;
            cout << "Price: "; // Запрос цены товара
            cin >> key;
            cout << "Product: "; // Запрос названия товара
            cin.ignore();
            getline(cin, full_name);
            Add(notebookArray, key, full_name); // Добавление товара
            break;
        }
        case 2:
            Display(notebookArray); // Отображение всех товаров
            break;
        case 3: {
            int key;
            cout << "Price to del: "; // Запрос цены товара для удаления
            cin >> key;
            Del(notebookArray, key); // Удаление товара
            break;
        }
        case 4: {
            int key;
            cout << "Price to search: "; // Запрос цены товара для поиска
            cin >> key;
            start_time = chrono::steady_clock::now(); // Время начала поиска
            Search(notebookArray, key); // Поиск товара
            end_time = chrono::steady_clock::now(); // Время окончания поиска
            cout << "Time of searching: " << chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count() << " nanoseconds" << endl;
            break;
        }
        case 5:
            return 0; // Завершение программы
        default:
            cout << "Error." << endl; // Сообщение об ошибке
            break;
        }
    }

    return 0;
}
