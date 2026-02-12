#include "Person.h"

PersonTemplate
Person PersonTemplateTypenames::Person(Tid _id, string _name, int _age, string _passportData, double _balance, TbankId _bankId, TsecretWord _secretWord)
{
    id = _id;

    if (_name == "Платон")
    {
        name = "Безымянный";
        cout << "Не подходящее имя" << endl;
    }
    else name = _name;

    if (_age > MAX_AGE) age = MAX_AGE;
    else if (_age < GetMIN_AGE()) age = GetMIN_AGE();
    else age = _age;

    passportData = _passportData;
    educationLevel = "Необразованный";

    agePointer = &age;

    counter++;
    fingerCounter += 20;

    cout << "В танчики играете, " << name << ", м? (1/0)" << endl;
    bool userInput;
    cin >> userInput;
    if (userInput)
    {
        cout << "Введите логин: ";
        cin >> tanchikiLogin;
        cout << endl << "Введите пароль: ";
        cin >> tanchikiPassword;
        cout << endl;
    }

    balance = _balance;
    bankId = _bankId;
    secretWord = _secretWord;
}

PersonTemplate
void Person PersonTemplateTypenames::PrintInfo()
{
    cout << "Имя: " << name << ". Возраст: " << age << endl;
    cout << "Серия и номер пасспорта: " << GetPassportData() << endl;
    cout << "====================" << endl;
    cout << "Танчики логин: " << tanchikiLogin << endl;
    cout << "Танчики пароль: " << tanchikiPassword << endl;
    cout << "====================" << endl;
    cout << "Банк: " << bankId << endl;
    cout << "Баланс: " << balance << endl;
}

PersonTemplate
void Person PersonTemplateTypenames::SetPassportData(string _passportData)
{
    if (_passportData.size() == 11) passportData = _passportData;
    else cout << "Значение неверно.";
}

PersonTemplate
string Person PersonTemplateTypenames::GetPassportData() const
{
    return passportData;
}

PersonTemplate
unsigned int Person PersonTemplateTypenames::GetCounter()
{
    return counter;
}

PersonTemplate
Tid Person PersonTemplateTypenames::GetId() const
{
    return id;
}

PersonTemplate
unsigned int Person PersonTemplateTypenames::GetMIN_AGE()
{
    return MIN_AGE;
}

PersonTemplate
unsigned int Person PersonTemplateTypenames::GetFingerCounter()
{
    return fingerCounter;
}

PersonTemplate
void Person PersonTemplateTypenames::Wisdraw()
{
    cout << "Какую сумму вы хотите списать?" << endl;
    double userInput;
    cin >> userInput;

    if (userInput > balance) cout << "У вас недостаточно средств!" << endl;
    else
    {
        cout << "Введите секретное слово: ";
        TsecretWord nestedUserInput;
        cin >> nestedUserInput;
        cout << endl;

        if (nestedUserInput == secretWord) balance -= userInput;
        else cout << "Введено неверное секретное слово!" << endl;
    }
}

PersonTemplate
void Person PersonTemplateTypenames::ChangeBank()
{
    cout << "Введите секретное слово для смены банка" << endl;
    TsecretWord userInput;
    cin >> userInput;

    if (!(userInput == secretWord)) cout << "Введено неверное секретное слово!" << endl;
    else
    {
        cout << "Введите банк, на который вы хотите перейти" << endl;
        cin >> bankId;

        cout << "Введите новое секретное слово: " << endl;
        cin >> secretWord;
    }
}

PersonTemplate
Person& Person PersonTemplateTypenames::operator--() // Префиксный декримент
{
    *agePointer -= 1;
    return *this;
}
PersonTemplate
Person& Person PersonTemplateTypenames::operator++()
{
    *agePointer += 1;
    return *this;
}
PersonTemplate
Person Person PersonTemplateTypenames::operator--(int) // Постфиксный декримент
{
    Person copy{ *this };
    --(*this);
    if (this->age < 0) this->age = 0;
    return copy;
}
PersonTemplate
Person Person PersonTemplateTypenames::operator++(int) // Постфиксный инкримент
{
    Person copy{ *this };
    ++(*this);
    return copy;
}
PersonTemplate
Person& Person PersonTemplateTypenames::operator+=(const Person& other) // Присвоение со сложением объекта класса
{
    age += other.age;
    return *this;
}
PersonTemplate
Person& Person PersonTemplateTypenames:: operator+=(const int value) // Присвоение со сложением целого числа
{
    age += value;
    return *this;
}
PersonTemplate
Person& Person PersonTemplateTypenames::operator+=(const string value) // Присвоение со сложением имени
{
    name += " " + value;
    return *this;
}
PersonTemplate
Person& Person PersonTemplateTypenames::operator-=(const Person& other) // Присвоение с вычитанием объекта класса
{
    age -= other.age;
    if (this->age < 0) this->age = 0;
    return *this;
}
PersonTemplate
Person& Person PersonTemplateTypenames::operator-=(const int value) // Присвоение с вычитанием целого числа
{
    age -= value;
    if (this->age < 0) this->age = 0;
    return *this;
}
PersonTemplate
Person Person PersonTemplateTypenames::operator+(const Person& other) const // Оператор сложения с другим классом
{
    int temp = age + other.age;
    return Person{ name, temp, passportData };
}
PersonTemplate
Person Person PersonTemplateTypenames::operator-(const Person& other) const // Оператор вычитания с другим классом
{
    int temp = age - other.age;
    if (temp < 0) temp = 0;
    return Person{ name, temp, passportData };
}
PersonTemplate
bool Person PersonTemplateTypenames::operator==(const Person& other) const // Оператор сравнения равенства с другим классом
{
    if (name == other.name && age == other.age && GetPassportData() == other.GetPassportData()) return true;
    else return false;
}
PersonTemplate
bool Person PersonTemplateTypenames::operator!=(const Person& other) const // Оператор сравнения неравенства с другим классом
{
    if (!(name == other.name && age == other.age && GetPassportData() == other.GetPassportData())) return true;
    else return false;
}
PersonTemplate
bool Person PersonTemplateTypenames::operator>(const Person& other) const // Оператор сравнения больше с другим классом
{
    if (age > other.age) return true;
    else return false;
}
PersonTemplate
bool Person PersonTemplateTypenames::operator<(const Person& other) const // Оператор сравнения меньше с другим классом
{
    if (age < other.age) return true;
    else return false;
}
PersonTemplate
bool Person PersonTemplateTypenames::operator>=(const Person& other) const // Оператор сравнения больше или равенства с другим классом
{
    if (age >= other.age) return true;
    else return false;
}
PersonTemplate
bool Person PersonTemplateTypenames::operator<=(const Person& other) const // Оператор сравнения меньше или равенства с другим классом
{
    if (age <= other.age) return true;
    else return false;
}

PersonTemplate
ostream& operator<<(ostream& stream, const Person PersonTemplateTypenames& person)
{
    stream << ". Имя: " << person.name << ". Возраст: " << person.age << endl;
    return stream;
}


PersonTemplate
void Student PersonTemplateTypenames::SetEducationLevel(string _educationLevel)
{
    educationLevel = _educationLevel;
}

PersonTemplate
void CollegeStudent PersonTemplateTypenames::SetCollegeEducationLevel()
{
    SetEducationLevel PersonTemplateTypenames("Среднее проффесиональное");
}

PersonTemplate
void UniversetyStudent PersonTemplateTypenames::SetUniversetyEducationLevel()
{
    SetEducationLevel PersonTemplateTypenames("Высшее");
}