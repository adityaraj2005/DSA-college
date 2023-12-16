#include <stdio.h>
int linearSearch(int array[], int x, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (array[i] == x)
            return i;
    }
    return -1;
}
void main()
{
    int i, n, A[20], target, ans;
    printf("\nName - Aditya Raj\n");
    printf("Enter size of array : ");
    scanf("%d", &n);
    printf("\nEnter %d elements : ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);
    printf("Enter target elements : ");
    scanf("%d", &target);
    ans = linearSearch(A, target, n);
    if (ans == -1)
        printf("%d Not Found", target);
    else
        printf("%d Found at index %d", target, ans);
}