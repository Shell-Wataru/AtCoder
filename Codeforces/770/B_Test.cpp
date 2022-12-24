#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <numeric>

using namespace std;
using ll = long long;

class BIT
{
public:
    vector<ll> data;
    BIT(long long n) : data(n) {}
    void add(int index, long long v)
    {
        int N = data.size();
        for (int i = index; i < N; i |= i + 1)
        {
            data[i] += v;
        }
    }

    long long sum(int index)
    {
        long long retValue = 0;
        int i;
        for (i = index; i >= 0; i = (i & (i + 1)) - 1)
        {
            retValue += data[i];
        }
        return retValue;
    }

    void show(){
        for (auto v:data){
            cout << v << endl;
        }
    }
};

 ll inverse_number(vector<ll> &A,ll l, ll r){
    BIT bit(A.size());
    ll ans = 0;
    for (int i = 0; i < r-l; i++) {
        ans += i - bit.sum(A[l+i]);
        bit.add(A[l+i], 1);
    }
    return ans;
 }

int main()
{
    ll n = 10;
    vector<ll> a(n);
    iota(a.begin(),a.end(),1);
    ll ans_i = 2;
    ll ans_j = 4;
    ll ans_k = 8;
    reverse(a.begin()+ans_i-1,a.begin()+ans_j-1);
    reverse(a.begin()+ans_j-1,a.begin()+ans_k);
    // for(int i = 0;i < n;i++){
    //     cout << a[i] << ",";
    // }
    // cout << endl;
    cout << 1 << endl;
    cout << a.size() << endl;
    while(true){
        char type;
        cin >> type;
        if (type == '!'){
            ll i,j,k;
            cin >> i >> j >> k;
            cerr << i << "," << j << "," << k << endl;
            break;
        }else{
            ll l,r;
            cin >> l >> r;
            l--;
            cout << inverse_number(a,l,r) << endl;;
        }
    }
    return 0;
}
