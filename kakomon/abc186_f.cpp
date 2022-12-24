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
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;

//zero indexed and vector
template< typename T>
class BIT
{
public:
    vector<T> data;
    BIT(long long n) : data(n+1) {}
    //　indexに足す
    void add(int index, T v)
    {
        int N = data.size();
        for (int i = index; i < N; i |= i + 1)
        {
            data[i] += v;
        }
    }

    // [0,index)の和
    T sum(int index)
    {
        T retValue = 0;
        for (int i = index - 1; i >= 0; i = (i & (i + 1)) - 1)
        {
            retValue += data[i];
        }
        return retValue;
    }

    // [l,r)の和
    T sum(int l,int r)
    {
        return sum(r) - sum(l);
    }

    void show(){
        for (auto v:data){
            cout << v << endl;
        }
    }
};

int main()
{
    ll H,W,M;
    cin >> H >> W >> M;
    vector<vector<ll>> points(H);
    for(int i =0;i < M;i++){
        ll x,y;
        cin >> x >> y;
        x--;
        y--;
        points[x].push_back(y);
    }
    // cout << "!!" << endl;
    BIT<ll> bit(W);
    ll ans = 0;
    for(int i = 0;i < H;i++){
        // cout << i << endl;
        if (i == 0){
            sort(points[i].begin(),points[i].end());
            for(auto p:points[i]){
                for(int j = p;j < W;j++){
                    bit.add(j,1);
                    ans++;
                }
                break;
            }
        }else{
            if (bit.sum(0,1) == 1){
                points[i].push_back(0);
            }
            sort(points[i].begin(),points[i].end());
            bool is_first = true;
            for(auto p:points[i]){
                if (is_first){
                    ans += bit.sum(p,W);
                    is_first = false;
                }
                if (bit.sum(p,p+1) == 0){
                    ans++;
                    bit.add(p,1);
                }
            }
        }
    }
    cout << H*W - ans << endl;
    return 0;
}