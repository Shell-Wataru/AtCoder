#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;

int solve()
{
    ll n;
    cin >> n;
    vector<ll> lefts(n,-1);
    vector<ll> rights(n,-1);
    map<ll,ll> left_min_eats;
    ll blues = 0;
    ll reds = 0;
    for(int i = 0;i< n;i++){
        ll a;
        cin >> a;
        lefts[i] = a;
        if (a == 1){
            reds++;
        }else{
            blues++;
        }
    }
    reverse(lefts.begin(),lefts.end());
    left_min_eats[reds - blues] = 0;
    for(int i = 0;i<n;i++){
        if (lefts[i] == 1){
            reds--;
        }else{
            blues--;
        }
        if (left_min_eats.find(reds - blues) == left_min_eats.end()){
            left_min_eats[reds - blues] = i+1;
        }
    }

    for(int i = 0;i< n;i++){
        ll a;
        cin >> a;
        rights[i] = a;
        if (a == 1){
            reds++;
        }else{
            blues++;
        }
    }

    ll minimum = BASE_NUM;
    if (left_min_eats.find(blues - reds) != left_min_eats.end()){
        minimum = min(minimum,left_min_eats[blues - reds]);
    }
    for(int i = 0;i< n;i++){
        if (rights[i] == 1){
            reds--;
        }else{
            blues--;
        }
        if (left_min_eats.find(blues - reds) != left_min_eats.end()){
            minimum = min(minimum,left_min_eats[blues - reds] + i + 1);
        }
    }
    cout << minimum << endl;
    return 0;
}

int main()
{
    // 整数の入力
    ll q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        solve();
    }
    return 0;
}
