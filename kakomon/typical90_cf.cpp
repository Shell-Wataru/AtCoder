#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = long long;

int solve()
{
    ll N;
    cin >> N;
    string S;
    cin >> S;
    ll r = 0;
    ll ans = 0;
    for(int l = 0;l < N;l++){
        while(r < N && S[l] == S[r]){
            r++;
        }
        ans += N-r;
    }
    cout << ans << endl;
    return 0;
}

int main()
{
    // 整数の入力
    //   ll t;
    //   cin >> t;
    //   for (size_t i = 0; i < t; i++)
    //   {
    solve();
    //   }
    cout << flush;
    return 0;
}
