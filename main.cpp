#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<fstream>
#include<time.h>
using namespace std;

const int nTest = 10;
const int N = 1e6;
int n;
double a[N];

void quicksort(double a[], int l, int r)
{
    if (r - l <= 0)
        return;
    double pivot = a[(l + r) / 2];
    int i = l, j = r;
    while (i <= j)
    {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++; j--;
        }
    }
    quicksort(a, i, r);
    quicksort(a, l, i-1);
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
    freopen("./output/quicksort/out.txt", "w", stdout);
    for (int iTest = 1; iTest <= 10; iTest++)
    {
        ifstream cin;
        cin.open(("./input/SORT" + to_str(iTest) + ".INP").c_str());
        read(cin);

        clock_t startt = clock();
        quicksort(a, 0, n-1);
        clock_t endd = clock();
        cout << (double) (endd - startt) / CLOCKS_PER_SEC << '\n';
        for (int i = 0; i+1 < n; i++)
            if (a[i]>a[i+1]) {cout << false; break;}
        //cerr << n;
        cin.close();
    }
    return 0;
}
