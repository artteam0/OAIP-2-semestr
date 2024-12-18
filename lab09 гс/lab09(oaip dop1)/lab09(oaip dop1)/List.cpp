#include"List.h"

// ���������� ������������ �������� ������
Element::Element(Element* prev, constchar* name, constchar* capital, intpopulation, doublearea, constchar* presidentLastName, Element* next)
    : Prev(prev), Next(next) {
    strcpy_s(Data.Name, name);
    strcpy_s(Data.Capital, capital);
    Data.Population = population;
    Data.Area = area;
    strcpy_s(Data.PresidentLastName, presidentLastName);
}

// ����� ��������� ��������� �� ��������� �������
Element* Element::GetNext() {
    return Next;
}

// ����� ��������� ��������� �� ���������� �������
Element* Element::GetPrev() {
    return Prev;
}

// ����������� ������� ���������� �������
Object::Object() {
    Head = nullptr;
}

// ���������� ������� ���������� �������
Object::~Object() {
    DeleteList();
}

// ����� ��������� ��������� �� ������ ������� ������
Element* Object::GetFirst() {
    return Head;
}

// ����� ��������� ��������� �� ��������� ������� ������
Element* Object::GetLast() {
    Element* e = Head;
    Element* rc = e;
    while (e != nullptr) {
        rc = e;
        e = e->GetNext();
    }
    return rc;
}

// ����� ������� ������ �������� � ������ ������
boolObject::Insert(constchar* name, constchar* capital, intpopulation, doublearea, constchar* presidentLastName) {
    if (Head == nullptr) {
        Head = newElement(nullptr, name, capital, population, area, presidentLastName, nullptr);
    }
    else {
        Head = (Head->Prev = newElement(nullptr, name, capital, population, area, presidentLastName, Head));
    }
    returntrue;
}

// ����� ������ �������� �� �������� �����������
Element* Object::Search(constchar* name) {
    Element* rc = Head;
    while (rc != nullptr && strcmp(rc->Data.Name, name) != 0) {
        rc = rc->Next;
    }
    return rc;
}

// �����������������������������
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

// ����� �������� �������� �� �������� �����������
boolObject::Delete(constchar* name) {
    return Delete(Search(name));
}

// ����� �������� ���� ��������� ������
boolObject::DeleteList() {
    while (Head != nullptr) {
        Element* p = Head;
        Head = Head->Next;
        delete p;
    }
    returntrue;
}

// ����� ������ ������ ���������� � �������
voidObject::PrintList() {
    Element* e = Head;
    while (e != nullptr) {
        std::cout << "��������: " << e->Data.Name << std::endl;
        std::cout << "�������: " << e->Data.Capital << std::endl;
        std::cout << "���������: " << e->Data.Population << std::endl;
        std::cout << "�������: " << e->Data.Area << " ��^2" << std::endl;
        std::cout << "���������: " << e->Data.PresidentLastName << std::endl;
        std::cout << "--------------------------" << std::endl;
        e = e->GetNext();
    }
}

// ������� �������� ������� ���������� ������� ����������
Object Create() {
    returnObject();
}
