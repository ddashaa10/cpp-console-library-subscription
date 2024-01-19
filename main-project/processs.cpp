#include "processingg.h"
#include <cstring>
#include <iostream>

using namespace std;

double process(rate* exchanges, int size) {
    double maxDifference = std::numeric_limits<double>::lowest();

    for (int i = 0; i < size; ++i) {
        double difference = exchanges[i].sale - exchanges[i].purchase;
        if (difference > maxDifference) {
            maxDifference = difference;
        }
    }

    return maxDifference;
}
