#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <iomanip>
#include <cmath>
#include <set>
#include <numeric>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

ll pow(ll x, ll y, ll modulo)
{
    if (y == 0)
    {
        return 1LL;
    }
    else
    {
        ll y_2 = pow(x, y / 2, modulo) % modulo;
        ll yy = (y_2 * y_2) % modulo;
        if (y % 2 == 0)
        {
            return yy;
        }
        else
        {
            return (yy * x) % modulo;
        }
    }
}

ll popcount(ll a){
    ll ans = 0;
    for(int i = 0; (1<<i) <= a;i++){
        if (a & 1<<i){
            ans++;
        }
    }
    return ans;
}
int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    string X;
    cin >> X;
    vector<ll> A(2*100000+1,0);
    for(int i = 1; i< 2*100000+1;i++){
        A[i] = A[i % popcount(i)] + 1;
        // if (i < 100){
        //     cout << A[i] << endl;
        // }
    }
    // cout << "===" << endl;
    ll ones = 0;
    for(int i = 0;i < N;i++){
        if (X[i] == '1'){
            ones++;
        }
    }
    ll plus_total = 0;
    ll minus_total = 0;
    if (ones + 1 != 0){
        for(int i = 0;i < N;i++){
            if (X[i] == '1'){
                plus_total = (plus_total + pow(2,N - 1 - i,ones+1)) % (ones+1);
            }
        }
    }
    if (ones - 1 != 0){
        for(int i = 0;i < N;i++){
            if (X[i] == '1'){
                minus_total = (minus_total + pow(2,N - 1 - i,ones-1)) % (ones-1);
            }
        }
    }
    for(int i = 0; i < N;i++){
        ll count;
        bool is_zero = false;
        if (X[i] == '1'){
            if (ones - 1 == 0){
                is_zero = true;
                count = 0;
            }else{
                count = (minus_total - pow(2,N - 1 - i,ones - 1) + ones - 1) % (ones -1);
            }
        }else{
            if (ones + 1 == 0){
                count = 0;
            }else{
                count = (plus_total + pow(2,N - 1 - i,ones + 1)) % (ones + 1);
            }
        }
        if (is_zero){
            cout << 0 << endl;
        }else{
            cout << A[count] + 1 << endl;
        }
    }
    return 0;
}