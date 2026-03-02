#pragma once

#include <string>
#include <iostream>

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

    explicit operator int() const { return  counter; }
    Person& operator--(); // Префиксный декримент
    Person& operator++(); // Префиксный инкримент 
    Person operator--(int); // Постфиксный декримент
    Person operator++(int); // Постфиксный инкримент
    Person& operator+=(const Person& other); // Присвоение со сложением объекта класса
    Person& operator+=(const int value); // Присвоение со сложением целого числа
    Person& operator+=(const string value); // Присвоение со сложением имени
    Person& operator-=(const Person& other); // Присвоение с вычитанием объекта класса
    Person& operator-=(const int value); // Присвоение с вычитанием целого числа
    Person operator+(const Person& other) const; // Оператор сложения с другим классом
    Person operator-(const Person& other) const; // Оператор вычитания с другим классом
    bool operator==(const Person& other) const; // Оператор сравнения равенства с другим классом
    bool operator!=(const Person& other) const; // Оператор сравнения неравенства с другим классом
    bool operator>(const Person& other) const; // Оператор сравнения больше с другим классом
    bool operator<(const Person& other) const; // Оператор сравнения меньше с другим классом
    bool operator>=(const Person& other) const; // Оператор сравнения больше или равенства с другим классом
    bool operator<=(const Person& other) const; // Оператор сравнения меньше или равенства с другим классом
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
ostream& operator<<(ostream& stream, const Person PersonTemplateTypenames& person);

PersonTemplate
class Student : public PersonPersonTemplateTypenames
{
public:
    void Study();
    void MissClass();
private:
    void PassExamAutomatically();
protected:
    void SetEducationLevel(string _educationLevel);
};

PersonTemplate
class CollegeStudent : Student PersonTemplateTypenames
{
    void SetCollegeEducationLevel();
};

PersonTemplate
class UniversetyStudent : Student PersonTemplateTypenames
{
    void SetUniversetyEducationLevel();
};