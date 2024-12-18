#include"List.h"
#include<Windows.h>

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int choice;
    Object L1 = Create();
    do {
        std::cout << "Выберитевариант: " << std::endl;
        std::cout << "1. Добавить государство" << std::endl;
        std::cout << "2. Вывести список государств" << std::endl;
        std::cout << "3. Найти государство" << std::endl;
        std::cout << "4. Удалить государство" << std::endl;
        std::cout << "5. Очистить список государств" << std::endl;
        std::cout << "6. Выйти" << std::endl;
        std::cin >> choice;

        switch (choice) {
        case 1: {
            char Name[50];
            char Capital[50];
            int Population;
            double Area;
            char PresidentLastName[50];

            std::cout << "Название: ";
            std::cin >> Name;
            std::cout << "Столица: ";
            std::cin >> Capital;
            std::cout << "Население: ";
            std::cin >> Population;
            std::cout << "Площадь: ";
            std::cin >> Area;
            std::cout << "Фамилияпрезидента: ";
            std::cin >> PresidentLastName;

            L1.Insert(Name, Capital, Population, Area, PresidentLastName);
            break;
        }
        case 2: {
            L1.PrintList();
            break;
        }
        case 3: {
            char name[50];
            std::cout << "Введите название государства: ";
            std::cin >> name;
            Element* e = L1.Search(name);
            if (e == nullptr) {
                std::cout << "Государствоненайдено" << std::endl;
            }
            else {
                std::cout << "Найденогосударство:" << std::endl;
                std::cout << "Название: " << e->Data.Name << std::endl;
                std::cout << "Столица: " << e->Data.Capital << std::endl;
                std::cout << "Население: " << e->Data.Population << std::endl;
                std::cout << "Площадь: " << e->Data.Area << " км^2" << std::endl;
                std::cout << "Президент: " << e->Data.PresidentLastName << std::endl;
            }
            break;
        }
        case 4: {
            char name[50];
            std::cout << "Введите название государства для удаления: ";
            std::cin >> name;
            bool rc = L1.Delete(name);
            if (rc) {
                std::cout << "Государство удалено" << std::endl;
            }
            else {
                std::cout << "Государство не найдено или не удалено" << std::endl;
            }
            break;
        }
        case 5: {
            if (L1.DeleteList()) {
                std::cout << "Списокгосударствочищен" << std::endl;
            }
            else {
                std::cout << "Ошибка при очистке списка" << std::endl;
            }
            break;
        }
        default:
            break;
        }
    } while (choice != 6);

    return 0;
}
