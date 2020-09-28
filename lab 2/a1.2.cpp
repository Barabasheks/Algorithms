#include <iostream>

using namespace std;

void sort(int *mas, int first, int last)
{
	if(last - first == 1)
	{
		if(mas[first] > mas[last])
		{
			int num = mas[first];
			mas[first] = mas[last];
			mas[last] = num;
		}
		return;
	}
	if(last == first)
		return;
	int mid = (last + first) / 2;
	sort(mas, first, mid);
	sort(mas, mid + 1, last);
	int buf[last - first + 1];
	int i = first, j = mid + 1, k = 0;
	while (last - first + 1 != k) 
	{
        if (i > mid)
            buf[k++] = mas[j++];
        else if (j > last)
            buf[k++] = mas[i++];
        else if (mas[i] > mas[j])
            buf[k++] = mas[j++];
        else buf[k++] = mas[i++];

    }
	for(int i = 0; i < last - first + 1; i++)
	{
		mas[i + first] = buf[i];
	}
}

int main()
{
	freopen("sort.in", "r", stdin);
  	freopen("sort.out", "w", stdout);
	int n;
	cin >> n;
	int *mas = new int[n];
	for(int i = 0; i < n; i++)
	{
		cin >> mas[i];
	}
	int first = 0, last = n - 1;
	sort(mas, first, last);
	for(int i = 0; i < n; i++)
	{
		cout << mas[i] << " ";
	}
}
