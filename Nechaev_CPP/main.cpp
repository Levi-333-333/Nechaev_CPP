#include <iostream>
#include <vector>
#include <stdexcept>
#include <ctime>
#include <cstdlib>
#include <string>

struct BrokenVendor : public std::exception {
    const char* what() const noexcept override {
        return "Автомат взорвался...";
    }
};

int main()
{
    setlocale(LC_ALL, "Ru");

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    const std::vector<std::string> items = { "сода", "боярышник", "кола" };
    const std::vector<double> rates = { 2.5, 2.0, 3.0 };

    try
    {
        double inserted = 0.0;
        int id = 0;

        std::cout << "Вендинг" << std::endl;
        for (size_t i = 0; i < items.size(); ++i)
        {
            std::cout << (i + 1) << ". " << items[i] << " (" << rates[i] << ")" << std::endl;
        }
        std::cout << std::endl;

        std::cout << "Внесите сумму: ";
        if (!(std::cin >> inserted))
        {
            throw std::invalid_argument("Неверный формат денег");
        }

        std::cout << "Введите номер напитка: ";
        if (!(std::cin >> id))
        {
            throw std::invalid_argument("Неверный ввод выбора");
        }

        if (id < 1 || id > static_cast<int>(items.size()))
        {
            throw std::out_of_range("Такого пункта нет в меню");
        }

        if (std::rand() % 5 == 0)
        {
            throw BrokenVendor();
        }

        double price = rates[id - 1];
        if (inserted < price)
        {
            throw std::runtime_error("Недостаточно средств");
        }

        std::cout << "Вы получили: " << items[id - 1] << '\n';
        std::cout << "Сдача: " << (inserted - price) << '\n';
    }
    catch (const std::invalid_argument& ex)
    {
        std::cout << "Ошибка ввода: " << ex.what() << '\n';
    }
    catch (const std::out_of_range& ex)
    {
        std::cout << "Некорректный выбор: " << ex.what() << '\n';
    }
    catch (const BrokenVendor& ex)
    {
        std::cout << "Аппарат сломан: " << ex.what() << '\n';
    }
    catch (const std::runtime_error& ex) \
    {
        std::cout << "Ошибка покупки: " << ex.what() << '\n';
    }
    catch (...)
    {
        std::cout << "Автомат сошел с ума...\n";
    }

    return 0;
}