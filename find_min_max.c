#include <stdint.h>
#include "find_min_max.h"

void FindMinMax(int16_t* arr, int16_t arrSize, int16_t* minOut, int16_t* maxOut)
{
    int16_t tempMin = arr[0];
    int16_t tempMax = arr[0];
    int16_t i = 1;
    
    while (i < arrSize)
    {
        if (arr[i-1] < arr[i])
        {
            if (arr[i-1] < tempMin)
            {
                tempMin = arr[i-1];
            }

            if (arr[i] > tempMax)
            {
                tempMax = arr[i];
            }
        }
        else
        {
            if (arr[i] < tempMin)
            {
                tempMin = arr[i];
            }

            if (arr[i-1] > tempMax)
            {
                tempMax = arr[i-1];
            }
        }

        i += 2;
    }

    if ((i-1) < arrSize)
    {
        if (arr[i-1] < tempMin)
        {
            tempMin = arr[i-1];
        }

        if (arr[i-1] > tempMax)
        {
            tempMax = arr[i-1];
        }
    }

    *minOut = tempMin;
    *maxOut = tempMax;
}

