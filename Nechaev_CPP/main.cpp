#include <iostream>
#include <Windows.h>

#define PersonTemplate template<typename Tid, typename Tlogin, typename Tpassword, typename TbankId, typename TsecretWord>
#define PersonTemplateTypenames <Tid, Tlogin, Tpassword, TbankId, TsecretWord>

using namespace std;

PersonTemplate
class Person
{
public:
    string name;
    unsigned int age;
    unsigned int* agePointer;
    TbankId bankId;
    const static inline unsigned int MAX_AGE = 120;
    
    Person(Tid _id, string _name, int _age, string _passportData, double _balance, TbankId _bankId, TsecretWord _secretWord);
    void PrintInfo();
    void SetPassportData(string _passportData);
    string GetPassportData() const;
    unsigned int GetCounter();
    unsigned int GetMIN_AGE();
    unsigned int GetFingerCounter();
    Tid GetId() const;
    void Wisdraw();
    void ChangeBank();

    explicit operator int() const { return counter; }

    Person& operator--() // Префиксный декримент
    {
        *agePointer -= 1;
        return *this;
    }
    Person& operator++() // Префиксный инкримент 
    {
        *agePointer += 1;
        return *this;
    }
    Person operator--(int) // Постфиксный декримент
    {
        Person copy{ *this };
        --(*this);
        if (this->age < 0) this->age = 0;
        return copy;
    } 
    Person operator++(int) // Постфиксный инкримент
    {
        Person copy{ *this };
        ++(*this);
        return copy;
    }
    
    Person& operator+=(const Person& other) // Присвоение со сложением объекта класса
    {
        age += other.age;
        return *this;
    }
    Person& operator+=(const int value) // Присвоение со сложением целого числа
    {
        age += value;
        return *this;
    }
    Person& operator+=(const string value) // Присвоение со сложением имени
    {
        name += " " + value;
        return *this;
    }

    Person& operator-=(const Person& other) // Присвоение с вычитанием объекта класса
    {
        age -= other.age;
        if (this->age < 0) this->age = 0;
        return *this;
    }
    Person& operator-=(const int value) // Присвоение с вычитанием целого числа
    {
        age -= value;
        if (this->age < 0) this->age = 0;
        return *this;
    }

    Person operator+(const Person& other) const // Оператор сложения с другим классом
    {
        int temp = age + other.age;
        return Person{ name, temp, passportData };
    }
    Person operator-(const Person& other) const // Оператор вычитания с другим классом
    {
        int temp = age - other.age;
        if (temp < 0) temp = 0;
        return Person{ name, temp, passportData };
    }

    bool operator==(const Person& other) const // Оператор сравнения равенства с другим классом
    {
        if (name == other.name && age == other.age && GetPassportData() == other.GetPassportData()) return true;
        else return false;
    }
    bool operator!=(const Person& other) const // Оператор сравнения неравенства с другим классом
    {
        if (!(name == other.name && age == other.age && GetPassportData() == other.GetPassportData())) return true;
        else return false;
    }
    bool operator>(const Person& other) const // Оператор сравнения больше с другим классом
    {
        if (age > other.age) return true;
        else return false;
    }
    bool operator<(const Person& other) const // Оператор сравнения меньше с другим классом
    {
        if (age < other.age) return true;
        else return false;
    }
    bool operator>=(const Person& other) const // Оператор сравнения больше или равенства с другим классом
    {
        if (age >= other.age) return true;
        else return false;
    }
    bool operator<=(const Person& other) const // Оператор сравнения меньше или равенства с другим классом
    {
        if (age <= other.age) return true;
        else return false;
    } 
private:
    string passportData;
    Tlogin tanchikiLogin;
    Tpassword tanchikiPassword;
    double balance;
    TsecretWord secretWord;
    const static inline unsigned int MIN_AGE = 0;
protected:
    Tid id;
    string educationLevel;
    static inline unsigned int counter;
    static inline unsigned int fingerCounter;
};

PersonTemplate
ostream& operator<<(ostream& stream, const Person PersonTemplateTypenames& person)
{
    stream << ". Имя: " << person.name << ". Возраст: " << person.age << endl;
    return stream;
}

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

//template<typename Tid, typename Tlogin, typename Tpassword>
//class Student : public Person<Tid, Tlogin, Tpassword>
//{
//public:
//    void Study();
//    void MissClass();
//private:
//    void PassExamAutomatically();
//protected:
//    void SetEducationLevel(string _educationLevel);
//};
//
//template<typename Tid, typename Tlogin, typename Tpassword>
//void Student<Tid, Tlogin, Tpassword>::SetEducationLevel(string _educationLevel)
//{
//    educationLevel = _educationLevel;
//}
//
//template<typename Tid, typename Tlogin, typename Tpassword>
//class CollegeStudent : Student<Tid, Tlogin, Tpassword>
//{
//    void SetCollegeEducationLevel();
//};
//
//template<typename Tid, typename Tlogin, typename Tpassword>
//void CollegeStudent<Tid, Tlogin, Tpassword>::SetCollegeEducationLevel()
//{
//    SetEducationLevel<Tid, Tlogin, Tpassword>("Среднее проффесиональное");
//}
//
//template<typename Tid, typename Tlogin, typename Tpassword>
//class UniversetyStudent : Student<Tid, Tlogin, Tpassword>
//{
//    void SetUniversetyEducationLevel();
//};
//
//template<typename Tid, typename Tlogin, typename Tpassword>
//void UniversetyStudent<Tid, Tlogin, Tpassword>::SetUniversetyEducationLevel()
//{
//    SetEducationLevel<Tid, Tlogin, Tpassword>("Высшее");
//}

void main() 
{
    setlocale(LC_ALL, "Ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Person<string, string, string, string, string> chelovek1{ "brawl stars", "Leon", 17, "4444 666666", 0.91, "T-BankUser333", "абоба" };
    Person<int, string, string, string, int> chelovek2{ 0, "Zloy David V Mute.", 10, "0000 000000", 503.32, "Inoagent", 52 };
    Person<double, string, string, int, int> chelovek3{ 36.6, "alex shopkeeper", 18, "4444 666666", 2000.02, 33, 64 };
    
    chelovek1.PrintInfo();
    chelovek1.Wisdraw();
    chelovek1.PrintInfo();
    chelovek1.ChangeBank();
    chelovek1.PrintInfo();
}

// Практика:
// 3. Объявить в классе функцию смены банка и секретного слова, которая просит пользователя сначала ввести секретное слово/код от ынешнего банка, а затем задать новый банк и секретное слово/код