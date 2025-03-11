#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

/* qsort: sort v[left]..v[right into increasing order */
void my_qsort(int v[], int left, int right)
{
    int i, last;
    void my_swap(int v[], int i, int j);
    if (left >= right)                  /* do nothing if array contains */
        return;                         /* fewer than two elements */

    my_swap(v, left, (left + right) / 2);  /* move partition elem */
    last = left;                        /* to v[0] */

    for (i = left + 1; i <= right; i++) /* partition */
        if (v[i] < v[left])
            my_swap(v, ++last, i);
            
    my_swap(v, left, last); /* restore partition elem */
    my_qsort(v, left, last - 1);
    my_qsort(v, last + 1, right);
}

/* swap: interchange v[i] and v[j] */
void my_swap(int v[], int i, int j) // swap v[i] and v[j]
{
    int temp;
 
    temp = v[i]; 
    v[i] = v[j];
    v[j] = temp;
}

int main()
{
    int i;
    int v[] = {3, 2, 1, 5, 4, 6, 7, 8, 9, 0};

    my_qsort(v, 0, 9);

    for (i = 0; i < 10; i++)
        printf("%d ", v[i]);
    printf("\n");

    return 0;
}

// Output: 0 1 2 3 4 5 6 7 8 9
 
 /* The above code is a simple implementation of the quicksort algorithm in C. The code is self-explanatory. The  my_qsort  function sorts the array  v  in increasing order. The  my_swap  function swaps two elements of the array. The  main  function initializes an array  v  with 10 elements and calls the  my_qsort  function to sort the array. Finally, the sorted array is printed. 
 The output of the above code is: 
 0 1 2 3 4 5 6 7 8 9 
 In the above code, the  my_qsort  function is a recursive function that sorts the array  v  in increasing order. The function takes three arguments: the array  v , the left index of the array, and the right index of the array. The function first checks if the array contains fewer than two elements. If so, it does nothing. Otherwise, it selects the partition element as the middle element of the array and swaps it with the leftmost element. Then, it partitions the array into two subarrays: one with elements less than the partition element and the other with elements greater than the partition element. It then recursively calls itself on the two subarrays. 
 The  my_swap  function swaps two elements of the array  v . It takes three arguments: the array  v  and the indices of the two elements to be swapped. It uses a temporary variable to swap the two elements. 
 In the  main  function, an array  v  is initialized with 10 elements. The  my_qsort  function is called to sort the array. Finally, the sorted array is printed. 
 You can modify the code to sort the array in decreasing order by changing the comparison operator in the  my_qsort  function. 
 That’s it for this tutorial. 
 Recommended Articles 
 This is a guide to Quicksort in C. Here we discuss the introduction, how quicksort works in C, and examples with code implementation. You may also have a look at the following articles to learn more – 
 
 Quicksort in Python
 Quicksort in Java
 Quicksort in C++
 Quicksort in C#
 
 C Programming Training (3 Courses, 5 Project)  3 Online Courses  5 Hands-on Projects  34+ Hours  Verifiable Certificate of Completion  Lifetime Access Learn More
 */