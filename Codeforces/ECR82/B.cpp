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

int solve(){
    ll n,g,b;
    cin >> n >> g >> b;
    if (g >= b){
        cout << n << endl;
    }else{
        ll neccesarry_good_days =(n + 1)/2;
        ll neccesarry_bad_days =n/2;
        ll neccesarry_good_periods = (neccesarry_good_days + g - 1)/g - 1;
        ll amari_good = neccesarry_good_days - neccesarry_good_periods * g;
        ll amari_bad = max(neccesarry_bad_days - neccesarry_good_periods * b,0LL);
        // cout << "necessary_good_days" << neccesarry_good_days << "periods" << neccesarry_good_periods<< "amari_good" << amari_good  << "amari_bad" << amari_bad<< endl;
        cout << (g + b) * neccesarry_good_periods + amari_good  + amari_bad << endl;
    }
    return 0;
}
int main()
{
    // 整数の入力
    long long T;
    cin >> T;
    for(int i = 0;i< T;i++){
        solve();
    }

    return 0;
}