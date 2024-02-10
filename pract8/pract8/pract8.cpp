// pract8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

enum class PhoneType { Personal, Office };


struct Phone {
    
    std::string number;
    PhoneType type;
    union {
        char ownerName[50];
        struct {
            char institutionName[50];
            char departmentName[50];
        };
    } details;
  //конструкторы
    Phone(const std::string& num, PhoneType t, const char* name)  //для личного телеофона
        : number(num), type(t) {
        strncpy_s(details.ownerName, name, sizeof(details.ownerName));
    }

    Phone(const std::string& num, PhoneType t, const char* inst, const char* dept)  //для служебного телефона
        : number(num), type(t) {
        strncpy_s(details.institutionName, inst, sizeof(details.institutionName));
        strncpy_s(details.departmentName, dept, sizeof(details.departmentName));
    }
};
//сравнение двух номеров при сортировке
bool compareByNumber(const Phone& a, const Phone& b) {
    return a.number < b.number;
}

int main() {
    setlocale(LC_ALL, "RUS");
    std::vector<Phone> phoneBook = {
        Phone("89002006578", PhoneType::Personal, "Максимов М.К"),
        Phone("89435654345", PhoneType::Office, "Школа", "Гимназия"),
        Phone("89546545433", PhoneType::Office, "Школа", "Лицей"),
        Phone("89543543346", PhoneType::Office, "Колледж", "ПТУ")
    };

    std::string targetInstitution = "Школа"; //определяем для какого учреждения искать нмоера
    std::vector<Phone> targetPhones;

    for (const Phone phone : phoneBook) {
        if (phone.type == PhoneType::Office && strcmp(phone.details.institutionName, targetInstitution.c_str()) == 0) {
            targetPhones.push_back(phone);
        }
    }

    std::sort(targetPhones.begin(), targetPhones.end(), compareByNumber);

    std::cout << "Телефоны учреждения  - " << targetInstitution  << std::endl;
    for (const Phone phone : targetPhones) {
        std::cout << "Номер: " << phone.number << ", Подразделение: " << phone.details.departmentName << std::endl;
    }

    return 0;
}















// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
