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
    string S;
    ll N;
    cin >> N;
    cin >> S;
    bool found_white = false;
    vector<ll> black_counts(N+1,0);
    vector<ll> white_counts(N+1,0);
    for(int i = 0;i < N;i++){
        if (S[i] == '#'){
            black_counts[i+1] = black_counts[i] + 1;
        }else{
            black_counts[i+1] = black_counts[i];
        }
    }
    for(int i = N-1;i >= 0;i--){
        if (S[i] == '.'){
            white_counts[i] = white_counts[i+1] + 1;
        }else{
            white_counts[i] = white_counts[i+1];
        }
    }
    ll ans = numeric_limits<ll>::max();
    for(int i = 0;i <= N;i++){
        ans = min(ans,black_counts[i] + white_counts[i]);
    }
    cout << ans << endl;
    return 0;
}