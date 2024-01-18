#ifndef FILTERR_H
#define FILTERR_H

#include "rate.h"

rate** find_currency_rate_in_belarusbank(rate* array[], int size, int& result_size);

rate** find_currency_rate_by_sales(rate* array[], int size, int& result_size);

#endif
