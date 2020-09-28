#include <iostream>

using namespace std;

int main()
{
	freopen("garland.in", "r", stdin);
  	freopen("garland.out", "w", stdout);
  	int n;
  	cin >> n;
  	double mas[n];
  	cin >> mas[0];
  	double l = 0, r = mas[0];
  	while(r - l > 0.0000000001)
	{
	  	mas[1] = (r + l) / 2;
	  	bool up = true;
	  	for(int i = 2; i < n; i++)
	  	{
	  		mas[i] = 2 * mas[i - 1] - mas[i - 2] + 2;
	  		if (mas[i] < 0) 
			{
				up = false;
				break;
			}
		}
		if (up)
			r = mas[1];
		else
			l = mas[1];
	}
	printf("%.2f", mas[n - 1]);
}
