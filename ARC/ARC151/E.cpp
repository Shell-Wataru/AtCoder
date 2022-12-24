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
#include <boost/multiprecision/cpp_int.hpp>

namespace mp = boost::multiprecision;
using namespace std;

using ll = long long;

#include <atcoder/string>

using namespace std;
using ll = long long;
using namespace atcoder;

bool lt_substr(const vector<int> &s,const vector<int> &t, int si = 0, int ti = 0) {
  int sn = (int) s.size(), tn = (int) t.size();
  while(si < sn && ti < tn) {
    if(s[si] < t[ti]) return true;
    if(s[si] > t[ti]) return false;
    ++si, ++ti;
  }
  return si >= sn && ti < tn;
}

  int lower_bound(const vector<int> &s,vector<int> &t,const vector<int> &sa) {
    int low = -1, high = (int) sa.size();
    while(high - low > 1) {
      int mid = (low + high) / 2;
      if(lt_substr(s,t, sa[mid])) low = mid;
      else high = mid;
    }
    return high;
  }

  pair< int, int > lower_upper_bound(const vector<int> &s,vector<int> &t,const vector<int> &sa) {
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
    scanf("%lld", &N);
    vector<int> A(N);
    for(int i = 0;i < N;i++){
        cin >> A[i];
    }
    ll P;
    scanf("%lld", &P);
    vector<int> X(P);
    for(int i = 0;i < P;i++){
        cin >> X[i];
    }
    ll Q;
    scanf("%lld", &Q);
    vector<int> Y(Q);
    for(int i = 0;i < Q;i++){
        cin >> Y[i];
    }
    cout << "!!" << endl;
    ll ans = numeric_limits<ll>::max();
    auto sa = suffix_array(A);
    cout << "BB" << endl;
    auto p_y = lower_upper_bound(A,Y,sa);

    cout << p_y.first << "~" << p_y.second << endl;
    cout << sa[p_y.first] << endl;
    vector<int> dummyX(X);
    for(int i = 0;i < P;i++){
        auto p_x = lower_upper_bound(A,dummyX,sa);
        if (p_x.first <= p_y.second && p_y.first <= p_x.second){
            ans = min(ans,i+abs( (P-i)-Q));
        }
        dummyX.pop_back();
    }
    reverse(A.begin(),A.end());
    reverse(X.begin(),X.end());
    reverse(Y.begin(),Y.end());
    auto sa_rev = suffix_array(A);
    auto p_y_rev = lower_upper_bound(A,Y,sa_rev);
    cout << "REV" << endl;
    cout << p_y_rev.first << "~" << p_y_rev.second << endl;
    vector<int> dummyX_rev(X);
    for(int i = 0;i < P;i++){
        auto p_x = lower_upper_bound(A,dummyX_rev,sa_rev);
        cout << p_x.first << "~" << p_x.second << endl;
        if (p_x.first <= p_y_rev.second && p_y_rev.first <= p_x.second){
            ans = min(ans,i+abs( (P-i)-Q));
        }
        dummyX_rev.pop_back();
    }

    cout << ans << endl;
    return 0;
}