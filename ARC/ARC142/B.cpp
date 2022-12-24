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
    ll N;
    cin >> N;
    vector<vector<ll>> ans(N,vector<ll>(N));
    for(int i = 0;i < N*N;i++){
      ans[i/N][i%N] = i + 1;
    }
    for(int i = 0;i < N;i++){
      if (i % 2 == 0 && i+1 < N){
        swap(ans[i],ans[i+1]);
      }
    }
    for(int i = 0;i < N;i++){
      for(int j = 0;j < N;j++){
        if (j != 0){
          cout << " ";
        }
        cout << ans[i][j];
      }
      cout << "\n";
    }
    cout << flush;
    return 0;
}