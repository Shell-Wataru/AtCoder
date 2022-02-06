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

int solve()
{
    string S;
    cin >> S;
    ll n = S.size();
    vector<vector<ll>> G(n);
    if (S.back() == '1' || S[0] == '0'){
        cout << -1 << endl;
        return 0;
    }
    S.pop_back();
    string revS = S;
    reverse(revS.begin(),revS.end());
    if (S != revS){
        cout << -1 << endl;
        return 0;
    }
    ll last = 0;
    for(int i = 0;i < (n+1)/2;i++){
        if (S[i] == '1'){
            for(int j = last+1;j <= i+1;j++){
                G[last].push_back(j);
            }
            last = i+1;
        }
    }
    for(int i = last+1;i < n;i++){
        G[last].push_back(i);
    }
    for(int i = 0;i < n;i++){
        for(auto to:G[i]){
            cout << i + 1<< " " << to + 1<< "\n";
        }
    }
    cout << flush;
    return 0;
}

int main()
{
    // ll t;
    // cin >> t;
    // for(int i = 0;i < t;i++){
    solve();
    // }
    cout << flush;
    return 0;
}