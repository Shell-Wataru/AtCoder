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

int solve()
{
    ll N,K;
    cin >> N >> K;
    if (K % 2 == 0 || (N == K && N != 1)){
        cout << "No" << endl;
        return 0;
    }
    vector<ll> points = {0};
    for(int i = 0;i < N;i++){
        for(int j = 0;j < 1ll<<i;j++){
            points.push_back(points[(1ll<<i)-1-j] ^ 1ll<<i);
        }
        if (i == K){
            for(int j = 0;j < 1ll<<(i+1);j++){
                if (j % 2 == 1){
                    points[j] ^= (1ll<<(i+1))-1;
                }
            }
        }
        if (i > K){
            for(int j = 0;j < 1ll<<i;j++){
                points[j+(1ll<<i)] ^= (1ll<<(K-1)) - 1;
            }
        }
    }
    // for(int i = 0;i < 1ll<<N;i++){
    //     cout << bitset<8>(points[i]) << endl;
    // }

    cout << "Yes\n";
    for(int i = 0;i < 1ll<<N;i++){
        if (i != 0){
            cout << " ";
        }
        cout << points[i];
    }
    cout << "\n";
    return 0;
}
int main()
{
    // ll T;
    // cin >> T;
    // while (T--)
    // {
        solve();
    // }
    // cout << flush;
    return 0;
}