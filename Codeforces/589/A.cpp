#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;

bool check(ll i){
    string s = to_string(i);
    vector<bool> used(10,false);
    for(auto c:s){
        ll current = c -'0';
        if(used[current]){
            return false;
        }else{
            used[current] = true;
        }
    }
    return true;
}
int main()
{
    // 整数の入力
    ll l,r;
    cin >> l >> r;
    for (int i = l; i <= r; i++)
    {
        if(check(i)){
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;


    return 0;
}
