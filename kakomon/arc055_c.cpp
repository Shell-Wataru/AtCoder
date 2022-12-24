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
#include <set>
#include <atcoder/mincostflow>
using namespace std;
using ll = long long;
using namespace atcoder;
#include <atcoder/string>

int solve()
{
    string S;
    cin >>  S;
    string SS = S + S;
    ll N = S.size();
    ll M = SS.size();
    auto sa = suffix_array(SS);
    auto lcp =  lcp_array(SS, sa);
    for(int i = 0;i+1 < M;i++){
        if (sa[i] < N && sa[i+1] < N ){

        }
    }
    return 0;
}

int main()
{
    // ll T;
    // cin >> T;
    // for (int i = 0; i < T; i++)
    // {
    solve();
    // }
    cout << flush;
    return 0;
}
