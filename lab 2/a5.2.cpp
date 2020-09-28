#include <iostream>
#include <cstdlib>

using namespace std;

int find_i(int mas[], int k, int n) 
{
	int l = 0, r = n - 1;
	while(true) 
	{
		if (l != r)
			swap(mas[l + rand() % (r - l)], mas[r]);
		int dop = mas[r];
		int piv = l - 1;
		for (int j = l; j <= r; j++) 
		{	
			if (mas[j] < dop)
			swap(mas[++piv], mas[j]);
		}
		swap(mas[++piv], mas[r]);
		if (mas[piv] == mas[r] && k >= piv)
			return mas[piv];
		if (piv < k)
			l = piv + 1;
		else if (piv > k)
			r = piv - 1;
		else return mas[k];
	}
}
int main()
{
	freopen("kth.in", "r", stdin);
    freopen("kth.out", "w", stdout);
    int n, k, A, B, C;
    cin >> n >> k;
    k--;
    int mas[n];
    cin >> A >> B >> C;
    cin >> mas[0];
    cin >> mas[1];
    for(int i = 2; i < n; i++)
    {
        mas[i] = A * mas[i - 2] + B * mas[i - 1] + C;
    }
	cout << find_i(mas, k, n);
}
