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

using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    vector<ll> remains;
    for (int i = 0; i < N; i++)
    {
        ll X, Y, Z;
        ll M;
        cin >> X >> Y >> Z;
        cin >> M;
        ll max_x = 0, max_y = 0, max_z = 0, min_x = X, min_y = Y, min_z = Z;
        for (int j = 0; j < M; j++)
        {
            ll x, y, z;
            cin >> x >> y >> z;
            max_x = max(max_x,x);
            max_y = max(max_y,y);
            max_z = max(max_z,z);
            min_x = min(min_x,x);
            min_y = min(min_y,y);
            min_z = min(min_z,z);
        }
        remains.push_back(X - max_x - 1);
        remains.push_back(Y - max_y - 1);
        remains.push_back(Z - max_z - 1);
        remains.push_back(min_x);
        remains.push_back(min_y);
        remains.push_back(min_z);
    }

    ll nim_sum = 0;
    for(auto r: remains){
        // cout << r << endl;
        nim_sum = nim_sum ^ r;
    }
    // cout << nim_sum << endl;
    if (nim_sum){
        cout << "WIN" << endl;
    }else{
        cout << "LOSE" << endl;
    }
    return 0;
}