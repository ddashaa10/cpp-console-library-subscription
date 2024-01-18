#include "file_readerr.h"
#include "constanss.h"

#include <fstream>
#include <cstring>


void read(const char* file_name, rate* array[], int& size)
{
    std::ifstream file(file_name);
    if (file.is_open())
    {
        size = 0;
        char tmp_buffer[MAX_STRING_SIZE];
        while (!file.eof())
        {
            rate* item = new rate;
            file >> item->bank;
            file >> item->purchase;
            file >> item->sale;
            file.getline(item->address, MAX_STRING_SIZE);
            array[size++] = item;
        }
        file.close();
    }
    else
    {
        throw "Ошибка открытия файла";
    }
}