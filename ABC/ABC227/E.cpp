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
  string S;
  ll K;
  cin >> S;
  cin >> K;
  map<string,ll> distances;
  queue<string> q;
  q.push(S);
  distances[S] = 0;
  while(!q.empty()){
    string current = q.front();
    ll d = distances[current];
    q.pop();
    for(int i = 0;i < S.size()-1;i++){
      swap(current[i],current[i+1]);
      if (distances.find(current) == distances.end()){
        distances[current] =  d + 1;
        q.push(current);
      }
      swap(current[i],current[i+1]);
    }
  }
  ll ans = 0;
  for(auto p:distances){
    if (p.second <= K){
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
