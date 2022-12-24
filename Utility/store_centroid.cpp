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
#include <climits>
using namespace std;
using ll = long long;

ll store_centroid(vector<vector<ll>> &g, vector<ll> &centroid, ll current, ll parent)
{
  ll n = g.size();
  ll descendants = 1;
  bool iscentroid = true;
  for (auto to : g[current])
  {
    if (to != parent)
    {
      ll to_descendants = store_centroid(g, centroid, to, current);
      if (to_descendants > n / 2)
        iscentroid = false;
      descendants += to_descendants;
    }
  }
  if (n - descendants > n / 2)
  {
    iscentroid = false;
  }
  if (iscentroid)
    centroid.push_back(current);
  return descendants;
}

int main(){
    vector<vector<ll>> G = {
        {1},
        {0,2},
        {1,3},
        {2}
    };
    vector<ll> centroids;
    store_centroid(G,centroids,0,-1);
    for(auto c:centroids){
        cout << c << ",";
    }
    cout << endl;
    return 0;
}