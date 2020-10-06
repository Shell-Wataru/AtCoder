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

void print_query(vector<ll> &array,ll k){
  for(int i = 0;i<k;i++){
    if (i == 0){
      cout << array[i];
    }else{
      cout << " " << array[i];
    }
  }
  cout << "\n" <<flush;
}

template <typename T>
int find(vector<T> &array,T value){
  for(int i = 0;i < array.size();i++){
    if (array[i] == value){
      return i;
    }
  }
  return -1;
}
int main()
{
  ll n,k;
  cin >> n >> k;
  vector<ll> A(n,-1);
  vector<ll> query(k+1);
  vector<bool> decided(k+1);
  for(int i = 0;i<k+1;i++){
    query[i] = i+1;
  }
  set<ll> same_sides;
  ll last_added = -1;
  bool is_big_side = false;
  for(int i = 0;i<n;i++){
    ll a;
    ll pos;
    print_query(query,k+1);
    cin >> pos >> a;
    ll index = find(query,pos);
    if (decided[index]){
      same_sides.insert(query[k]);
      same_sides.insert(last_added);
    }else{
      A[pos-1] = a;
      decided[index] = true;
    }
    ll remove_index;
    for(int j = 0;j< k;j++){
      if (!decided[j] && same_sides.find(query[j]) == same_sides.end()){
        remove_index = j;
        break;
      }
    }

    cout << remove_index << endl;
    cout << k << endl;
    last_added = query[k];
    query[k] = query[remove_index];
    query[remove_index] =last_added;
  }
  return 0;
}