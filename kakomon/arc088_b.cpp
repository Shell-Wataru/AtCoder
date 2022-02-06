#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
using namespace std;
using ll = long long;

int solve()
{
    string S;
    cin >> S;
    bool flip = false;
    ll l = 0;
    ll r = S.size();
    vector<ll> sumS(S.size() + 1, 0);
    for (int i = 0; i < S.size(); i++)
    {
        sumS[i + 1] = sumS[i] + (S[i] - '0');
    }
    while (l < r)
    {
        if (flip){

        }else{
            while(S[l] == '0'){
                l++;
            }
            while(S[r-1] == '0'){
                r--;
            }
        }
    }
    cout << r - l << endl;
    return 0;
}

int main()
{
    // // 整数の入力
    //   ll t;
    //   cin >> t;
    //   for (size_t i = 0; i < t; i++)
    //   {
    solve();
    //   }
    //   cout << flush;
    return 0;
}
