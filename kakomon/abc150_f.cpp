#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <limits>
#include <cmath>
#include <iomanip>
#include <functional>
#include <random>
#include <boost/multiprecision/cpp_int.hpp>
#include <atcoder/string>
using namespace std;
using ll = long long;
using namespace atcoder;

bool lt_substr(const string &s,const string &t, int si = 0, int ti = 0) {
  int sn = (int) s.size(), tn = (int) t.size();
  while(si < sn && ti < tn) {
    if(s[si] < t[ti]) return true;
    if(s[si] > t[ti]) return false;
    ++si, ++ti;
  }
  return si >= sn && ti < tn;
}

  int lower_bound(const string &s,string &t,const vector<int> &sa) {
    int low = -1, high = (int) sa.size();
    while(high - low > 1) {
      int mid = (low + high) / 2;
      if(lt_substr(s,t, sa[mid])) low = mid;
      else high = mid;
    }
    return high;
  }

  pair< int, int > lower_upper_bound(const string &s,string &t,const vector<int> &sa) {
    int idx = lower_bound(s,t,sa);
    int low = idx - 1, high = (int) sa.size();
    t.back()++;
    while(high - low > 1) {
      int mid = (low + high) / 2;
      if(lt_substr(s,t, sa[mid])) low = mid;
      else high = mid;
    }
    t.back()--;
    return {idx, high};
  }

int main()
{
  ll N;
  cin >> N;
  vector<ll> A(N);
  vector<ll> B(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A[i];
  }
  vector<bool> can_make(N, true);
  for (int i = 0; i < N; i++)
  {
    cin >> B[i];
  }
  for (int i = 0; i < 30; i++)
  {
    string a1;
    string a2;
    string b;
    ll a_one_count = 0;
    ll b_one_count = 0;
    for (int j = 0; j < N; j++)
    {
      if (A[j] & 1ll << i)
      {
        a_one_count++;
        a1 += '1';
        a2 += '0';
      }
      else
      {
        a1 += '0';
        a2 += '1';
      }
    }
    for (int j = 0; j < N; j++)
    {
      if (B[j] & 1ll << i)
      {
        b_one_count++;
        b += '1';
      }
      else
      {
        b += '0';
      }
    }
    b += b.substr(0, N - 1);
    if (!(a_one_count == b_one_count || N-a_one_count == b_one_count)){
      return 0;
    }else if ( (a_one_count == N || a_one_count == 0) && (b_one_count == N || b_one_count == 0)){
      continue;
    }
    vector<int> sa = suffix_array(b);
    pair<int,int> p1;
    if (a_one_count == b_one_count){
      p1 = lower_upper_bound(b,a1,sa);
    }else{
      p1 = {0,0};
    }

    pair<int,int> p2;
    if (N - a_one_count == b_one_count){
      p2 = lower_upper_bound(b,a2,sa);
    }else{
      p2 = {0,0};
    }
    // cout << "=" << endl;
    // cout << a1 << endl;
    // cout << a2 << endl;
    // cout << b << endl;
    // cout << p1.first << "~" << p1.second << "," << p2.first << "~" << p2.second << endl;
    for (int j = 0; j < 2 * N - 1; j++)
    {
      if ((p1.first <= j && j < p1.second) || (p2.first <= j && j < p2.second))
      {
      }
      else if (sa[j] < N)
      {
        // cout << sa[j] << endl;
        can_make[sa[j]] = false;
      }else{
        // cout <<sa[i] << endl;
      }
    }
  }
  for (int i = N; i >= 1; i--)
  {
    if (can_make[i%N])
    {
      cout << (N-i) % N << " " << (A[0] ^ B[i%N]) << "\n";
    }
  }
  cout << flush;
  return 0;
}