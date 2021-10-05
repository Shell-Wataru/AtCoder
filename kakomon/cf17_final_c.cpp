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
    vector<ll> D(N);
    for (size_t i = 0; i < N; i++)
    {
      scanf("%lld",&D[i]);
    }
    sort(D.begin(),D.end());
    ll ans = 0;

    while(true){
      bool made = true;
      ll next_ans = ans + 1;
      ll first = 0;
      ll last = 24;
      // cout << "next" << next_ans << endl;
      for(int i = 0;i < N;i++){
        ll first_diff = min(D[i] -first, last - D[i]);
        ll last_diff = min((24 - D[i]) - first,last - (24 - D[i]));
        // cout << first_diff << " " << last_diff << endl;
        if (first_diff >= next_ans && last_diff >= next_ans){
          if (first_diff > last_diff){
            first = D[i];
          }else{
            last = 24 - D[i];
          }
        }else if (first_diff >= next_ans && last_diff < next_ans){
          first = D[i];
        }else if (first_diff < next_ans && last_diff >= next_ans){
          last = 24 - D[i];
        }else if (first_diff < next_ans && last_diff < next_ans){
          made = false;
          break;
        }
      }
      if (made){
        ans = next_ans;
      }else{
        break;
      }
    }
    cout << ans << endl;
    return 0;
}