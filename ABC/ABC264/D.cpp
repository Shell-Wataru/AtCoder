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

//zero indexed and vector
template< typename T>
class BIT
{
public:
    vector<T> data;
    BIT(long long n) : data(n) {}
    void add(int index, T v)
    {
        int N = data.size();
        for (int i = index; i < N; i |= i + 1)
        {
            data[i] += v;
        }
    }

    long long sum(int index)
    {
        T retValue = 0;
        for (int i = index; i >= 0; i = (i & (i + 1)) - 1)
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

// 0~N-1に注意,compressするか確認
ll inversion_number(vector<ll> &A){
    BIT<ll> bit(A.size()*2);
    ll ans = 0;
    for (int i = 0; i < A.size(); i++) {
        ans += i - bit.sum(A[i]);
        bit.add(A[i], 1);
    }
    return ans;
}

int solve()
{
  string S;
  cin >> S;
  string Atcoder = "atcoder";
  map<char,ll> mapping;
  for(int i = 0;i < Atcoder.size();i++){
    mapping[Atcoder[i]] = i;
  }
  vector<ll> A(S.size());
  for(int i = 0;i < S.size();i++){
    A[i] = mapping[S[i]];
  }
  cout << inversion_number(A) << endl;
  return 0;
}

int main()
{
  // cout << "!" << endl;
  // 整数の入力
  // ll T;
  // cin >> T;
  // for(int i = 0;i < T;i++){
  solve();
  // }
  cout << flush;
  return 0;
}
