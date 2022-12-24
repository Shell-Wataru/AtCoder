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
  ll Q;
  cin >> Q;
  queue<ll> q;
  map<ll,ll> counts;
  for(int i = 0;i < Q;i++){
    ll type;
    cin >> type;
    if (type == 1){
      ll x;
      cin >> x;
      q.push(x);
    }else if (type == 2){
      ll remove_value;
      if (counts.size() > 0){
        // cout << counts.begin()->first << ":" << counts.begin()->second << endl;
        remove_value = counts.begin()->first;
        counts[remove_value]--;
        if (counts[remove_value] == 0){
          counts.erase(remove_value);
        }
      }else{
        remove_value = q.front();
        q.pop();
      }
      cout << remove_value << "\n";
    }else{
      while(!q.empty()){
        counts[q.front()]++;
        q.pop();
      }
    }
  }

  return 0;
}
