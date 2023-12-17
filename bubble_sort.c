#include <stdio.h>

void bubble(int A[], int n)
{
    int i, pass, temp;
    for (pass = 1; pass < n; pass++)
    {
        for (i = 0; i < n - pass; i++)
        {
            if (A[i] > A[i + 1])
            {
                temp = A[i];
                A[i] = A[i + 1];
                A[i + 1] = temp;
            }
        }
    }
    printf("Sorted array :::\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
}
void main()
{
    printf("\nName - Aditya Raj\n");
    int A[20], n, i;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    printf("Enter %d elements :::\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    bubble(A, n);
}
