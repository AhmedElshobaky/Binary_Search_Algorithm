#include <stdio.h>
#include <string.h>
#include <math.h>

typedef signed char uint8_t;
typedef unsigned int uint32_t;

extern uint8_t binarySearch(uint32_t *arr, uint8_t size,uint32_t number);

extern uint8_t sorted (const uint32_t *arr, uint8_t size);

extern void sort(uint32_t *arr, uint8_t size);

extern void swap(uint32_t *num1, uint32_t *num2);

extern void printArray(uint32_t *arr, uint32_t size);