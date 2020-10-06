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
    ll a,b;
    cin >> a >> b;
    if (a < b){
        if ( (b -a) % 2 == 1){
            cout << 1 << endl;
        }else{
            cout << 2 << endl;
        }
    }else if(a > b){
        if ( (a - b) % 2 == 0){
            cout << 1 << endl;
        }else{
            cout << 2 << endl;
        }
    }else{
        cout << 0 << endl;
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