#include <iostream>
#include <stdlib.h>
#include <time.h>
 
using namespace std;
 
int main()
{
    freopen("kth.in", "r", stdin);
    freopen("kth.out", "w", stdout);
    long long n, k, A, B, C;
    cin >> n >> k;
    int mas[n];
    cin >> A >> B >> C;
    cin >> mas[0];
    cin >> mas[1];
    for(int i = 2; i < n; i++)
    {
        mas[i] = A * mas[i - 2] + B * mas[i - 1] + C;
    }
    int pos_of_random = 0, left = 0, right = n - 1;
    srand(time(0));
    while (true)
    {
    	if(mas[left] == mas[left + 1] && mas[left] == mas[left + 2])
		{
			pos_of_random = left;
			break;
		}
        if(left != right)
        {
            pos_of_random = rand() % (right - left) + left; 
        }
        else
        {
            pos_of_random = left;
            break;
        }
        swap(mas[pos_of_random], mas[right]);
        pos_of_random = left - 1;
        int j = 0;
        for(int i = left; i < right + 1; i++)
        {
            if (mas[right] >= mas[i])
            {
                pos_of_random++;
                swap(mas[i], mas[pos_of_random]);
                if(mas[right] == mas[i])
                	j++;
            }
        }
        if(pos_of_random + 1 >= k && j == pos_of_random - left + 1)
        	break;
	    if (pos_of_random + 1 < k)
	        left = pos_of_random + 1;
	    else if (pos_of_random + 1 > k)
	        right = pos_of_random - 1;  
	    else
	        break;
    }
    cout << mas[pos_of_random];
}
