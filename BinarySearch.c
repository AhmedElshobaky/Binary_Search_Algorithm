#include "BinarySearch.h"

uint8_t binarySearch(uint32_t *arr, uint8_t size,uint32_t number){
    // check whether the array is sorted or not
    if(!sorted(arr, size))
        //if the array is not sorted it will be sorted
        sort(arr, size);
    //initializing the start, mid, and end of the array
    uint32_t start = 0, mid = size/2, end = size;
    // searching for the number given
    while (1){
        // if the number is located in the index mid, the index will be returned
        if(number == arr[mid]){
            return mid;
        } else if (start == mid){           //checking if the search has reached the end or not
            return -1;                      // if the start = mid --> indicates that search ended
        }
        // if the number is smaller or bigger than the number in the index of mid, modify the values of start, mid, and end.
        else if (number <arr[mid]){
            end = mid -1;
            mid = (start + end)/2 ;
            continue;
        } else if (number > arr[mid]){
            start = mid +1;
            mid = (start + end)/2 ;
            continue;
        }
    }
}
// function to check whether the array is sorted or not
uint8_t sorted (const uint32_t *arr, uint8_t size){
    for(int i = 0; i<size-1; i++){
       if(arr[i] > arr[i+1]) return 0;
    }
    return 1;
}
// sorting the array if not sorted using bubble sort algorithm
void sort(uint32_t *arr, uint8_t size){
    /*using nested loops to take each element and
      compare it to the rest of the elements in the array */
    for (int i = 0; i < size-1; i++)
        for (int j = 0; j < size-i-1; j++)
            if (arr[j] > arr[j+1])
                // using the swap function if the element is greater than the element after it
                swap(&arr[j], &arr[j+1]);
}
// swap function to swap elements
void swap(uint32_t *num1, uint32_t *num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}
// function used to print the array
void printArray(uint32_t *arr, uint32_t size){
    printf("{");
    for(int i = 0; i< size-1; i++)
        printf("%d,", arr[i]);

    printf("%d}\n", arr[size-1]);
}