#include <stdio.h>
#include <stdlib.h>

// Implementation of Binary Search with the Divide and Conquer Approach

int binary_search(int arr[], int low, int high, int target)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    // If the number is not found
    return -1;
}

int main()
{
    int n, target;
    printf("Enter the size of the array : ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter the elements in sorted order: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    // Sorting of array elements
    printf("The elements in sorted order: \n");  
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    // Swap elements
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    for (int i = 0; i < n; i++)
    {
        printf("%d \t", arr[i]);
    }
    printf("\n");

    printf("Enter the target element to search: ");
    scanf("%d", &target);

    int result = binary_search(arr, 0, n - 1, target);

    if (result == -1)
    {
        printf("Element not found\n");
    }
    else
    {
        printf("Element found at index %d\n", result);
    }

    return 0;
}
