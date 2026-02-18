#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std::chrono_literals;

std::mutex mainMutex;
std::vector<std::exception_ptr> exceptionsArray;

// Функция выкидывает исключение
void ThrowExeption()
{
    throw std::exception("Пайтон.");
}

// Функция, которая обрабатывает исключения паралельно
void ThreadTryCatch() 
{
    std::this_thread::sleep_for(3000ms);
    try
    {
        ThrowExeption();
    }
    catch (const std::exception&)
    {
        std::lock_guard<std::mutex> lock(mainMutex);
        exceptionsArray.push_back(std::current_exception());
    }
}

int main() 
{
    setlocale(LC_ALL, "Ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::thread thr(ThreadTryCatch);
    thr.join();
    
    //std::this_thread::sleep_for(2000ms);

    for (auto& exception : exceptionsArray)
    {
        try
        {
            if (exception != nullptr)
            {
                std::rethrow_exception(exception);
            }
        }
        catch (const std::exception& mutexException)
        {
            std::cout << "Исключение поймано: " << mutexException.what() << std::endl;
        }
    }

    system("pause");
}

// Я провёл эксперименты с усыплением потоков. По итогу экспериментов выяснилось, что эти потоки работают поочерёдно и ждут выполнения друг друга. Если заставить поток main ждать 2 секунды, а потом поток с функцией ThreadTryCatch 3 секунды, то программа будет работать 5 секунд. Вызов join блокирует вызывающий поток до тех пор пока функция потока не выполнит свою работу (из конспекта прошлой пары).