#include <stdio.h>
void selection(int A[], int n)
{
    int Pass, i, j, min, temp, loc;
    for (Pass = 0; Pass < n; Pass++)
    {
        min = A[Pass];
        loc = Pass;
        for (j = Pass + 1; j < n; j++)
        {
            if (A[j] < min)
            {
                min = A[j];
                loc = j;
            }
        }
        temp = A[Pass];
        A[Pass] = A[loc];
        A[loc] = temp;
    }
    printf("Sorted array is :::\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
}
void main()
{
    printf("\nName - Aditya Raj\n");
    int A[20], n, i;
    printf("Enter the size of array : ");
    scanf("%d", &n);
    printf("Enter %d elements :::\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    selection(A, n);
}