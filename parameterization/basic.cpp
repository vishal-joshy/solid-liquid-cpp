#include <iostream>
#include <vector>

std::vector<int> BSort(std::vector<int> arr, int length)
{
    int temp;
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return arr;
}

int main()
{
    std::vector<int> arr = {5, 3, 2, 4, 1};

    std::vector sorted = BSort(arr, 5);

    for (int i : sorted)
    {
        std::cout << i;
    }
}
