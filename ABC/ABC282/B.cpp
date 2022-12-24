

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

using namespace std;
using ll = long long;


int main()
{
    // 整数の入力
    ll N,M;
    cin >> N >> M;
    vector<string> G(N);
    for(int i = 0;i < N;i++){
      cin >> G[i];
    }
    ll ans = 0;
    for(int i = 0;i < N;i++){
      for(int j = i+1;j < N;j++){
        bool is_ok = true;
        for(int k = 0;k < M;k++){
          if (G[i][k] == 'x' && G[j][k] == 'x'){
            is_ok = false;
            break;
          }
        }
        if (is_ok){
          ans++;
        }
      }
    }
    cout << ans << endl;
    return 0;
}