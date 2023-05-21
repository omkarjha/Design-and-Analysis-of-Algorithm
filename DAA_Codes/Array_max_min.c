#include <stdio.h>

// Function to find the minimum and maximum elements in an array
void findMinAndMax(int arr[], int left, int right, int *min, int *max)
{
    if (left == right)
    {
        *min = arr[left];
        *max = arr[right];
    }
    else if (left == right - 1)
    {
        if (arr[left] < arr[right])
        {
            *min = arr[left];
            *max = arr[right];
        }
        else
        {
            *min = arr[right];
            *max = arr[left];
        }
    }
    else
    {
        int mid = (left + right) / 2;
        int min1, min2, max1, max2;

        findMinAndMax(arr, left, mid, &min1, &max1);
        findMinAndMax(arr, mid + 1, right, &min2, &max2);

        *min = (min1 < min2) ? min1 : min2;
        *max = (max1 > max2) ? max1 : max2;
    }
}

int main()
{
    int arr[100], n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int min, max;
    findMinAndMax(arr, 0, n - 1, &min, &max);

    printf("Minimum element: %d\n", min);
    printf("Maximum element: %d\n", max);

    return 0;
}
