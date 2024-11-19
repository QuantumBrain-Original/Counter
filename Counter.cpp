#include <iostream>
#include <string>
#include <Windows.h>

class Counter
{
    int digit_counter;

    public:
        void add()
        {
            digit_counter++;
        }

        void subtract()
        {
            digit_counter--;
        }

        void print_current()
        {
            std::cout << digit_counter << std::endl;
        }

        Counter()
        {
            digit_counter = 1;
        }

        Counter(int a)
        {
            digit_counter = a;
        }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    Counter *Count = nullptr;
    std::string answer = "";

    std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";

    std::cin >> answer;
    if (answer == "да" || answer == "Да" || answer == "ДА")
    {
        int userDigit;
        std::cout << "Введите начальное значение счётчика: ";
        std::cin >> userDigit;
        Count = new Counter(userDigit);
    }
    else
        Count = new Counter();

    system("cls");

    do
    {
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> answer;

        if (answer == "+")
            Count->add();
        else if (answer == "-")
            Count->subtract();
        else if (answer == "=")
            Count->print_current();

    } while (answer != "x" && answer != "X" && answer != "х" && answer != "Х");

    delete Count;
}
