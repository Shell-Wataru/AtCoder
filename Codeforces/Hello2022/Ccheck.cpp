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
    ll n = 4;
    vector<ll> p2 = {4,2,1,3};
    vector<ll> p1 = {1,3,4,2};
    vector<ll> q1 = {1,2,3,4};
    vector<ll> q2 = {1,2,3,4};
    cout << 2 << endl;
    cout << p1.size() << endl;
    while(true){
        char type;
        cin >> type;
        if (type == '!'){
            for(int i = 0;i < p1.size();i++){
                ll a;
                cin >> a;
                cerr << a << ",";
            }
            cerr << endl;
            break;
        }else{
            ll ask;
            cin >> ask;
            ask--;
            cout << q1[ask] << endl;;
            vector<ll> new_q(p1.size());
            for(int i = 0;i < p1.size();i++){
                new_q[i] = q1[p1[i]-1];
            }
            q1 = new_q;

        }
    }
    cout << p2.size() << endl;
    while(true){
        char type;
        cin >> type;
        if (type == '!'){
            for(int i = 0;i < p2.size();i++){
                ll a;
                cin >> a;
                cerr << a << ",";
            }
            cerr << endl;
            break;
        }else{
            ll ask;
            cin >> ask;
            ask--;
            cout << q2[ask] << endl;;
            vector<ll> new_q(p2.size());
            for(int i = 0;i < p2.size();i++){
                new_q[i] = q2[p2[i]-1];
            }
            q2 = new_q;

        }
    }
    return 0;
}
