#include <iostream>


using namespace std;

long long sort(long long *mas, int first, int last, long long inv)
{
	if(last - first == 1)
	{
		if(mas[first] > mas[last])
		{
			long long num = mas[first];
			mas[first] = mas[last];
			mas[last] = num;
			inv++;
		}
		return inv;
	}
	if(last == first)
		return inv;
	int mid = (last + first) / 2;
	inv = sort(mas, first, mid, inv);
	inv = sort(mas, mid + 1, last, inv);
	long long buf[last - first + 1];
	int i = first, j = mid + 1, k = 0;
	while (last - first + 1 != k) 
	{
        if (i > mid)
            buf[k++] = mas[j++];
        else if (j > last)
		{
        	buf[k++] = mas[i++];	
		}
        else if (mas[i] > mas[j])
		{
			inv += mid - i + 1;
            buf[k++] = mas[j++];
        }
        else buf[k++] = mas[i++];

    }
	for(int i = 0; i < last - first + 1; i++)
	{
		mas[i + first] = buf[i];
	}
	return inv;
}

int main()
{
	freopen("inversions.in", "r", stdin);
  	freopen("inversions.out", "w", stdout);
	int n;
	cin >> n;
	long long *mas = new long long[n];
	for(int i = 0; i < n; i++)
	{
		cin >> mas[i];
	}
	int first = 0, last = n - 1;
	long long inv = 0;
	inv = sort(mas, first, last, inv);
	cout << inv;
}
