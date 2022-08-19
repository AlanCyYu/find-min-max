#include <stdint.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "find_min_max.h"

#define ARRAY_SIZE 13
#define TEST_TIMES 1
#define MAX_NUM 123

void GenRandomArray(int16_t* arr, uint16_t arrSize);
void CheckFuntion(int16_t arr[], uint16_t arrSize);

int main()
{
    time_t t;
    srand(time(&t));// Initialization, should only be called once.
    int16_t arr[ARRAY_SIZE];
    uint16_t arrSize = sizeof(arr)/sizeof(arr[0]);
    int16_t max, min;
    
    for (int i = 0; i < TEST_TIMES; i++)
    {
        GenRandomArray(arr, arrSize);
        FindMinMax(arr, arrSize, &min, &max);
        //CheckFuntion(arr, arrSize);
    }
     
    for (int i = 0; i < arrSize; i++)
         printf("%d,", arr[i]);   
    
    printf("\n");
    
    printf("Max: %d, Min: %d.",max,min);
}

void CheckFuntion(int16_t arr[], uint16_t arrSize)
{
    for (uint16_t i = 1; i < arrSize; i++)
    {
        if (arr[i] < arr[i-1])
        {
            printf("Algorithm failed at index %d.\n", i);
            printf("%d, %d\n", arr[i-1], arr[i]);   
            return;
        }
    }
    printf("Algorithm succeed.\n");
    return;
}

void GenRandomArray(int16_t* arr, uint16_t arrSize)
{

    for (int16_t i = 0; i < arrSize; i++)
    {
        *(arr+i) = rand()%(MAX_NUM+1);
    }
}

