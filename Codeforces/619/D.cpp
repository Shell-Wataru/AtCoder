#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
using namespace std;
using ll = long long;
ll BASE_NUM = 998244353;

int main()
{
  ll n, m, k;
  cin >> n >> m >> k;
  ll max_k = 4 * n * m - 2 * n - 2 * m;
  if (k > max_k)
  {
    cout << "NO" << endl;
    return 0;
  }

  vector<pair<ll, string>> All;
  for (int i = 0; i < n - 1; i++)
  {
    All.push_back({1, "D"});
    All.push_back({m - 1, "R"});
    All.push_back({m - 1, "L"});
  }
  All.push_back({n - 1, "U"});

  for (int i = 0; i < m - 1; i++)
  {
    All.push_back({1, "R"});
    All.push_back({n - 1, "D"});
    All.push_back({n - 1, "U"});
  }
  All.push_back({m - 1, "L"});

  ll index = 0;
  vector<pair<ll, string>> Answer;
  while (k > 0)
  {
    pair<ll, string> p = All[index];
    index++;
    if(p.first == 0){
      continue;
    }else if (p.first >= k)
    {
      Answer.push_back({k, p.second});
      break;
    }
    else
    {
      k -= p.first;
      Answer.push_back(p);
    }
  }

  cout << "YES" << endl;
  cout << Answer.size() << endl;
  for (auto p : Answer)
  {
    cout << p.first << " " << p.second << endl;
  }
  return 0;
}