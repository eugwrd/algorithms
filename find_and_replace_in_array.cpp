#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>

using namespace std;

int left_bound(vector<int>&, int);
int find(vector<int>&, int);

int main() 
{
    srand(time(NULL));

    vector<int> data(10);
    cout << "inds:\t";
    for (int i = 0; i < data.size(); i++)
    {
        data[i] = rand() % 100 + 1;
        cout << i << '\t';
    }
    sort(data.begin(), data.end());
    cout << "\nnums:\t";
    for (int n : data) cout << n << '\t';
    cout << '\n';

    int number;
    cout << "What do you want to find: ";
    cin >> number;

    if (find(data, number) != -1) cout << number << " located in index: " << find(data, number) << '\n';
    else cout << number << " not found, but you can add him after index: " << left_bound(data, number) << '\n';

    return 0;
}

int left_bound(vector<int>& A, int x)
{
    int left = -1;
    int right = A.size();

    while (right - left > 1)
    {
        int mid = (right + left) / 2;

        if (A[mid] < x) left = mid;
        else right = mid;
    }

    return left;
}

int find(vector<int>& A, int x)
{
    int i_left = left_bound(A, x);
    int i_number_after_left = i_left + 1;

    if (i_number_after_left < A.size() && A[i_number_after_left] == x) return i_number_after_left;
    else return -1;
}