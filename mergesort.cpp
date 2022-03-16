#include<iostream>
#include<algorithm>
#include<time.h>
#include<cstdlib>
#include<stdio.h>
#include<fstream>
using namespace std;

const int nTest = 10;
const int N = 1e6;
int n;
double a[N];

void mergee(double a[], int left, int mid, int right)
{
	int *temp;
	int lf = left;
	int rf = mid + 1;
	temp = new int[right - left + 1];
	for (int i = 0; i < right - left + 1; i++)
	{
		temp[i]=min(a[lf],a[rf]);
		if (a[lf]<a[rf]) lf++;
		else rf++;
		if (lf == mid + 1)
		{
			while (rf <= right)
			{
				i++;
				temp[i] = a[rf];
				rf++;
			}
			break;
		}
		if (rf == right + 1)
		{
			while (lf <= mid)
			{
				i++;
				temp[i] = a[lf];
				lf++;
			}
			break;
		}
	}
	for (int i = 0; i <= right - left; i++)
		a[left + i] = temp[i];
	delete temp;
}

void mergesort(double a[], int left, int right)
{
	if (right > left)
	{
		int mid;
		mid = left + (right-left) / 2;
		mergesort(a, left, mid);
		mergesort(a, mid + 1, right);
		mergee(a, left, mid, right);
	}
}

void read(ifstream& cin){

        cin >> n;
        for (int i = 0; i<n; i++)
        cin >> a[i];
}

string to_str(int x)
{
    if (x < 10)
    {
        string s = "0";
        s += char(x + '0');
        return s;
    }
    return "10";
}

int main()
{
    freopen("./output/mergesort/out.txt", "w", stdout);
    for (int iTest = 1; iTest <= 10; iTest++)
    {
        ifstream cin;
        cin.open(("./input/SORT" + to_str(iTest) + ".INP").c_str());
        read(cin);

        clock_t startt = clock();
        mergesort(a, 0, n-1);
        clock_t endd = clock();
        cout << (double) (endd - startt) / CLOCKS_PER_SEC << '\n';
        /* for (int i = 0; i+1 < n; i++)
            if (a[i]>a[i+1]) {cout << false; break;} */
        //cerr << n;
        cin.close();
    }
    return 0;
}
