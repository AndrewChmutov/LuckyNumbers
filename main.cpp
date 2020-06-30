#include <iostream>
#include <cstdlib>


using namespace std;

int step(int numb, int s)
{
    int value = 1;

    for (int i = 0; i < s;i++)
    {
        value *= numb;
    }

    return value;
}

int GetSumArr(int* arr, int sz)
{
    int value = 0;

    for (int i = 0; i < sz; i++)
        value += arr[i];
    return value;

}

void splitNum(int* arr, int numb, int k)
{
    arr[0] = numb % 10;

    for (int i = 1; i < k; i++)
    {
        arr[i] = (numb % step(10, i + 1) - GetSumArr(arr, i)) / step(10, i);
    }
}

int length_numb(int numb)
{
    int c = 1;

    while(numb % step(10, c) != numb)
    {
        c++;
    }
    return c;
}

void lucky(int numb)
{
    cout << "\n\nLucky number:\t" << numb << endl;
}

void check_num(int n, int accuracy)
{
    int bounds = 1, k, val;
    while (bounds < accuracy)
    {
        int *arr;

        if (bounds == 1)
            val = n;

        k = length_numb(val);

        arr = new int[k];


        splitNum(arr, val, k);

        val = 0;

        for (int i = 0; i < k; i++)
        {
            val += step(arr[i], 2);
        }

        if (val == 1)
        {
            delete[] arr;

            lucky(n);

            cout << "Count " << bounds << endl;
            cout << "Continue?" << endl;

            system("pause");
            return;
        }

        delete[] arr;
        bounds++;
    }
}

int main()
{
    int n = 0;

    while (true)
    {
        check_num(n, 100);
        n++;
    }

    system("pause");
    return 0;
}
