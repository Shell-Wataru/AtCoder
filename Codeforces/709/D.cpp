#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
#include <list>
using namespace std;
using ll = long long;
const ll BASE_NUM = 1000000007;

int solve()
{
    int n;
    scanf("%d", &n);
    vector<ll> A(n);
    list<deque<pair<ll,ll>>> segments;
    vector<ll> deleted;
    for(int i = 0;i < n;i++){
      scanf("%lld",&A[i]);
    }
    // cout << "!!" << endl;
    for(int i = 0;i < n;i++){
      segments.push_back(deque<pair<ll,ll>>());
      segments.back().push_back({i,A[i]});
    }

    ll last_number = 0;
    deque<pair<ll,ll>> *last_segment = &segments.back();
    while(!(segments.size() == 0 || (segments.size() == 1 && gcd(segments.front().front().second,segments.back().back().second) != 1))){
      for (auto it = segments.begin(); it != segments.end();) {
        if (last_number == 0){
          last_number = it->back().second;
          last_segment = &*it;
          ++it;
        }else if (gcd(it->front().second,last_number) == 1){
          deleted.push_back(it->front().first);
          it->pop_front();
          if (it->size() == 0) {
            it = segments.erase(it);
            last_number = 0;
          }
          else {
            last_segment = &*it;
            last_number = it->back().second;
            ++it;
          }
        }else{
          last_number = it->back().second;
          if (segments.size() > 1){
            for(auto p: *it){
              last_segment->push_back(p);
            }
            it = segments.erase(it);
          }else{
            ++it;
          }
        }
      }
    }

    cout << deleted.size();
    for(int i = 0 ;i < deleted.size();i++){
      cout << " "<< deleted[i] + 1;
    }
    cout << "\n";
    return 0;
}

int main()
{
    // 整数の入力
    ll t;
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        solve();
    }
    cout << flush;
    return 0;
}
