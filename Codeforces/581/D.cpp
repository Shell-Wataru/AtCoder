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
ll my_pow(ll x,ll y){
    if (y == 0){
        return 1LL;
    }else if(y == 1){
        return x;
    }else{
        return (my_pow(x,y/2) % BASE_NUM) * (my_pow(x,(y+1)/2) % BASE_NUM) % BASE_NUM;
    }
}
int main()
{
    // 整数の入力
    long long N,total;
    vector<string> A;
    map<ll,ll> length_map;
    map<ll,ll> length_leq_map;
    total = 0;
    cin >> N;
    for(int i = 0;i < N;i++){
        string S;
        cin >> S;
        reverse(S.begin(),S.end());
        A.push_back(S);
        length_map[S.size()]++;
    }

    ll count = 0;
    for(int i = 11;i>=0;i--){
        count += length_map[i];
        length_leq_map[i] = count;
    }

    for(int i = 0;i<N;i++){
        string &s = A[i];
        for(int j = 0;j<s.size();j++){
            for(int k = 0;k<12;k++){
                cout << k <<"-" <<length_map[k] << endl;
                cout <<  my_pow(10,j + min(j,k) ) * (s[j] - '0') * length_map[k] << endl;
                cout << my_pow(10,j + min(j+1,k)) * (s[j] - '0') * length_map[k] << endl;
                total = (total + my_pow(10,j + min(j,k) ) * (s[j] - '0') * length_map[k]) % BASE_NUM;
                total = (total + my_pow(10,j + min(j+1,k)) * (s[j] - '0') * length_map[k]) % BASE_NUM;
            }
        }
    }

    cout << total << endl;
   return 0;
}