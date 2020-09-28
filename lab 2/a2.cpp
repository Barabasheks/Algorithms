#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

void sort(string* mas1, string* mas2, int first, int last)
{
	cout<<first<<" "<<last;
	if(last - first == 1)
	{
		if(mas1[first] > mas1[last])
		{
			string dop1 = mas1[first];
			string dop2 = mas2[first];
			//cout << dop1 << " " << dop2;
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
	//cout<<first<<" "<<mid;
	sort(mas1, mas2, first, mid);
	sort(mas1, mas2, mid + 1, last);
	string buf1[last - first + 1];
	string buf2[last - first + 1];
	int i = first, j = mid + 1, k = 0;
	while (last - first + 1 != k) 
	{
        if (i > mid)
		{
			buf1[k++] = mas1[j++];
            buf2[k++] = mas2[j++];
		}
        else if (j > last)
		{
        	buf1[k++] = mas1[i++];
            buf2[k++] = mas2[i++];
		}
        else if (mas1[i] > mas1[j])
		{
			buf1[k++] = mas1[j++];
            buf2[k++] = mas2[j++];
		}
        else
		{
        	buf1[k++] = mas1[i++];
        	buf2[k++] = mas2[i++];
		}

    }
	for(int i = 0; i < last - first + 1; i++)
	{
		mas1[i + first] = buf1[i];
		mas2[i + first] = buf2[i];
	}
}

int main()
{
	freopen("race.in", "r", stdin);
	freopen("race.out", "w", stdout);
  	int n;
  	cin >> n;
  	string* mas1 = new string[n];
  	string* mas2 = new string[n];
  	for(int i = 0; i < n; i++)
	{
	  	cin >> mas1[i];
	  	cin >> mas2[i];
	}
	int first = 0, last = n - 1;
	sort(mas1, mas2, first, last);
	/*for(int i = 0; i < n; i++)
	{
	  	cout << mas1[i]<<" ";
	  	cout << mas2[i]<<endl;
	}*/
}
