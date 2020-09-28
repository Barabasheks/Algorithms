#include <iostream>

using namespace std;

int main()
{
	freopen("turtle.in", "r", stdin);
  	freopen("turtle.out", "w", stdout);
	int h, w;
	cin >> h >> w;
	int arr1[h][w], arr2[h][w];
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cin >> arr1[i][j];
			arr2[i][j] = 0;
		}
	}
	
	arr2[h-1][0] = arr1[h-1][0];
	for (int i = h - 2; i >= 0; i--){
		arr2[i][0] = arr2[i+1][0] + arr1[i][0];
	}
	for (int i = 1; i < w; i++){
		arr2[h-1][i] = arr2[h-1][i-1] + arr1[h-1][i];
	}
	
	for (int i = h-2; i >= 0; i--)
	{
		for (int j = 1; j < w; j++)
		{
			arr2[i][j] = max(arr2[i+1][j], arr2[i][j-1]) + arr1[i][j];
		}
	}
	
	cout << arr2[0][w-1];
}
