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
    string S;
    cin >> S;
    vector<set<string>> DP(2);
    DP[0].insert("");
    DP[1].insert("");
    for(int i = 0;i < N;i++){
        ll current = i % 2;
        ll next = (i+1) % 2;
        DP[next] = DP[current];
        for(auto &s:DP[current]){
            if (s.size() <= 2){
                DP[next].insert(s + S[i]);
            }
        }
    }
    ll ans = 0;
    for(auto &s:DP[N%2]){
        if (s.size() == 3){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}