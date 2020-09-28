#include <iostream>

using namespace std;

int main()
{
	freopen("isheap.in", "r", stdin);
  	freopen("isheap.out", "w", stdout);
	int n;
	cin >> n;
	int mas[n + 1];
	for(int i = 1; i <= n; i++)
	{
		cin >> mas[i];
	} 
	bool piramid = true;
	for(int i = 1; i <= n; i++)
	{
		if(2 * i < n && mas[i] > mas[2 * i])
		{
			piramid = false;
			break;
		}
		if(2 * i + 1 < n && mas[i] > mas[2 * i + 1])
		{
			piramid = false;
			break;
		}
	}
	if(piramid)
		cout << "YES";
	else
		cout << "NO";
}
