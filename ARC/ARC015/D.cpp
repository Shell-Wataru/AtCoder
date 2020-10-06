#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <iomanip>
#include <cmath>
#include <set>
#include <numeric>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

struct Effect{
    double q,x;
    ll t;
};

int main()
{
    // 整数の入力
    ll T,N;
    double P;
    cin >> T >> N >> P;
    vector<double> imos(100002,0);
    vector<double> times(100002);
    imos[0] = 1;
    for (int i = 0; i < N; i++)
    {
        double q,x;
        ll t;
        cin >> q >> x >> t;
        imos[1] += P * q * (x - 1);
        imos[t+1] += - P * q * (x - 1);
    }

    double total_times = imos[0];
    double current_times = imos[0];
    double total_cookies = 1;
    for (int i = 1; i < T; i++)
    {
        current_times = current_times + imos[i];
        total_times = total_times * current_times;
        // cout << "current_times:" << current_times << endl;
        // cout << "total_times:" << total_times << endl;
        total_cookies += total_times;
    }

    cout << fixed <<  setprecision(4) << total_cookies << endl;

    return 0;
}