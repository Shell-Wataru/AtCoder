#include<iostream>
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
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;

int solve()
{
    // 整数の入力
    ll N;
    cin >> N;
    deque<ll> A;
    for(int i = 0;i < N;i++){
      ll a;
      cin >> a;
      if (A.empty() || A.back() != a){
        while( a == 2 && !A.empty() && A.back() == 1){
          A.pop_back();
        }
        while ( a == 3 && !A.empty() && A.back() == 4){
          A.pop_back();
        }
        if (a == 1 && !A.empty() && A.back() == 2){
          continue;
        }
        if (a == 4 && !A.empty() && A.back() == 3){
          continue;
        }
        A.push_back(a);
      }
    }
    while(!A.empty() && A.front() == 3 && A.back() == 4){
      A.pop_back();
    }
    while(!A.empty() && A.front() == 4 && A.back() == 3){
      A.pop_front();
    }
    while(!A.empty() && A.front() == 1 && A.back() == 2){
      A.pop_front();
    }
    while(!A.empty() && A.front() == 2 && A.back() == 1){
      A.pop_back();
    }
    deque<ll> twothree;
    deque<ll> onefour;
    for(auto a:A){
      if (a == 2 || a == 3){
        if (onefour.empty()){
          twothree.push_back(a);
        }else{
          onefour.pop_back();
        }
      }else{
        if (twothree.empty()){
          onefour.push_back(a);
        }else{
          twothree.pop_back();
        }
      }
      // cout << a << " ";
    }
    // cout << endl;
    // cout << twothree.size() << "," << onefour.size() << endl;
    if (twothree.size() > 0){
      cout << "Yes\n";
    }else{
      cout << "No\n";
    }
    return 0;
}

int main()
{
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
    cout << flush;
    return 0;
}