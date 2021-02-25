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

struct takahashi {
    ll x,y,c;
};
int main()
{
    // 整数の入力
    ll N, K;
    cin >> N;
    vector<ll> D(N);
    for(int i = 0;i < N;i++)    {
        cin >> D[i];
    }
    ll max_d = numeric_limits<ll>::min();
    ll min_d = numeric_limits<ll>::max();
    ll max_index = -1;
    ll min_index = -1;
    for(int i = 0;i < N;i++){
        if (max_d < D[i]){
            max_d = D[i];
            max_index = i;
        }
        if (min_d > D[i]){
            min_d = D[i];
            min_index = i;
        }
    }
    cout << 2 * N - 1 << endl;
    if (max_d + min_d > 0){
        for(int i = 0; i < N;i++){
            cout << max_index + 1 << "  " << i + 1 << endl;
        }
        for(int i = 0; i < N - 1;i++){
            cout << i + 1 << "  " << i + 2 << endl;
        }
    }else{
        for(int i = 0; i < N;i++){
            cout << min_index + 1 << "  " << i + 1 << endl;
        }
        for(int i = N-2; i >= 0;i--){
            cout << i + 2 << "  " << i + 1 << endl;
        }
    }
    return 0;
}