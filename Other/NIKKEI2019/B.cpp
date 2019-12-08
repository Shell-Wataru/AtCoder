#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <iomanip>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

ll BASE_NUM = 998244353;

ll my_pow(ll x,ll y){
    if (y == 0){
        return 1LL;
    }else if(y == 1){
        return x;
    }else{
        return (my_pow(x,y/2) % BASE_NUM) * (my_pow(x,(y+1)/2) % BASE_NUM) % BASE_NUM;
    }
}

int main()
{
    // 整数の入力
    ll N;
    vector<ll> D;
    map<ll, ll> D_Counts;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        ll d;
        cin >> d;
        D.push_back(d);
        D_Counts[d]++;
    }
    if (D[0] != 0)
    {
        cout << 0 << endl;
    }
    else if (D_Counts[0] > 1)
    {
        cout << 0 << endl;
    }
    else
    {
        ll total = 1;
        for(int i = 1;i<D_Counts.size();i++){
            if (D_Counts[i] == 0){
                total = 0;
            }else{
                total = total * my_pow(D_Counts[i-1],D_Counts[i]) % BASE_NUM;
            }
            // cout << i << ":" << total << endl;
        }
        cout << total <<endl;
    }
    return 0;
}