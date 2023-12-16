#include <stdio.h>
int partition(int a[], int lb, int ub)
{
    int pivot, up, down, temp;
    down = lb;
    up = ub + 1;
    pivot = a[lb];
    while (down <= up)
    {
        do
        {
            down++;
        } while (a[down] < pivot);

        do
        {
            up--;
        } while (a[up] > pivot);
        if (down < up)
        {
            temp = a[down];
            a[down] = a[up];
            a[up] = temp;
        }
    }
    temp = a[lb];
    a[lb] = a[up];
    a[up] = temp;
    return up;
}
void Quick_Sort(int a[], int lb, int ub)
{
    int u;
    if (lb < ub)
    {
        u = partition(a, lb, ub);
        Quick_Sort(a, lb, u - 1);
        Quick_Sort(a, u + 1, ub);
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
    Quick_Sort(A, 0, n - 1);
    printf("Sorted array is :::\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
}