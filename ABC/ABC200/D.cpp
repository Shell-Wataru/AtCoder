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
  vector<ll> A(N);
  for (size_t i = 0; i < N; i++)
  {
    cin >> A[i];
    A[i] = A[i] % 200;
  }
  vector<vector<ll>> current(200);
  for (int i = 0; i < N; i++)
  {
    vector<vector<ll>> next = current;
    for (int j = 0; j < 200; j++)
    {
      ll remain = (j + A[i]) % 200;
      if (current[j].size() != 0 || j == 0){
        if (next[remain].size() != 0)
        {
          cout << "Yes" << endl;
          cout << current[j].size() + 1;
          for (auto b : current[j])
          {
            cout << " " << b + 1;
          }
          cout << " " << i + 1 << endl;
          cout << next[remain].size();
          for(auto c:next[remain]){
            cout << " " << c + 1;
          }
          cout << endl;
          return 0;
        }
        else
        {
          next[remain] = current[j];
          next[remain].push_back(i);
        }
      }
    }
    swap(current, next);
  }
  cout << "No" << endl;
  return 0;
}
