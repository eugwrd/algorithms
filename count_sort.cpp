#include<iostream>
#include<cstdlib>

using namespace std;

int* count_sort(int* A, int N, int max)
{
    int* F = new int[max + 1];                                     

    for (int i = 0; i < max + 1; i++) F[i] = 0;
    for (int i = 0; i < N; i++)
    {
        F[ A[i] ]++;
    }

    int j = 0; 
    for (int i = 0; i < max + 1; i++)
    {
        if (F[i] != 0)
        {
            while (F[i] != 0)
            {
                A[j++] = i;
                F[i]--;
            }
        }
    }

    delete[] F;

    return A;
}

int main() 
{
    srand(time(NULL));

    const int N = 10;

    int Arr[N];
    for (int i = 0; i < N; i++)
        Arr[i] = rand() % 6;
    for (int n : Arr)
        cout << n << '\t';
    cout << '\n';

    count_sort(Arr, N, 5);

    for (int n : Arr)
        cout << n << '\t';

    return 0;
}