#ifndef RATE_H
#define RATE_H

#include "constanss.h"

struct rate
{
    char bank[MAX_STRING_SIZE];
    double purchase;
    double sale;
    char address[MAX_STRING_SIZE];
};

#endif