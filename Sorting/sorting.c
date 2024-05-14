#include <stdio.h>

void BubbleSort(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int flag = 1;

        for (int j = 0; j < size - (i + 1); j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 0;
            }
        }

        if (flag)
            break;
    }
}

void InsertionSort(int *arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0)
        {
            if (key < arr[j])
            {
                arr[j + 1] = arr[j];
            }
            else
            {
                break;
            }
            j--;
        }
        arr[j + 1] = key;
    }
}

void SelectionSort(int *arr, int size)
{
    int min, minIndex, temp;
    for (int i = 0; i < size - 1; i++)
    {
        min = arr[i];
        minIndex = i;

        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < min)
            {
                min = arr[j];
                minIndex = j;
            }
        }

        if (i != minIndex)
        {
            temp = arr[i];
            arr[i] = min;
            arr[minIndex] = temp;
        }
    }
}

void print(int *arr, int size)
{
    printf("Array is : ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};
}