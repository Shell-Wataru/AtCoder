#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <iomanip>
#include <cmath>
#include <set>
#include <numeric>
#include <boost/multiprecision/cpp_int.hpp>
#include <bitset>
using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;
ll BASE_NUM = 1000000007;
const ll square_size = 150;
const ll bit_size = square_size * 2 - 1;

bool can_put_row(bitset<bit_size> &current, ll new_one)
{
  if (current[new_one])
  {
    return false;
  }

  set<ll> diffs({0});
  for(int i = 0;i < bit_size;i++){
    if (current[i]){
      for(int j = i+1; j < bit_size;j++){
        if (current[j]){
          diffs.insert(abs(i - j));
        }
      }
    }
  }

  bool is_clear = true;
  for(int i = 0; i < bit_size;i++){
    if (current[i]){
      ll diff = abs(i - new_one);
      if(diffs.find(diff) != diffs.end()){
        is_clear = false;
        break;
      }
    }
  }

  if (is_clear){
    return true;
  }

  for (int i = 0; i < square_size; i++)
  {
    int j = new_one - i;
    if (j < 0 || j >= square_size)
    {
      continue;
    }
    for (int k = 0; k < square_size; k++)
    {
      if (k == i){
        continue;
      }
      for (int l = 0; l < square_size; l++)
      {
        if (l == j){
          continue;
        }
        ll one = k + l;
        ll two = k + j;
        ll three = i + l;
        if (current[one] && current[two] && current[three])
        {
          return false;
        }
      }
    }
  }
  return true;
}

ll counts(bitset<bit_size> &rows){
  ll count = 0;
  for(int i = 0;i< bit_size;i++){
    if(rows[i]){
      count += min(i + 1LL, 2 * square_size - (i + 1));
    }
  }
  return count;
}
ll max_counts(bitset<bit_size> &rows, int depth)
{
  if (depth == 0){
    return counts(rows);
  }

  ll min_used_index = bit_size;
  ll max_used_index = -1;
  for(ll i = 0;i < bit_size;i++){
    if (rows[i]){
      min_used_index = min(min_used_index,i);
      max_used_index = max(max_used_index,i);
    }
  }
  ll max_interval = max_used_index - min_used_index + 2;
  ll max_count = counts(rows);
  for (int i = max(min_used_index - max_interval,0ll) ; i < min(bit_size,max_used_index + max_interval); i++)
  {
    if ((i < min_used_index || max_used_index < i) && can_put_row(rows, i))
    {
      rows.set(i);
      max_count = max(max_count,max_counts(rows,depth -1));
      rows.reset(i);
    }
  }
  return max_count;
}
int main()
{
  // vector<string> answer(150, "......................................................................................................................................................");
  bitset<bit_size> rows;
  bool cannot_add = false;
  rows.set(148);
  rows.set(149);
  while (!cannot_add)
  {
    cout << rows.count() << endl;
    ll max_index = -1;
    ll max_count = 0;

    ll min_used_index = bit_size;
    ll max_used_index = -1;
    for(ll i = 0;i < bit_size;i++){
      if (rows[i]){
        min_used_index = min(min_used_index,i);
        max_used_index = max(max_used_index,i);
      }
    }
    ll max_interval = max_used_index - min_used_index + 2;
    for (int i = max(min_used_index - max_interval,0ll) ; i < min(bit_size,max_used_index + max_interval); i++)
    {
      ll count = 0;
      if ((i < min_used_index || max_used_index < i) && can_put_row(rows, i))
      {
        rows.set(i);
        count = max_counts(rows,3);
        rows.reset(i);
      }
      if (max_count < count || (count > 0 && max_count == count && abs(i - 149) < abs(max_index - 149)))
      {
        max_count = count;
        max_index = i;
      }
    }
    // cout << endl;
    if (max_index != -1)
    {
      cannot_add = false;
      cout << "index:" << max_index << ",max:" << max_count << endl;
      rows.set(max_index);
    }
    else
    {
      cannot_add = true;
    }
  }
  cout << counts(rows) << endl;
  return 0;
}