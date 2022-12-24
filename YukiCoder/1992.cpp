#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = long long;

int solve()
{
    ll x;
    cin >> x;
    ll current = 0;
    ll total = 0;
    for(int i = 0;i < 100;i++){
        current += 2;
        total += 2;
        if (current == x){
            break;
        }
        current += 2;
        total += 2;
        if (current == x){
            break;
        }
        current += -1;
        total += 1;
        if (current == x){
            break;
        }
        current += -1;
        total += 1;
        if (current == x){
            break;
        }
        current += 2;
        total += 2;
        if (current == x){
            break;
        }
        current += -1;
        total += 1;
        if (current == x){
            break;
        }
        current += -1;
        total += 1;
        if (current == x){
            break;
        }
    }
    cout << total << endl;
  return 0;
}

int main()
{
//   ll t;
//   cin >> t;
//   for (size_t i = 0; i < t; i++)
//   {
    solve();
//   }
//   cout << flush;
  return 0;
}
