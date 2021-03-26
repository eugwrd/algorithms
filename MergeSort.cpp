#include <iostream>
#include <vector>

using namespace std;

void MergeSort(vector<int>&, int, int); 
void Merge(vector<int>&, int, int, int);


void MergeSort(vector<int>& data, int start, int end)
{
	if (start < end)
	{
		int mid = (end + start) / 2;
		MergeSort(data, start, mid);
		MergeSort(data, mid+1, end);

		Merge(data, start, end, mid);
	}
}
void Merge(vector<int>& data, int start, int end, int mid)
{
	int n1 = mid - start + 1;
	int n2 = end - mid;

	vector<int> L(n1), M(n2);
	for (int i = 0; i < n1; i++)
		L[i] = data[start + i];
	for (int i = 0; i < n2; i++)
		M[i] = data[mid + 1 + i];

	int i = 0, j = 0, k = start;

	while (i < n1 && j < n2)
	{
		if (L[i] <= M[j])
		{
			data[k] = L[i];
			i++;
		}
		else
		{
			data[k] = M[j];
			j++;
		}
		
		k++;		
	}

	while (i < n1)
	{
		data[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		data[k] = M[j];
		j++;
		k++;
	}


}

int main()
{
	vector<int> data(10);
	for (int i = 0; i < data.size(); i++)
	{
		data[i] = i + 1;
	}
	for (int i = 0; i < data.size(); i++)
	{
		swap(data[i], data[rand() % data.size()]);
	}
	for (int n : data)
		cout << n << " ";
	cout << endl;

	MergeSort(data, 0, data.size() - 1);

	for (int n : data)
		cout << n << " ";
	cout << endl;

	return 0;
}