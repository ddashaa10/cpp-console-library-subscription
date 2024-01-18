#include <iostream>
#include <iomanip>

using namespace std;

#include "rate.h"
#include "file_readerr.h"
#include "constanss.h"
#include "filterr.h"
#include "sort.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Лабораторная работа №1. GIT\n";
    cout << "Вариант №4. Курсы валют\n";
    cout << "Автор: Моисеенко Дарья\n\n";
    rate* rt[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data_rate.txt", rt, size);
        cout << "***** Курсы валют *****\n\n";
        for (int i = 0; i < size; i++)
        {
            /********** вывод информации об курсах ваолют **********/
            cout << "Информация об курсах валют........: ";
            // вывод банка
            cout << rt[i]->bank << " ";
            // вывод покупки
            cout << rt[i]->purchase << " ";
            // вывод продажи
            cout << rt[i]->sale << " ";
            // вывод адреса
            cout << rt[i]->address;
            cout << '\n';
            cout << '\n';
        }

        int filter;
        cout << "Способы фильтрации:\n";
        cout << "1) Вывести курсы валюты во всех отделениях банка «Беларусбанк» (с адресами)\n";
        cout << "2) Вывести курсы валюты и адреса отделений банков, в которых продажа меньше 2,5.\n";
        cout << "Выберите способ фильтрации: ";
        cin >> filter;
        switch (filter)
        {
        case 1:
        {
            int new_size = 0;
            rate** currency_rate_in_belarusbank = find_currency_rate_in_belarusbank(rt, size, new_size);
            for (int i = 0; i < new_size; i++)
            {
                cout << currency_rate_in_belarusbank[i]->bank << currency_rate_in_belarusbank[i]->address << "\n";
            }
            delete currency_rate_in_belarusbank;
        }
        break;
        case 2:
        {
            int new_size1 = 0;
            rate** currency_rate_by_sales = find_currency_rate_by_sales(rt, size, new_size1);
            for (int i = 0; i < new_size1; i++)
            {
                cout << currency_rate_by_sales[i]->sale << "\n";
            }
            delete currency_rate_by_sales;
        }
        break;
        default:
            throw " ";
        }

        int sort_criteria;
        int sort_method;
        cout << "Сортировка данных:\n";
        cout << "Критерии сортировки:\n";
        cout << "1) По убыванию разницы между стоимостью продажи и покупки\n";
        cout << "2) По возрастанию названию банка, а в рамках одного банка по возрастанию адреса отделения\n";
        cout << "Выберите критерий сортировки: ";
        cin >> sort_criteria;
        cout << "Методы сортировки:\n";
        cout << "1) Сортировка обменом (Bubble sort)\n";
        cout << "2) Сортировка слиянием (Merge sort)\n";
        cout << "Выберите метод сортировки: ";
        cin >> sort_method;
        switch (sort_method)
        {
        case 1:
        {
            bubble_sort(rt, size, (sort_criteria == 1) ? compare_by_price_difference : compare_by_name_and_address);
        }
        break;
        case 2:
        {
            merge_sort(rt, 0, size - 1, (sort_criteria == 1) ? compare_by_price_difference : compare_by_name_and_address);
        }
        break;
        default:
            throw " ";
        }
        cout << "Отсортированные данные:" << std::endl;
        for (int i = 0; i < size; ++i) {
            cout << " Банк: " << rt[i]->bank << " Покупка: " << rt[i]->purchase
                << " Продажа: " << rt[i]->sale << " Адрес: " << rt[i]->address << endl;
        }
        for (int i = 0; i < size; i++)
        {
            delete rt[i];
        }
    }
    catch (const char* error)
    {
        cout << error << '\n';
    }
    return 0;
}