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
#include <stack>

using namespace std;
using ll = long long;

ll keta_number(ll keta, ll number){

    for(int i = 0;i < keta;i++){
        number /= 10;
    }
    return number % 10;
}
ll same_number_value(ll keta, ll number){
    ll ans = 0;
    for(int i = 0;i < keta;i++){
        ans *= 10;
        ans += number;
    }
    return ans;
}

ll my_pow(ll x, ll y)
{
    if (y == 0)
    {
        return 1LL;
    }
    else
    {
        ll y_2 = my_pow(x, y / 2);
        ll yy = y_2 * y_2;
        if (y % 2 == 0)
        {
            return yy;
        }
        else
        {
            return yy * x;
        }
    }
}

ll diff(ll N, ll keta, vector<ll> &uses){
    vector<ll> using_numbers;
    for(int i = 0;i < 10;i++){
        if (uses[i] == 1){
            // cout << i << "," ;
            using_numbers.push_back(i);
        }
    }
    // cout << endl;
    ll min_num = using_numbers.front();
    ll max_num = using_numbers.back();
    ll min_diff = N - same_number_value(keta -1,max_num);
    // cout << min_diff << endl;
    bool broken = false;
    for(int i = keta -1;i>=0;i--){
        ll n = keta_number(i,N);
        // cout << N % my_pow(10,i+1) << endl;
        for(int j = n+1;j < 10;j++){
            if (uses[j] == 1){
                ll d = j*my_pow(10,i) + same_number_value(i,min_num) - N % my_pow(10,i+1);
                // cout << d << endl;
                min_diff = min(min_diff,d);
                break;
            }
        }

        for(int j = n-1;j >= 0;j--){
            if (uses[j] == 1){
                ll d = N % my_pow(10,i+1) -  (j*pow(10,i) + same_number_value(i,max_num));
                min_diff = min(min_diff,d);
                break;
            }
        }
        if (uses[n] != 1){
            broken = true;
            break;
        }
    }
    if (broken){
        return min_diff;
    }else{
        return 0;
    }
}
int solve(){
    ll N,K;
    cin >> N >> K;
    ll keta = to_string(N).size();
    vector<ll> uses(10);
    for(int i = 0;i < K;i++){
        uses[i] = 1;
    }
    sort(uses.begin(),uses.end());
    ll min_diff = numeric_limits<ll>::max();
    do{
        min_diff = min(min_diff,diff(N,keta,uses));
    }while(next_permutation(uses.begin(),uses.end()));
    cout << min_diff << endl;
    return 0;
}

int main()
{
    // 整数の入力
    // ll T;
    // cin >> T;
    // for (size_t i = 0; i < T; i++)
    // {
        solve();
    // }
    // cout << flush;
    return 0;
}