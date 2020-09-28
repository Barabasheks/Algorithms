#include <iostream>
#include <cstring>

using namespace std;

void sort(string mas1[],string mas2[], int first, int last)
{
	cout << mas1[0];
	  	cout << mas2[0];
	if(last - first == 1)
	{
		if(mas1[first] > mas1[last])
		{
			string dop1 = mas1[first];
			string dop2 = mas2[first];
			mas1[first] = mas1[last];
			mas2[first] = mas2[last];
			mas1[last] = dop1;
			mas2[last] = dop2;
		}
		return;
	}
	if(last == first)
		return;
	int mid = (last + first) / 2;
	sort(mas1, mas2, first, mid);
	sort(mas1, mas2, mid + 1, last);
	string buf[last - first + 1][2];
	int i = first, j = mid + 1, k = 0;
	while (last - first + 1 != k) 
	{
        if (i > mid)
		{
			buf[k++][0] = mas1[j++];
            buf[k++][1] = mas2[j++];
		}
        else if (j > last)
		{
        	buf[k++][0] = mas1[i++];
            buf[k++][1] = mas2[i++];
		}
        else if (mas1[i] > mas1[j])
		{
			buf[k++][0] = mas1[j++];
            buf[k++][1] = mas2[j++];
		}
        else
		{
        	buf[k++][0] = mas1[i++];
        	buf[k++][1] = mas2[i++];
		}

    }
	for(int i = 0; i < last - first + 1; i++)
	{
		mas1[i + first] = buf[i][0];
		mas2[i + first] = buf[i][1];
	}
}

int main()
{
	freopen("race.in", "r", stdin);
	freopen("race.out", "w", stdout);
  	int n;
  	cin >> n;
  	string mas1[n];
  	string mas2[n];
  	for(int i = 0; i < n; i++)
	{
	  	cin >> mas1[i];
	  	cin >> mas2[i];
	}
	for(int i = 0; i < n; i++)
	{
	  	cout << mas1[i];
	  	cout << mas2[i];
	}
	int first = 0, last = n - 1;
	sort(mas1, mas2, first, last);
	for(int i = 0; i < n; i++)
	{
	  	cout << mas1[i];
	  	cout << mas2[i];
	}
}
