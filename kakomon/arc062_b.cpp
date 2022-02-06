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
    ll g = 0;
    ll p = 0;
    for(auto c:S){
        if (c == 'g'){
            g++;
        }else{
            p++;
        }
    }
    cout << (g- p)/2 << endl;
    return 0;
}

int main()
{
    // // 整数の入力
    // ll t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
    solve();
    // }
    cout << flush;
    return 0;
}
