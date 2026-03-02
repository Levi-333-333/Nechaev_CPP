#include <iostream>
#include <string>

class Logger
{
public:
    // ƒл€ того что бы обратитьс€ к единственному экземпл€ру класса используетс€ специальна€ статическа€ Get-функци€
    static Logger& GetInstance()
    {
        static Logger instance; // Ёкземпл€р класса
        return instance;
    }

    Logger(const Logger&) = delete;

    Logger& operator=(const Logger&) = delete;

    void Log(std::string message)
    {
        std::cout << "LOG: " << message << std::endl;
    }
private:
    static inline unsigned int counter = 0;
    Logger()
    {
        counter++;
        std::cout << "Ёкземпл€р Ћоггера был успешно создан! " << counter << std::endl;
    }

    ~Logger()
    {
        counter--;
        std::cout << "Ёкземпл€р Ћоггера был успешно разобран! " << counter << std::endl;
    }
};