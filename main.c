#include "BinarySearch.h"

uint8_t arrSize(const uint32_t *arr);
int main() {
    // initialize the program
    printf("\t\tWelcome\n");
    printf("Press 's' to start the program\n");
    char input= ' ';
    scanf(" %c", &input);
    // if the user wants to start the program he will press 's'
    if(input == 's') {
        // changing the input to 'r' -> reload, to reload the program if wanted after ending it
        input = 'r';
        while (input == 'r') {
            // options given to the user
            printf("Options: \n");
            printf("a)Search for an index of a number in the array (after automatically sorted if needed)\n"
                   "b)Array before sort\n"
                   "c)Array after sorted\n");
            scanf(" %c", &input);
            // initializing array of uint32_t
            uint32_t arr[256] = {19, 10, 8, 17, 9, 12, 14, 26, 20, 24, 29, 31, 7, 40, 35};
            // determining the size of the array
            uint8_t size = arrSize(arr);
            // number that he user will search for its index in the array later
            uint32_t number = 0;
            // checking the user input
                switch (input) {
                    case 'b':
                        printf("Array before sort = ");
                        printArray(arr, size);
                        break;
                    case 'c':
                        // sort the array and print it
                        sort(arr, size);
                        printf("Array after sort = ");
                        printArray(arr, size);
                        break;

                    case 'a':
                        printf("Please enter a number to search for\n");
                        scanf(" %d", &number);
                        //passing the array to our function and storing the returned value in result
                        uint32_t result = binarySearch(arr, size, number);
                        // showing the result to the user
                        if (result == (-1)) {
                            printf("Number is not found in the array\n");
                        } else {
                            printf("Number found in index %d"
                                   "\n", result);
                        }
                        break;
                    default:
                        printf("Invalid input!\n");
                        break;
                }

            // checking whether the user wants to reload the program or not
            printf("Press 'r' to reload or any other key to exit\n");
            scanf(" %c", &input);
        }
    }
    return 0;
}
//function used to determine the size of the array
uint8_t arrSize(const uint32_t *arr) {
    int i = 0;
    while(arr[i] != '\0') i++;
    return i;
}