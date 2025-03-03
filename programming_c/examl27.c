/* Solution by Paul Griffiths (mail@paulgriffiths.net) */

/*

  EX3_1.C
  =======

  Suggested solution to Exercise 3-1

*/

#include <stdio.h>
#include <time.h>

int binsearch(int x, int v[], int n);  /*  Original K&R function  */
int binsearch2(int x, int v[], int n); /*  Our new function       */

#define MAX_ELEMENT 20000

/*  Outputs approximation of processor time required
    for our two binary search functions. We search for
    the element -1, to time the functions' worst case
    performance (i.e. element not found in test data)   */

int main(void)
{
    int testdata[MAX_ELEMENT]; // testdata is an array of size MAX_ELEMENT
    int index;  /*  Index of found element in test data  */
    int n = -1; /*  Element to search for  */
    int i;
    clock_t time_taken; // clock_t is a data type defined in the C standard library for storing processor time

    /*  Initialize test data  */

    for (i = 0; i < MAX_ELEMENT; ++i)
        testdata[i] = i; // testdata is an array of size MAX_ELEMENT

    /*  Output approximation of time taken for
        100,000 iterations of binsearch()       */

    for (i = 0, time_taken = clock(); i < 100000; ++i) // time_taken is the time taken to search the element
    {
        index = binsearch(n, testdata, MAX_ELEMENT); // n is the element to be searched, testdata is the array and MAX_ELEMENT is the size of the array
    }
    time_taken = clock() - time_taken; // time_taken is the time taken to search the element

    if (index < 0)
        printf("Element %d not found.\n", n);
    else
        printf("Element %d found at index %d.\n", n, index);

    printf("binsearch() took %lu clocks (%lu seconds)\n",
           (unsigned long)time_taken, // unsigned long is a data type that is used to store only positive values
           (unsigned long)time_taken / CLOCKS_PER_SEC); // CLOCKS_PER_SEC is a macro that is used to get the number of clock ticks per second

    /*  Output approximation of time taken for
        100,000 iterations of binsearch2()        */

    for (i = 0, time_taken = clock(); i < 100000; ++i)
    {
        index = binsearch2(n, testdata, MAX_ELEMENT);
    }
    time_taken = clock() - time_taken;

    if (index < 0)
        printf("Element %d not found.\n", n);
    else
        printf("Element %d found at index %d.\n", n, index);

    printf("binsearch2() took %lu clocks (%lu seconds)\n",
           (unsigned long)time_taken,
           (unsigned long)time_taken / CLOCKS_PER_SEC);

    return 0;
}

/*  Performs a binary search for element x
        in array v[], which has n elements      */

int binsearch(int x, int v[], int n)
{
    int low, mid, high;

    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

/*  Implementation of binsearch() using
    only one test inside the loop        */

int binsearch2(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    mid = (low + high) / 2;
    while (low <= high && x != v[mid])
    {
        if (x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;
        mid = (low + high) / 2;
    }
    if (x == v[mid])
        return mid;
    else
        return -1;
}
