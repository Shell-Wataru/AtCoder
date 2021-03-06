#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <limits>
#include <cmath>
#include <iomanip>
#include <functional>
#include <random>
#include <boost/multiprecision/cpp_int.hpp>

namespace mp = boost::multiprecision;
using namespace std;

using ll = long long;

const long long BASE_NUM = 1000000007;

int main()
{
    ll N;
    scanf("%lld", &N);
    vector<vector<ll>> trains(N-1,vector<ll>(3));
    for (size_t i = 0; i < N-1; i++)
    {
        cin >> trains[i][0] >> trains[i][1] >> trains[i][2];
    }

    for (size_t i = 0; i < N-1; i++)
    {
        ll current = trains[i][1];
        for(int j = i;j < N-1;j++){
            current = max(trains[i][0] + trains[i][1], (current+ trains[i][2] - 1)/trains[i][2] * trains[i][2] + trains[i][1]);
        }
        cout << current << endl;
    }
    return 0;
}