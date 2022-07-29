#include <iostream>
#include <functional>

template <typename T>
void BSort(T *arr, int length, std::function<bool(int, int)> comparator)
{
    if (arr == nullptr)
        return;

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length - i - 1; j++)
        {
            if (comparator(arr[j], arr[j + 1]))
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

    std::function foo = [](int a, int b)
    {
        return a > b;
    };

    BSort(arr, 5, foo);

    for (int i : arr)
    {
        std::cout << i;
    }
}
