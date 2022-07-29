#include <iostream>

class Comparator
{
public:
    bool Evaluate(int a, int b)
    {
        return a > b;
    }
};

void BSort(int *arr, int length, Comparator *c)
{
    int temp;
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length - i - 1; j++)
        {
            if (c->Evaluate(arr[j], arr[j + 1]))
            {
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main()
{
    int arr[5] = {5, 4, 3, 2, 1};

    Comparator *c;

    BSort(arr, 5, c);

    for (int i : arr)
    {
        std::cout << i;
    }
}