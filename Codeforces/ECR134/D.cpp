#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> a(2);
vector<vector<int>> b(2);
vector<vector<int>> ranges(2);

int solve()
{
  int n;
  cin >> n;
  a[0].resize(n);
  b[0].resize(n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &a[0][i]);
  }
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &b[0][i]);
  }
  ranges[0] = {0, n};
  int group_index = 0;
  int ans = 0;
  for (int i = 29; i >= 0; i--)
  {
    int next_group_index = (group_index + 1) % 2;
    ranges[next_group_index].clear();
    ranges[next_group_index].shrink_to_fit();
    ranges[next_group_index].push_back(0);
    a[next_group_index].clear();
    a[next_group_index].shrink_to_fit();
    b[next_group_index].clear();
    b[next_group_index].shrink_to_fit();
    bool can_make = true;
    for (int j = 0; j < ranges[group_index].size() - 1; j++)
    {
      int a_one_count = 0;
      int b_one_count = 0;
      int a_zero_count = 0;
      int b_zero_count = 0;
      for (int k = ranges[group_index][j]; k < ranges[group_index][j + 1]; k++)
      {
        if (a[group_index][k] & 1 << i)
        {
          a_one_count++;
        }
        else
        {
          a_zero_count++;
        }
        if (b[group_index][k] & 1 << i)
        {
          b_one_count++;
        }
        else
        {
          b_zero_count++;
        }
      }
      if (a_zero_count == b_one_count)
      {
        for (int k = ranges[group_index][j]; k < ranges[group_index][j + 1]; k++)
        {
          if (a[group_index][k] & 1 << i)
          {
            a[next_group_index].push_back(a[group_index][k]);
          }
          if (!(b[group_index][k] & 1 << i))
          {
            b[next_group_index].push_back(b[group_index][k]);
          }
        }
        if (ranges[next_group_index].back() !=  a[next_group_index].size()){
          ranges[next_group_index].push_back(a[next_group_index].size());
        }
        for (int k = ranges[group_index][j]; k < ranges[group_index][j + 1]; k++)
        {
          if (!(a[group_index][k] & 1 << i))
          {
            a[next_group_index].push_back(a[group_index][k]);
          }
          if ((b[group_index][k] & 1 << i))
          {
            b[next_group_index].push_back(b[group_index][k]);
          }
        }
        if (ranges[next_group_index].back() !=  a[next_group_index].size()){
          ranges[next_group_index].push_back(a[next_group_index].size());
        }
      }
      else
      {
        can_make = false;
        break;
      }
    }

    if (can_make)
    {
      ans =  ans | 1 << i;
      group_index = next_group_index;
    }
  }
  cout << ans << "\n";
  return 0;
}
int main()
{
  // 整数の入力
  int t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}
