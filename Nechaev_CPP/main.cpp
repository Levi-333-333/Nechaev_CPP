#include <iostream>
using namespace std;

class Person
{
public:
    string name;
    unsigned int age;
    unsigned int* agePointer;
    const static inline unsigned int MAX_AGE = 120;
    
    Person(string _name, int _age, string _passportData);
    void PrintInfo();
    void AgeUp();
    void SetPassportData(string _passportData);
    string GetPassportData() const;
    unsigned int GetCounter();
    unsigned int GetMIN_AGE();
    unsigned int GetFingerCounter();
    explicit operator int() const { return counter; }
    Person& operator--()
    {
        *agePointer -= 1;
        return *this;
    }
    Person& operator++()
    {
        *agePointer += 1;
        return *this;
    }
    // Практика 3.
    Person operator+(const Person& other) const
    {
        int temp = age + other.age;
        return Person{ name, temp, passportData };
    }
    // Практика 4.
    Person operator-(const Person& other) const
    {
        int temp = age - other.age;
        if (temp < 0) temp = 0;
        return Person{ name, temp, passportData };
    }
    bool operator==(const Person& other) const
    {
        if (name == other.name && age == other.age && GetPassportData() == other.GetPassportData()) return true;
        else return false;
    }
    bool operator>(const Person& other) const
    {
        if (age > other.age) return true;
        else return false;
    }
    // Практика 2.
    bool operator<(const Person& other) const
    {
        if (age < other.age) return true;
        else return false;
    }
    bool operator>=(const Person& other) const
    {
        if (age >= other.age) return true;
        else return false;
    }
    bool operator<=(const Person& other) const
    {
        if (age <= other.age) return true;
        else return false;
    }
    // Практика 1.
    bool operator!=(const Person& other) const
    {
        if (!(name == other.name && age == other.age && GetPassportData() == other.GetPassportData())) return true;
        else return false;
    }
private:
    string passportData;
    const static inline unsigned int MIN_AGE = 0;
protected:
    string educationLevel;
    static inline unsigned int counter; // inline - необязательное ключевое слово, которое инициализирует переменную нулём (0). Работает только со static полями.
    static inline unsigned int fingerCounter;
};

ostream& operator<<(ostream& stream, const Person& person)
{
    stream << "Имя: " << person.name << ". Возраст: " << person.age << endl;
    return stream;
}

Person::Person(string _name, int _age, string _passportData)
{
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
}

void Person::PrintInfo()
{
    cout << "Имя: " << name << ". Возраст: " << age << endl;
}

void Person::AgeUp()
{
    age++;
}

void Person::SetPassportData(string _passportData)
{
    if (_passportData.size() == 11) passportData = _passportData;
    else cout << "Значение неверно."; 
}

string Person::GetPassportData() const
{
    return passportData;
}

unsigned int Person::GetCounter()
{
    return counter;
}

unsigned int Person::GetMIN_AGE()
{
    return MIN_AGE;
}

unsigned int Person::GetFingerCounter()
{
    return fingerCounter;
}

class Student : public Person
{
public:
    void Study();
    void MissClass();
private:
    void PassExamAutomatically();
protected:
    void SetEducationLevel(string _educationLevel);
};

void Student::SetEducationLevel(string _educationLevel)
{
    educationLevel = _educationLevel;
}

class CollegeStudent : Student
{
    void SetCollegeEducationLevel();
};

void CollegeStudent::SetCollegeEducationLevel()
{
    SetEducationLevel("Среднее проффесиональное");
}

class UniversetyStudent : Student
{
    void SetUniversetyEducationLevel();
};

void UniversetyStudent::SetUniversetyEducationLevel()
{
    SetEducationLevel("Высшее");
}

void main() 
{
    setlocale(LC_ALL, "Ru");

    Person chelovek1("Leon", 17, "4444 666666");
    Person chelovek2("Zloy David V Mute.", 17, "0000 000000");
    Person chelovek3("alex shopkeeper", 18, "4444 666666");

    cout << chelovek1 << chelovek2 << endl;

    cout << (chelovek1 != chelovek2) << endl;
    cout << (chelovek1 < chelovek2) << endl;
    cout << (chelovek1 + chelovek2);
    cout << (++chelovek1) << endl;
    
    cout << chelovek1;
}