#include <stdio.h>
int binarySearch(int array[], int x, int n)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (array[mid] == x)
            return mid;
        if (array[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
void main(void)
{
    int i, n, A[20], target, ans;
    printf("\nName - Aditya Raj\n");
    printf("Enter size of array : ");
    scanf("%d", &n);
    printf("Enter %d elements ::: \n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);
    printf("Enter target elements : ");
    scanf("%d", &target);
    ans = binarySearch(A, target, n);
    if (ans == -1)
        printf("%d Not Found", target);
    else
        printf("%d Found at index %d\n\n", target, ans);
}