#include"List.h"

// Реализация конструктора элемента списка
Element::Element(Element* prev, constchar* name, constchar* capital, intpopulation, doublearea, constchar* presidentLastName, Element* next)
    : Prev(prev), Next(next) {
    strcpy_s(Data.Name, name);
    strcpy_s(Data.Capital, capital);
    Data.Population = population;
    Data.Area = area;
    strcpy_s(Data.PresidentLastName, presidentLastName);
}

// Метод получения указателя на следующий элемент
Element* Element::GetNext() {
    return Next;
}

// Метод получения указателя на предыдущий элемент
Element* Element::GetPrev() {
    return Prev;
}

// Конструктор объекта управления списком
Object::Object() {
    Head = nullptr;
}

// Деструктор объекта управления списком
Object::~Object() {
    DeleteList();
}

// Метод получения указателя на первый элемент списка
Element* Object::GetFirst() {
    return Head;
}

// Метод получения указателя на последний элемент списка
Element* Object::GetLast() {
    Element* e = Head;
    Element* rc = e;
    while (e != nullptr) {
        rc = e;
        e = e->GetNext();
    }
    return rc;
}

// Метод вставки нового элемента в начало списка
boolObject::Insert(constchar* name, constchar* capital, intpopulation, doublearea, constchar* presidentLastName) {
    if (Head == nullptr) {
        Head = newElement(nullptr, name, capital, population, area, presidentLastName, nullptr);
    }
    else {
        Head = (Head->Prev = newElement(nullptr, name, capital, population, area, presidentLastName, Head));
    }
    returntrue;
}

// Метод поиска элемента по названию государства
Element* Object::Search(constchar* name) {
    Element* rc = Head;
    while (rc != nullptr && strcmp(rc->Data.Name, name) != 0) {
        rc = rc->Next;
    }
    return rc;
}

// Методудаленияэлементаизсписка
boolObject::Delete(Element* e) {
    if (e != nullptr) {
        if (e->Next != nullptr) {
            e->Next->Prev = e->Prev;
        }
        if (e->Prev != nullptr) {
            e->Prev->Next = e->Next;
        }
        else {
            Head = e->Next;
        }
        deletee;
        returntrue;
    }
    returnfalse;
}

// Метод удаления элемента по названию государства
boolObject::Delete(constchar* name) {
    return Delete(Search(name));
}

// Метод удаления всех элементов списка
boolObject::DeleteList() {
    while (Head != nullptr) {
        Element* p = Head;
        Head = Head->Next;
        delete p;
    }
    returntrue;
}

// Метод вывода списка государств в консоль
voidObject::PrintList() {
    Element* e = Head;
    while (e != nullptr) {
        std::cout << "Название: " << e->Data.Name << std::endl;
        std::cout << "Столица: " << e->Data.Capital << std::endl;
        std::cout << "Население: " << e->Data.Population << std::endl;
        std::cout << "Площадь: " << e->Data.Area << " км^2" << std::endl;
        std::cout << "Президент: " << e->Data.PresidentLastName << std::endl;
        std::cout << "--------------------------" << std::endl;
        e = e->GetNext();
    }
}

// Функция создания объекта управления списком государств
Object Create() {
    returnObject();
}
