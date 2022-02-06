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

bool near_zero(double a){
  return abs(a) < 1e-8;
}

int main()
{
  // 整数の入力
  ll N;
  cin >> N;
  vector<pair<double, double>> S(N);
  vector<pair<double, double>> T(N);
  double s_center_x = 0;
  double s_center_y = 0;
  double t_center_x = 0;
  double t_center_y = 0;
  for (int i = 0; i < N; i++)
  {
    cin >> S[i].first >> S[i].second;
    s_center_x += S[i].first;
    s_center_y += S[i].second;
  }

  for (int i = 0; i < N; i++)
  {
    cin >> T[i].first >> T[i].second;
    t_center_x += T[i].first;
    t_center_y += T[i].second;
  }
  s_center_x /= N;
  s_center_y /= N;
  t_center_x /= N;
  t_center_y /= N;
  for (int i = 0; i < N; i++)
  {
    S[i].first -= s_center_x;
    S[i].second -= s_center_y;
  }

  for (int i = 0; i < N; i++)
  {
    T[i].first -= t_center_x;
    T[i].second -= t_center_y;
  }
  sort(S.begin(), S.end(), [](auto l, auto r)
       {
         double dl = hypot(l.first, l.second);
         double dr = hypot(r.first, r.second);
         double l_angle = atan2(l.first, l.second);
         double r_angle = atan2(r.first, r.second);
         if (abs(dl) < 1e-8)
         {
           return false;
         }
         else if (abs(dr) < 1e-8)
         {
           return true;
         }
         else if (abs(l_angle - r_angle) > 1e-8)
         {
           return l_angle < r_angle;
         }
         else
         {
           return dl < dr;
         }
       });

  sort(T.begin(), T.end(), [](auto l, auto r)
       {
         double dl = hypot(l.first, l.second);
         double dr = hypot(r.first, r.second);
         double l_angle = atan2(l.first, l.second);
         double r_angle = atan2(r.first, r.second);
         if (abs(dl) < 1e-8)
         {
           return false;
         }
         else if (abs(dr) < 1e-8)
         {
           return true;
         }
         else if (abs(l_angle - r_angle) > 1e-8)
         {
           return l_angle < r_angle;
         }
         else
         {
           return dl < dr;
         }
       });
  if (near_zero(S.back().first) && near_zero(S.back().second) && near_zero(T.back().first) && near_zero(T.back().second)){
    // cout << "!!" << endl;
    S.pop_back();
    T.pop_back();
    N--;
  }
  if (N == 0){
    cout << "Yes" << endl;
    return 0;
  }
  bool has_ok = false;
  for (size_t i = 0; i < N; i++)
  {
    double d_base_s = hypot(S[i].first, S[i].second);
    for (size_t j = 0; j < N; j++)
    {
      double d_base_t = hypot(T[j].first, T[j].second);

      double base_angle = atan2(S[i].first * T[j].first + S[i].second * T[j].second, S[i].first * T[j].second - S[i].second * T[j].first);
      // cout << "base:" << base_angle.first << "," << base_angle.second << endl;
      bool is_ok = true;
      for (int k = 0; k < N; k++)
      {
        auto s = S[(i + k) % N];
        auto t = T[(j + k) % N];
        double ds = hypot(s.first, s.second);
        double dt = hypot(t.first, t.second);
        if (abs(ds) < 1e-8 && abs(dt) < 1e-8)
        {
          continue;
        }
        else if (abs(ds) < 1e-8 || abs(dt) < 1e-8)
        {
          is_ok = false;
          break;
        }
        double angle = atan2(s.first * t.first + s.second * t.second, s.first * t.second - s.second * t.first);
        // cout << "  angle:" << angle.first << "," << angle.second << endl;
        if (abs(ds - dt) > 1e-8 || abs(base_angle - angle) > 1e-8)
        {
          // if (abs(ds - dt) > 1e-8 ){
          is_ok = false;
          break;
        }
      }
      if (is_ok)
      {
        has_ok = true;
        break;
      }
    }
  }
  if (has_ok)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
  return 0;
}
