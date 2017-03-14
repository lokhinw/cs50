/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    int left = 0;
    int right = n - 1;
    int middle = (left + right) / 2;
    
    while (left <= right) {
        if (values[middle] == value) {
            return true;
        } else if (values[middle] < value) {
           left = middle + 1;
           middle = (left + right) / 2;
           
        } else if (values[middle] > value) {
            right = middle - 1;
            middle = (left + right) / 2;
        } 
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (values[j - 1] > values[j]) {
                temp = values[j - 1];
                values[j - 1] = values[j];
                values[j] = temp;
            }
        }
    }
    return;
}
