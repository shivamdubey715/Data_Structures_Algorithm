#include <stdio.h>

int binarySearch(int arr[], int size, int element)
{
    int low = 0, high = size - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
        
    }
    return -1;
}

int main()
{
    int arr[] = {1, 45, 67, 78, 773, 869, 947};
    int size = sizeof(arr) / sizeof(int);
    int element = 947;
    int searchIndex = binarySearch(arr, size, element);
    printf("The element %d was found at index %d\n", element, searchIndex);

    return 0;
}