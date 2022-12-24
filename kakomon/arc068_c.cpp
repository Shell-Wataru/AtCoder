#include <string>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <iostream>
using namespace std;
using ll = long long;

// 区間加算　一点取得
//zero indexed and vector
template< typename T>
class DualBIT
{
public:
    vector<T> data;
    DualBIT(long long n) : data(n) {}
    // [0,index)に足す
    void add(int index, T v)
    {
        for (int i = index - 1; i >= 0; i = (i & (i + 1)) - 1)
        {
            data[i] += v;;
        }
    }

    void add(int l,int r, T v)
    {
        add(r,v);
        add(l,-v);
    }

    // indexを取得
    long long get(int index)
    {
        T retValue = 0;
        int N = data.size();
        for (int i = index; i < N; i |= i + 1)
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

int main()
{
    ll N, M;
    cin >> N >> M;
    DualBIT<ll> bit(M+1);
    for(int i = 0;i < N;i++){
        ll l,r;
        cin >> l >> r;
        r++;
        ll range_r = numeric_limits<ll>::max();
        for(ll j = 1;j < range_r;){
            // cout << "j:" << j << endl;
            ll next_l = max(j,(l+j-1)/j);
            ll next_r = min((r+j-1)/j,range_r);
            // cout << next_l << "~" << next_r << endl;
            if (next_l < next_r){
                bit.add(next_l,next_r,1);
            }
            if ((l+j-1)/j * j < r && j < next_l){
                bit.add(j,j+1,1);
            }
            range_r = next_l;
            j++;
        }
    }
    for(int i =1 ;i<= M;i++){
        cout << bit.get(i) << endl;
    }
    return 0;
}