#include <iostream>

class Light
{
public:
    void TurnOn()
    {
        std::cout << "Лампочка включена" << std::endl;
    }
    void TurnOff()
    {
        std::cout << "Лампочка выключна" << std::endl;
    }
private:
    std::string model;
};

class Thermostat
{
public:
    void TurnOn()
    {
        std::cout << "Термостат включен" << std::endl;
    }
    void TurnOff()
    {
        std::cout << "Термостат выключно" << std::endl;
    }
private:
    std::string model;
};

class Radio
{
public:
    void TurnOn()
    {
        std::cout << "Радио включен" << std::endl;
    }
    void TurnOff()
    {
        std::cout << "Радио выключно" << std::endl;
    }
private:
    std::string model;
};

class SmartHome
{
public:
    SmartHome(Light* light, Thermostat* thermostat, Radio* radio)
    {
        this->light = light;
        this->thermostat = thermostat;
        this->radio = radio;
    }
    void TurnOn()
    {
        light->TurnOn();
        thermostat->TurnOn();
        radio->TurnOn();
    }
    void TurnOff()
    {
        light->TurnOff();
        thermostat->TurnOff();
        radio->TurnOff();
    }
private:
    Light* light;
    Thermostat* thermostat;
    Radio* radio;
};

int main()
{
    setlocale(LC_ALL, "Ru");

    SmartHome sillyHome(new Light, new Thermostat, new Radio);

    sillyHome.TurnOn();
    sillyHome.TurnOff();
}