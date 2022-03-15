#include<stdio.h>
// For unsorted array
//Linear search
int linearSearch(int arr[], int size, int element) {
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
    
}

int main()
{
    int arr[] = {1, 45, 67, 78, 73, 69, 47};
    int size = sizeof(arr)/sizeof(int);
    int element = 78;
    int searchIndex = linearSearch(arr, size, element);
    printf("The element %d was found at index %d\n", element, searchIndex);

    return 0;
}
