#include <iostream>
#include <bitset>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = long long;

//zero indexed and vector
template< typename T>
class BIT
{
public:
    vector<T> data;
    BIT(long long n) : data(n) {}
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

ll answer(ll N, vector<ll> &A,ll l,ll r){
    if (l+1 == r){
        return l;
    }
    // cout << l << "~" << r << endl;
    ll center = (l+r)/2;
    BIT<ll> bitA(2*N);
    ll currentA = 0;
    ll zerosA = 0;
    ll onesA = 0;
    bitA.add(N+0,1);
    for(int i = 0;i < N;i++){
        if (A[i] >= center){
            currentA++;
        }else{
            currentA--;
        }
        zerosA += bitA.sum(N+currentA+1,2*N);
        onesA += bitA.sum(0,N+currentA+1);
        bitA.add(N+currentA,1);
    }
    // cout << zerosA << "vs" << onesA << endl;
    if (onesA >= zerosA){
        return answer(N,A,center,r);
    }else{
        return answer(N,A,l,center);
    }
}

int solve()
{
    ll N;
    cin >> N;
    vector<ll> A(N);
    for(int i = 0;i < N;i++){
        cin >> A[i];
    }
    cout << answer(N,A,0,1000000001ll) << endl;
    return 0;
}

int main()
{
    // cout << "!" << endl;
    // 整数の入力
    // ll t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
    solve();
    // }
    // cout << flush;
    return 0;
}
