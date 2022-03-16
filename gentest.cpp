#include <bits/stdc++.h>

using namespace std;

template<typename Numeric, typename Generator = std::mt19937>
Numeric random(Numeric from, Numeric to)
{
    thread_local static Generator gen(std::random_device{}());

    using dist_type = typename std::conditional
    <
        std::is_integral<Numeric>::value
        , std::uniform_int_distribution<Numeric>
        , std::uniform_real_distribution<Numeric>
    >::type;

    thread_local static dist_type dist;

    return dist(gen, typename dist_type::param_type{from, to});
}

string intToString(int x)
{
    stringstream ss;
    ss << x;
    string st; ss >> st;
    if (x < 10) st = "0" + st;
    if (x == 0) st = "00";
    return st;
}


void MakeTest(ofstream& cout, int iTest)  // ham sinh test
{
    vector<double> a;
    const int N = 1000000;
    const long long maxN = 1000000000;
    cout << N << "\n";
    for (int i = 0; i <= N; ++i)
        a.push_back(random<double>(-maxN,maxN));
    if (iTest == 1)
        sort(a.begin(), a.end());
    if (iTest == 2)
        sort(a.rbegin(), a.rend());
    for (auto value:a)
        cout << setprecision(9) << fixed << value << " ";
}

int main()
{
    srand(time(NULL));
    for(int iTest = 1; iTest <= 10; iTest++)
    {
        //string testForder = TASKNAME + "\\Test" + intToString(iTest); //ten folder SUM\\Test

        string inputFile = "SORT" + intToString(iTest) + ".INP";
        ofstream inp (inputFile.c_str());

        MakeTest(inp, iTest);
        inp.close();
    }
}
