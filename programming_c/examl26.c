#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n) // x is the element to be searched, v is the array and n is the size of the array
{
    int low, high, mid; // low, high and mid are integer type variables
    low = 0;
    high = n - 1; // n - 1 is the last index of the array
    while (low <= high)
    {
        mid = (low + high) / 2; // mid is the middle index of the array
        // If x is less than the middle element of the array, then high is assigned mid + 1
        if (x < v[mid])
            high = mid + 1;
        else if (x > v[mid])
            low = mid + 1;
        else /* found match */
            return mid;
    }
    return -1; /* no match */
}

int main(){
    time_t start, end;
    start = time(NULL);
    int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = 10;
    int x = 5;
    end = time(NULL);
    printf("%d\n", binsearch(x, v, n));
    printf("Time taken to print sum is %.2f seconds",
        difftime(end, start));
    return 0;
}