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
    ll ans = N*(N+1)*(N+2)/6;
    for(int i = 0;i < N-1;i++){
      ll u,v;
      cin >> u >> v;
      if (u > v){
        swap(u,v);
      }
      ans -= u * (N - v +1);
    }
    cout << ans << endl;
    return 0;
}