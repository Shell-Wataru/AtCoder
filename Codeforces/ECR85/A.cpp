#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <iterator> // std::rbegin, std::rend

using namespace std;
using ll = long long;

int solve()
{
    ll n,k;
    cin >> n;
    ll last_t =0;
    ll last_c =0;
    bool correct = true;
    for(int i = 0;i< n;i++){
        ll t,c;
        cin >> t >> c;
        ll diff_t = t - last_t;
        ll diff_c = c - last_c ;
        if (diff_t < 0 || diff_c < 0 || diff_c > diff_t){
            correct = false;
        }
        last_t = t;
        last_c = c;
    }

    if (correct) {
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}

int main()
{
    // 整数の入力
    ll t;
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        solve();
    }
    return 0;
}