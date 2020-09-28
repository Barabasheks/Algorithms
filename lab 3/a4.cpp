#include <iostream>

using namespace std;

void sift_down(int* mas, int root, int bottom)
{
	int max_child;
	bool done = false;
	while((root * 2 <= bottom) && (!done))
	{
		if(root * 2 == bottom)
			max_child = root * 2;
		else if(mas[root * 2] > mas[root * 2 + 1])
			max_child = root * 2;
		else
			max_child = root * 2 + 1;
		if(mas[root] < mas[max_child])
		{
			swap(mas[root], mas[max_child]);
			root = max_child;	
		}
		else
			done = true;
	}
}

void heap_sort(int* mas, int n)
{
	for(int i = n / 2 - 1; i >= 0; i--)
		sift_down(mas, i, n - 1);
	for(int i = n - 1; i >= 1; i--)
	{
		swap(mas[0], mas[i]);
		sift_down(mas, 0, i - 1);
	}
}

int main()
{
	freopen("sort.in", "r", stdin);
  	freopen("sort.out", "w", stdout);
  	int n;
  	cin >> n;
  	int mas[n];
  	for(int i = 0; i < n; i++)
  	{
  		cin >> mas[i];	
	}
	heap_sort(mas, n);
	for(int i = 0; i < n; i++)
	{
		cout << mas[i] << " ";
	}
}
