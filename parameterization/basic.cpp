#include <iostream>
#include <memory>

void BSort(int *arr, int length)
{
    if (arr == nullptr)
        return;

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main()
{
    int arr[5] = {5, 3, 2, 4, 1};
    BSort(arr, 5);

    for (int i : arr)
    {
        std::cout << i;
    }
}
