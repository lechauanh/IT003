#include <iostream>
#include<time.h>
#include<cstdlib>
#include<stdio.h>
#include<fstream>
using namespace std;

const int nTest = 10;
const int N = 1e6;
int n;
double a[N];

void heapify(double arr[], int n, int i)
{
    int M = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && arr[l] > arr[M])
        M = l;
    if (r < n && arr[r] > arr[M])
        M = r;
    if (M != i)
    {
        swap(arr[i], arr[M]);
        heapify(arr, n, M);
    }
}

void heapsort(double arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i=n-1; i>0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
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
    freopen("./output/heapsort/out.txt", "w", stdout);
    for (int iTest = 1; iTest <= 10; iTest++)
    {
        ifstream cin;
        cin.open(("./input/SORT" + to_str(iTest) + ".INP").c_str());
        read(cin);

        clock_t startt = clock();
        heapsort(a, n);
        clock_t endd = clock();
        cout << (double) (endd - startt) / CLOCKS_PER_SEC << '\n';
        /* for (int i = 0; i+1 < n; i++)
            if (a[i]>a[i+1]) {cout << false; break;} */
        //cerr << n;
        cin.close();
    }
    return 0;
}
