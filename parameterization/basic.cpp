#include <iostream>
#include <vector>
#include <exception>
#include <string>

void BSort(std::vector<int> &arr, int length)
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
}

void helpMessage()
{
    std::cout << "Invalid argument size : use <filename> <array>" << std::endl;
}

std::vector<int> getArray(int argc, char **argv)
{
    std::vector<int> temp;
    for (int i = 1; i < argc; i++)
    {
        temp.push_back((int)std::stoi(argv[i]));
    }
    return temp;
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        helpMessage();
        return -1;
    }

    std::vector<int> arr = getArray(argc, argv);

    BSort(arr, argc - 1);

    std::cout << "sorted array :";

    for (int i : arr)
    {
        std::cout << i << " ";
    }
    return 0;
}
