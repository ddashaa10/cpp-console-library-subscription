#include "filterr.h"
#include <cstring>
#include <iostream>
using namespace std;

rate** find_currency_rate_in_belarusbank(rate* array[], int size, int& result_size)
{
	rate** result = new rate * [size];
	result_size = 0;
	for (int i = 0; i < size; i++)
	{
		if (*array[i]->bank == *"Беларусбанк")
		{
			result[result_size++] = array[i];
		}
	}

	return result;
}

rate** find_currency_rate_by_sales(rate* array[], int size, int& result_size)
{
	rate** result = new rate * [size];
	result_size = 0;
	for (int i = 0; i < size; i++)
	{
		if (array[i]->sale < 2.5)
		{
			result[result_size++] = array[i];
		}
	}

	return result;
}