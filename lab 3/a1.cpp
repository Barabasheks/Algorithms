#include <iostream>

using namespace std;

int main()
{
	freopen("binsearch.in", "r", stdin);
  	freopen("binsearch.out", "w", stdout);
	int n, m;
	cin >> n;
	int mas[n];
	for(int i = 0; i < n; i++)
	{
		cin >> mas[i];
	}
	cin >> m;
	for(int i = 0; i < m; i++)
	{
		int num, mid, left = 0, right = n - 1;
		cin >> num;
		mid = (left + right) / 2;
		while(num != mas[mid] && left < right)
		{
			if(num > mas[mid])
				left = mid + 1;
			if(num < mas[mid])
				right = mid - 1;
			mid = (left + right) / 2;
		}
		if(mas[mid] == num)
		{
			int l = left, r = mid;
			while((num != mas[mid] || mas[mid - 1] == mas[mid]) && r > 0)
			{
				if(mas[mid] != num)
				{
					l = mid + 1;
				}
				else if(mas[mid - 1] == mas[mid])
				{
					r = mid - 1;
				}
				mid = (l + r) / 2;
			}
			cout << mid + 1 << " ";
			mid = (left + right) / 2;
			l = mid, r = right;
			while((num != mas[mid] || mas[mid + 1] == mas[mid]) && l < n - 1)
			{
				if(mas[mid] != num)
				{
					r = mid - 1;
				}
				else if(mas[mid + 1] == mas[mid])
				{
					l = mid + 1;
				}
				mid = (l + r) / 2;
			}
			cout << mid + 1 << endl;
		}
		else
			cout << "-1 -1" << endl;
	}
}
