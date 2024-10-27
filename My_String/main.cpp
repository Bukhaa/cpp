//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdexcept>
#include <locale.h>
#include "My_String.h"

int main()
{

    try
    {
        setlocale(LC_ALL, "RUS");
        std::cout << "Введите строку 1: " << std::endl;
        My_String str_1;
        std::cin >> str_1;
        std::cout << "Введите строку 2: " << std::endl;
        
        My_String str_2;
        std::cin >> str_2;
        
        std::cout << std::endl;

        std::cout << "Введите цифру для использования операторов: \n1.+\n2.=\n3.==\n4.!=\n5.>\n6.<\n7.[]\n8.+=\n9.++\n10.--\n11.>=\n12.<= " << std::endl;
        int number;
        std::cin >> number;

        switch (number)
        {
        case 1:
        {
            std::cout << "Это оператор + (конкатенация строк): " << std::endl;
            My_String res_str;
            res_str = str_1 + " " + str_2;
            std::cout << res_str << std::endl;

        }
        break;

        case 2:
        {
            std::cout << "Это оператор = (присвоить): " << std::endl;
            str_1 = std::move(str_2);
            std::cout << str_1 << std::endl;
            std::cout << "Присвоили str_2 в str_1";
        }
        break;

        case 3:
        {
            std::cout << "Это оператор == (равенство)\nЕсли строки равны выведется 1, иначе 0 " << std::endl;
            std::cout << (str_1 == str_2) << std::endl;
        }
        break;

        case 4:
        {
            std::cout << "Это оператор != (неравенство)\nЕсли строки неравны выведется 1, иначе 0 " << std::endl;
            std::cout << (str_1 != str_2) << std::endl;
        }
        break;

        case 5:
        {
            std::cout << "Это оператор > (больше)\nЕсли первая строка длинее второй выведется 1, иначе 0 " << std::endl;
            std::cout << (str_1 > str_2) << std::endl;
        }
        break;

        case 6:
        {
            std::cout << "Это оператор < (меньше)\nЕсли первая строка короче второй выведется 1, иначе 0 " << std::endl;
            std::cout << (str_1 < str_2) << std::endl;
        }
        break;

        case 7:
        {
            std::cout << "Это оператор []\nС помощью данного оператора можно получить букву по идексу, либо заменить бувку по индексу " << std::endl;
            int count;
            std::cout << "Если вы хотите получить букву по индексу введите 1, если хотите изменить букву введите 2: " << std::endl;
            std::cin >> count;

            if (count == 1)
            {
                std::cout << "Введите индекс любой буквы из первой строки (индексы начинаются с 0): ";
                int pos;
                std::cin >> pos;
                std::cout << std::endl;
                std::cout << "Это буква: " << (str_1[pos]) << std::endl;
            }

            if (count == 2)
            {
                std::cout << "Введите индекс любой буквы из первой строки (индексы начинаются с 0) и букву замены: ";
                int pos;
                char simvol;
                std::cin >> pos;
                std::cout << std::endl;
                std::cin >> simvol;
                std::cout << std::endl;
                str_1[pos] = simvol;

                std::cout << "Измененная строка: " << (str_1) << std::endl;
            }
        }
        break;

        case 8:
        {
            std::cout << "Это оператор +=: " << std::endl;
            str_1 += str_2;
            std::cout << str_1 << std::endl;
        }
        break;

        case 9:
        {
            std::cout << "Это оператор ++: " << std::endl;
            int count;
            std::cout << "Если вы хотите использовать префиснкую форму - введите 1, если постфиксную - 2: " << std::endl;
            std::cin >> count;

            if (count == 1)
            {
                std::cout << ++str_1 << "\n" << ++str_2 << std::endl;
            }

            if (count == 2)
            {
                std::cout << str_1++ << "\n" << str_2++ << std::endl;
                std::cout << str_1 << "\n" << str_2 << std::endl;
            }

        }
        break;

        case 10:
        {
            std::cout << "Это оператор --: " << std::endl;
            int count;
            std::cout << "Если вы хотите использовать префиснкую форму - введите 1, если постфиксную - 2: " << std::endl;
            std::cin >> count;

            if (count == 1)
            {
                std::cout << --str_1 << "\n" << --str_2 << std::endl;
            }

            if (count == 2)
            {
                std::cout << str_1-- << "\n" << str_2-- << std::endl;
            }
        }
        break;

        case 11:
        {
            std::cout << "Это оператор >= (больше или равно)\nЕсли первая строка больше или равна второй выведется 1, иначе 0 " << std::endl;
            std::cout << (str_1 >= str_2) << std::endl;
        }
        break;

        case 12:
        {
            std::cout << "Это оператор <= (меньше или равно)\nЕсли вторая строка меньше или равна первой выведется 1, иначе 0 " << std::endl;
            std::cout << (str_2 <= str_1) << std::endl;
        }
        break;

        default:
            throw "Ошибка!!!";

        }

        return 0;
    }
    catch (std::exception& ex)
    {
        std::cout << ex.what() << std::endl;;
    }
    catch (const char* ex)
    {
        std::cout << ex << " Операции с таким номером нет!!!" << std::endl;
    }
}

