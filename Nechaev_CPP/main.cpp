#include <string>
#include <iostream>
#include <list>

class IObserver // интерфейс для наблюдателя
{
public:
    virtual ~IObserver() {};
    virtual void Update(const std::string& message) = 0; // Функция, обновляющая поступающую информацию наблюдаемому
};

class ISubject // интерфейс для наблюдамого
{
public:
    virtual ~ISubject() {};
    virtual void Subscribe(IObserver* observer) = 0; // Функция, подписывающая на наблюдателя
    virtual void UnSubscribe(IObserver* observer) = 0; // Функция, отписывающая от наблюдателя
    virtual void Notify() = 0; // Уведомить наблюдаемого
};

class Subject : public ISubject
{
public:
    ~Subject()
    {
        std::cout << "Наблюдаемый был очищен в памяти" << std::endl;
    }

    // Методы управления подпиской
    void Subscribe(IObserver* observer) override
    {
        observerList.push_back(observer);
    }

    void UnSubscribe(IObserver* observer) override
    {
        observerList.remove(observer);
    }

    void Notify() override
    {
        // Для того, чтобы определить свою единицу перечисления для такого типа данных, как список, создается итератор, а внего задается начальный объект списка
        std::list<IObserver*>::iterator iterator = observerList.begin();
        std::cout << "За объектом наблюдает " << observerList.size() << " наблюдателей" << std::endl;
        // Пока значение итератора не примет вид последнего объекта из списка
        while (iterator != observerList.end())
        {
            // Вызываем функцию Update у текущего перечисляемого наблюдателя
            (*iterator)->Update(message);
            ++iterator; // У объекта итератора перегружен оператор ++
        }
    }

    // Функция, при вызове которой задается новое сообщение (новое состояние) для наблюдаемого и происходит автоматическое уведомление наблюдателя через функцию Notify()
    void CreateMessage(std::string message)
    {
        this->message = message;
        Notify();
    }

    std::list<IObserver*> GetObserverList()
    {
        return observerList;
    }
private:
    std::list<IObserver*> observerList;
    std::string message;
};

class Observer : public IObserver
{
public:
    // Конструктор
    Observer(Subject& _subject, std::string _name, int _answer) : subject(_subject), name(_name), answer(_answer)
    {
        // Наблюдаемый в классе наблюдателя подписывается на второго сразу же в конструкторе
        this->subject.Subscribe(this);
        couterObservers++;
        std::cout << "Наблюдатель " << couterObservers << " проинициализирован" << std::endl;
    }
    // Деструктор
    ~Observer()
    {
        couterObservers--;
        std::cout << "Наблюдатель " << name << " был очищен" << std::endl;
    }
    // Переопределенная Update
    void Update(const std::string& message) override
    {
        this->message = message;
        // Наблюдатель должен реагировать на поступаемое изменение
        std::cout << "У наблюдателя " << name << " появилось новое сообщение от наблюдаемого: " << this->message << std::endl;
    }
    // Вспомогательная функция по управлению количеством наблюдаемых
    void UnsubscribeSubject()
    {
        subject.UnSubscribe(this);
        std::cout << "Наблюдаемый " << name << " был отписан от наблюдателя!" << std::endl;
    }

    int GetAnswer()
    {
        return answer;
    }
private:
    Subject& subject;
    std::string message;
    static inline unsigned int couterObservers;
    std::string name;
    int answer;
};

int main()
{
    setlocale(LC_ALL, "Ru");

    Subject* subjectLeon = new Subject;
    Observer* observerGreka = new Observer(*subjectLeon, "Greka", 3);
    Observer* observerRak = new Observer(*subjectLeon, "Rak", 2);
    Observer* observerReka = new Observer(*subjectLeon, "Reka", -2);

    int userAnswer = 0;

    subjectLeon->CreateMessage("РЕШИТЬ УРАВНЕНИЕ: (x + 5) - 3 = 0");
    std::cin >> userAnswer;
    if (!(userAnswer == observerReka->GetAnswer())) observerReka->UnsubscribeSubject();
    userAnswer = 0;

    subjectLeon->CreateMessage("РЕШИТЬ УРАВНЕНИЕ: x^2 - 4x + 4 = 0");
    std::cin >> userAnswer;
    if (!(userAnswer == observerRak->GetAnswer())) observerRak->UnsubscribeSubject();
    userAnswer = 0;

    subjectLeon->CreateMessage("РЕШИТЬ УРАВНЕНИЕ: x^2 - 6x + 9 = 0");
    std::cin >> userAnswer;
    if (!(userAnswer == observerGreka->GetAnswer())) observerGreka->UnsubscribeSubject();
    userAnswer = 0;

    if (subjectLeon->GetObserverList().empty())
    {
        std::cout << "Ты слишком тупой для этого дерьма. Ты под наблюдением." << std::endl;
        Observer* observerTwichModer = new Observer(*subjectLeon, "Twich moderator", NULL);
        observerTwichModer->Update("Теперь я слежу за тобой.");

        delete observerTwichModer;
    }

    delete observerGreka;
    delete observerRak;
    delete observerReka;
    delete subjectLeon;

    return 0;
}