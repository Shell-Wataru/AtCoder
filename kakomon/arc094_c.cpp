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

int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    vector<ll> A(N);
    vector<ll> B(N);
    ll total = 0;
    for(int i = 0;i < N;i++){
      cin >> A[i] >> B[i];
      total += A[i];
    }
    vector<ll> targets;
    for(int i = 0;i < N;i++){
      if (A[i] > B[i]){
        targets.push_back(B[i]);
      }
    }
    sort(targets.begin(),targets.end());
    if(targets.size() == 0){
      cout << 0 << endl;
    }else{
      cout << total - targets[0] << endl;
    }
    return 0;
}