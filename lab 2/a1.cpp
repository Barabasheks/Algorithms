#include <iostream>

using namespace std;

void sort(int *mas, int first, int last)
{
	int mid, count;
	int f = first, l = last;
	mid = mas[(f + l) / 2];
	do
	{
		while (mas[f] < mid) f++;
		while (mas[l] > mid) l--;
		if (f <= l)
		{
			count = mas[f];
			mas[f] = mas[l];
			mas[l] = count;
			f++;
			l--;
		}
	} while (f < l);
	if (first < l) sort(mas, first, l);
	if (f < last) sort(mas, f, last);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	freopen("sort.in", "r", stdin);
  	freopen("sort.out", "w", stdout);
	int n;
	cin >> n;
	int *mas = new int[n];
	int first = 0, last = n - 1;
	for(int i = 0; i < n; i++)
	{
		cin >> mas[i];
	}
	sort(mas, first, last);
	for(int i = 0; i < n; i++)
	{
		cout << mas[i] << " ";
	}
}
