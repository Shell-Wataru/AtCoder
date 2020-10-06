#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <iterator>  // std::rbegin, std::rend


using namespace std;
using ll = long long;

int solve(){
    ll n,k1,k2;
    cin >> n >> k1 >> k2;
    ll first_max = 0;
    ll second_max = 0;
    for(int i = 0;i< k1;i++){
        ll a;
        cin >> a;
        first_max = max(a, first_max);
    }

    for(int i = 0;i< k2;i++){
        ll a;
        cin >> a;
        second_max = max(a, second_max);
    }

    if(first_max > second_max){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}

int main()
{
    // 整数の入力
    ll n;
    cin >> n;
    for(int i =0;i<n;i++){
        solve();
    }
    return 0;
}