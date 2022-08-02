#include <iostream>

template <typename T>
class IComparator
{
public:
    virtual bool Compare(T a, T b) = 0;
};

class IntComparator : public IComparator<int>
{
public:
    bool Compare(int a, int b)
    {
        return a > b;
    }
};

class DoubleComparator : public IComparator<double>
{
public:
    bool Compare(double a, double b)
    {
        return a > b;
    }
};


template <typename T>
void BSort(T *arr, int length, IComparator<T> &comp)
{
    if (arr == nullptr)
        return;

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length - i - 1; j++)
        {
            if (comp.Compare(arr[j], arr[j + 1]))
            {
                T temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main()
{
    int arr[5] = {5, 3, 2, 4, 1};

    IntComparator c;

    BSort(arr, 5, c);

    for (auto i : arr)
    {
        std::cout << i;
    }
}
