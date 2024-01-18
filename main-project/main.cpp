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
    cout << "������������ ������ �1. GIT\n";
    cout << "������� �4. ����� �����\n";
    cout << "�����: ��������� �����\n\n";
    rate* rt[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data_rate.txt", rt, size);
        cout << "***** ����� ����� *****\n\n";
        for (int i = 0; i < size; i++)
        {
            /********** ����� ���������� �� ������ ������ **********/
            cout << "���������� �� ������ �����........: ";
            // ����� �����
            cout << rt[i]->bank << " ";
            // ����� �������
            cout << rt[i]->purchase << " ";
            // ����� �������
            cout << rt[i]->sale << " ";
            // ����� ������
            cout << rt[i]->address;
            cout << '\n';
            cout << '\n';
        }

        int filter;
        cout << "������� ����������:\n";
        cout << "1) ������� ����� ������ �� ���� ���������� ����� ������������ (� ��������)\n";
        cout << "2) ������� ����� ������ � ������ ��������� ������, � ������� ������� ������ 2,5.\n";
        cout << "�������� ������ ����������: ";
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
        cout << "���������� ������:\n";
        cout << "�������� ����������:\n";
        cout << "1) �� �������� ������� ����� ���������� ������� � �������\n";
        cout << "2) �� ����������� �������� �����, � � ������ ������ ����� �� ����������� ������ ���������\n";
        cout << "�������� �������� ����������: ";
        cin >> sort_criteria;
        cout << "������ ����������:\n";
        cout << "1) ���������� ������� (Bubble sort)\n";
        cout << "2) ���������� �������� (Merge sort)\n";
        cout << "�������� ����� ����������: ";
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
        cout << "��������������� ������:" << std::endl;
        for (int i = 0; i < size; ++i) {
            cout << " ����: " << rt[i]->bank << " �������: " << rt[i]->purchase
                << " �������: " << rt[i]->sale << " �����: " << rt[i]->address << endl;
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