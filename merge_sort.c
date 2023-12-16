#include <stdio.h>
void Merge(int A[], int l, int m, int n)
{
    int R[20];
    int i, j, k;
    i = l;
    j = m + 1;
    k = l;
    while (i <= m && j <= n)
    {
        if (A[i] < A[j])
        {
            R[k] = A[i];
            i++;
        }
        else
        {
            R[k] = A[j];
            j++;
        }
        k++;
    }
    while (i <= m && j > n)
    {
        R[k] = A[i];
        i++;
        k++;
    }
    while ((j <= n && i > m))
    {
        R[k] = A[j];
        j++;
        k++;
    }
    for (i = l; i <= n; i++)
    {
        A[i] = R[i];
    }
}
void MergeSort(int A[], int left, int right)
{
    int mid;
    if (left < right)
    {
        mid = (left + right) / 2;
        MergeSort(A, left, mid);
        MergeSort(A, mid + 1, right);
        Merge(A, left, mid, right);
    }
}
void main()
{
    printf("\nName - Aditya Raj\n");
    int A[20], n, i;
    printf("Enter the size of array :");
    scanf("%d", &n);
    printf("Enter %d elements :::\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    MergeSort(A, 0, n - 1);
    printf("Sorted array is :::\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
}