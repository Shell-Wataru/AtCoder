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
    string S;;
    cin >> S;
    ll N = S.size();
    vector<vector<ll>> counts(26,vector<ll>(N+1,0));
    for(int i = 0;i < N;i++){
        for(int j = 0;j < 26;j++){
            if (S[i] - 'a' == j){
                counts[j][i+1] = counts[j][i] + 1;
            }else{
                counts[j][i+1] = counts[j][i];
            }
        }
    }
    ll ans = 1;
    for(int i = 0;i < N;i++){
        ll remain = N - 1 - i;
        // cout << counts[S[i] - 'a'][N] << ":" << counts[S[i] - 'a'][i+1] << endl;
        ans += remain - (counts[S[i] - 'a'][N] - counts[S[i] - 'a'][i+1]);
    }
    cout << ans << endl;
    return 0;
}