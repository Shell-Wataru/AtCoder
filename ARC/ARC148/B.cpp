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
#include <climits>
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
    string S;
    cin >> S;
    string revS(S.begin(),S.end());
    reverse(revS.begin(),revS.end());
    for(int j = 0;j < revS.size();j++){
      if (revS[j] == 'd'){
        revS[j] = 'p';
      }else{
        revS[j] = 'd';
      }
    }
    auto sa = suffix_array(revS);
    ll first_p = -1;
    for(int i = 0;i < N;i++){
      if (S[i] == 'p'){
        first_p = i;
        break;
      }
    }
    if (first_p == -1){
      cout << S << endl;
      return 0;
    }
    string ans = S;
    for(int i = 0;i < N;i++){
      ll normal_sa_index = N-1-sa[i];
      ll length = normal_sa_index-first_p+1;
      if (length > 0){
        // cout << S.substr(0,i) << ":" <<  revS.substr(sa[sa_index],length) << ":"<< S.substr(normal_sa_index+1,N-normal_sa_index) << endl;
        ans = min(ans, S.substr(0,first_p) + revS.substr(sa[i],length) + S.substr(normal_sa_index+1,N-normal_sa_index));
      }
    }
    // for(int i = 0;i < N;i++){
    //   while(N-1-sa[sa_index] <= i && sa_index < N){
    //     sa_index++;
    //   }
    //   // cout << sa_index << endl;
    //   // cout << revS.substr(sa[sa_index]) << endl;
    //   if (lt_substr(revS,S,sa[sa_index],i)){
    //     ll normal_sa_index = N-1-sa[sa_index];
    //     cout << "!!" << endl;
    //     cout << i << endl;
    //     cout << S.substr(0,i) + revS.substr(sa[sa_index],normal_sa_index-i) + S.substr(normal_sa_index,N-normal_sa_index) << endl;;
    //     return 0;
    //   }
    // }
    cout << ans << endl;
    return 0;
}