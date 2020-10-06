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
#include <set>
using namespace std;
using ll = long long;


int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    vector<ll> A(N);
    ll total = 0;
    for(int i = 0;i < N;i++){
      cin >> A[i];
    }
    for(int i = 2;i < N;i++){
      total = total ^ A[i];
    }

    ll sum12 = A[0] + A[1];
    ll diff = sum12 - total;
    cout << diff << endl;
    if (diff < 0 || diff & 1){
      cout << -1 << endl;
    }else{
      ll a = 0;
      ll b = 0;
      bool can_make = true;
      for(int i = 1;i < 35;i++){
        if (diff & 1ll<<i){
          cout << "i"<<i << endl;
          a += 1ll<<(i-1);
          b += 1ll<<(i-1);
        }
      }
      // cout << a << endl;
      // cout << b << endl;
      for(int i = 35; i >=0;i--){
        if (total & 1ll<<i){
          if ( (a + (1ll<<i)) <= A[0]){
            a += 1<<i;
          }else{
            b += 1<<i;
          }
        }
      }

      cout << A[0] - a << endl;
    }
    return 0;
}