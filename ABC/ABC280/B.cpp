

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
    ll N;
    cin >> N;
    vector<ll> S(N+1);
    for(int i = 0;i < N;i++){
      cin >> S[i+1];
    }
    for(int i = 0;i < N;i++){
      if (i!=0){
        cout << " ";
      }
      cout << S[i+1] - S[i];
    }
    cout << endl;
    return 0;
}