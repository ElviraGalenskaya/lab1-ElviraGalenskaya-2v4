#include "tasks.h"
#include <iostream>
#include <sstream>
#include <Windows.h>
#include <vector>

// В данном файле содержатся функции с будущими решениями. Решайте каждую задачу в теле функции и вызывайте её в 
// файле "cpp_lab1.cpp"

// Напишите программу, которая запрашивает у пользователя целочисленное значение n и выводит на экран сумму всех
// чисел от 1 до n
void task1()
{
    std::cout << "====TASK_1====\n"
        << "Calculate sum of numbers starting from 1 to N.\n";

    int32_t     n = 0;
    std::string input;
Point:
    std::cout << "Enter number N: ";
    std::cin >> input;
    n = std::atoi(input.c_str());
    if (n == 0) goto Point;

    int32_t sum = 0;

    if (n > 0)
        for (int i = 0; i <= n; i++) sum += i;
    else
        for (int i = 0; i >= n; i--) sum += i;

    std::cout << "Sum of numbers: " << sum << "\n";
}

// Напишите программу, которая будет проверять, является ли введеное пользователем слово палиндромом
void task2()
{
    std::cout << "\n====TASK_2====\n"
        << "Determining whether the word is a polyndrom.\n";
    std::string str;

    std::cout << "Enter word: ";
    std::cin >> str;

    bool res = true;

    for (int i = 0; i < str.size() / 2; i++)
        if (str[i] != str[str.size() - (i + 1)])
            res = false;

    if (res) std::cout << "This word is polyndrom.\n";
    else std::cout << "This word is not polyndrom.\n";
}

// Напишите программу, которая принимает набор строковых значений у пользователя, а затем выводит их в консоль в
// рамочке из любого символа, например:
// ***********
// * Гаррош  *
// * не      *
// * виноват *
// * !       *
// ***********
void task3()
{
    std::cout << "\n====TASK_3====\n"
        << "Outputs data to the console in a frame.\n"
        << "If you want to stop entering data press ENTER.\n";

    std::vector<std::string> data;
    std::string item;
    std::getline(std::cin, item);
    while (true) {
        std::cout << "Enter item of data: ";
        std::getline(std::cin, item);
        if (item.size() == 0) break;
        else data.push_back(item);
    }

    int32_t maxSize = 0;
    for (std::string word : data)
        if (maxSize < word.size())
            maxSize = word.size();

    maxSize += 4;
    std::cout << "Out put frame:\n";

    std::string newWord;
    newWord = std::string(maxSize, '#');
    std::cout << newWord << "\n";
    newWord.clear();

    for (std::string word : data)
    {
        newWord.append("# " + word);
        newWord.append(std::string(maxSize - newWord.size() - 1, ' ') + "#");
        std::cout << newWord << "\n";
        newWord.clear();
    }
    newWord = std::string(maxSize, '#');
    std::cout << newWord << "\n";
}

// Напишите программу, которая принимает на вход от пользователя количество байт и выводит их в более читаемом виде,
// например, в килобайтах, мегабайтах или гигабайтах
void task4()
{
    std::cout << "\n====TASK_4====\n"
        << "Convert byte to kbyte.\n";

    int32_t byteSize;
    std::string input;

Point:
    std::cout << "Enter size in byte: ";
    std::cin >> input;
    byteSize = std::atoi(input.c_str());
    if (byteSize == 0) goto Point;

    std::cout << "Size in kbyte: " << (double)byteSize / (double)1024;
}

// Напишите программу, которая принимает на вход список номеров автомобилей в формате "А000АА77" (где 77 - регион),
// и выводит на экран все номера из указанного пользователем региона
void task5()
{
    std::cout << "\n====TASK_5====\n"
        << "Accepts a list of car numbers in the format \"A000AA77\" (where 77 is the region),\n"
        << " and displays all numbers from the region specified by the user\n"
        << "If you want to stop entering data press ENTER.\n";

    std::vector<std::string> data;
    std::string item;
    std::getline(std::cin, item);
    while (true) {
        std::cout << "Enter car number: ";
        std::getline(std::cin, item);
        if (item.size() == 0) break;
        else data.push_back(item);
    }

    std::string region;

Point:
    std::cout << "Enter region for search: ";;
    std::cin >> region;
    if (std::atoi(region.c_str()) == 0) goto Point;

    std::cout << "Cars with region " << region << " : \n";

    for (std::string carNumber : data)
        if (carNumber.size() >= region.size()
            && 0 == carNumber.compare(carNumber.size() - region.size(), region.size(), region))
            std::cout << carNumber << "\n";
}

// Программа принимает на вход список цен на товар за 10 дней. Необходимо вывести на экран интервал цен за 3 дня,
// в течение которых произошел наибольший рост цены
void task6()
{
    std::cout << "\n====TASK_6====\n"
        << "Accepts a list of product prices for 10 days as input. It is necessary to display \nthe price interval for 3 days, "
        << "during which the greatest price increase occurred.\n";

    std::vector<double> allPrice;
    std::string input;
    double price;

    while (true)
    {
    Point:
        std::cout << "Enter price for " << allPrice.size() + 1 << " day: ";
        std::cin >> input;
        price = std::stod(input);
        if (price == 0) goto Point;
        else allPrice.push_back(price);

        if (allPrice.size() == 10) break;
    }

    std::vector<std::pair<int, double>> dayPrice;
    double bestPrice = 0.;

    for (int i = 1; i < allPrice.size() - 1; i++)
        if (allPrice[i - 1] + allPrice[i + 1] + allPrice[i] > bestPrice)
        {
            dayPrice.clear();
            dayPrice.push_back(std::pair<int, double>(i - 1, allPrice[i - 1]));
            dayPrice.push_back(std::pair<int, double>(i, allPrice[i]));
            dayPrice.push_back(std::pair<int, double>(i + 1, allPrice[i + 1]));

            bestPrice = allPrice[i - 1] + allPrice[i + 1] + allPrice[i];
        }

    std::cout << "High price interval:\n";

    for (std::pair<int, double> day : dayPrice)
        std::cout << " Day: " << day.first + 1 << " price: " << day.second << "\n";
}

// Напишите программу, которая принимает на вход целочисленное значение, а затем выводит на экран массив из цифр
// 1 и 0, являющийся представлением данного числа в двоичной системе исчисления, например:
// Ввод: 34, Вывод: [1,0,0,0,1,0]
void task7()
{
    std::cout << "\n====TASK_7====\n" << "Takes an integer value as input, and then displays an array of digits\n"
        << "1 and 0, which is a representation of this number in binary calculus\n";

    std::string input;
    int32_t     num;

Point:
    std::cout << "Enter number: ";
    std::cin >> input;
    num = std::atoi(input.c_str());
    if (num == 0) goto Point;

    std::vector<char> twoSS;

    for (int i = 0; num; i++) {
        twoSS.push_back(num % 2);
        num /= 2;
    }

    std::cout << "Array: ";

    for (int i = twoSS.size() - 1; i >= 0; i--)
        std::cout << (int32_t)twoSS[i];
}

// * Напишите программу, которая принимает на вход от пользователя количество секунд, затем отсчитывает заданное
// количество секунд с выводом счета на экран
void task8()
{
    std::cout << "\n====TASK_8====\n" << "Accepts the number of seconds as input from the user, then counts \ndown the specified"
        << "number of seconds with the account output to the screen\n";
    std::string input;
    int32_t time;

Point:
    std::cout << "Enter count os seconds: ";
    std::cin >> input;
    time = std::atoi(input.c_str());
    if (time == 0) goto Point;

    while (time >= 0) {
        std::cout << time << "\n";
        time--;
        Sleep(1000);
    }
    std::cout << "\nTimer stop.\n\n";
}
