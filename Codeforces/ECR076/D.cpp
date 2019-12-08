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
int BIG_VALUE = 2147483647;

class RMQ{

    int MAX_N;
    int highestOneBit(int i) {
        i |= (i >>  1);
        i |= (i >>  2);
        i |= (i >>  4);
        i |= (i >>  8);
        i |= (i >> 16);
        return i - (i >> 1);
    }
    public:
        int *dat;
        int *datIndexes;

        RMQ(int size = 100000){
            int HOB = highestOneBit(size);
            if (HOB != size){
                MAX_N = HOB<<1;
            }else{
                MAX_N = HOB;
            }
            dat = new int[MAX_N*2];
            datIndexes = new int[MAX_N*2];
            for (int i =1;i< MAX_N*2;i++){
                dat[i] = BIG_VALUE;
                datIndexes[i] = -1;
            }
        }

        void update(int index,int x){
            for (int i= index+MAX_N; i>0; i>>=1) {
            //iが対応するインデックス
                if (i >= MAX_N){
                    dat[i] = x;
                    datIndexes[i] = i-MAX_N;
                }else{
                    if (dat[i*2] <= dat[i*2+1]){
                        dat[i] = dat[i*2];
                        datIndexes[i] = datIndexes[i*2];
                    }else{
                        dat[i] = dat[i*2+1];
                        datIndexes[i] = datIndexes[i*2+1];
                    }
                }
            }
        }

        int query(int L,int R){
            L += MAX_N;
            R += MAX_N;
            int minValue = BIG_VALUE;
            for (;L<R; L>>=1, R>>=1) {
                if(R&1) {
                    --R;
                    if (dat[R] < minValue){
                        minValue = dat[R];
                    }
                } //--Rが対応するインデックス
                if(L&1){
                    if (dat[L] < minValue){
                        minValue = dat[L];
                    }
                    L++;
                }//L++が対応するインデックス
            }
            return minValue;
        }

        pair<int,int> queryWithIndex(int L,int R){
            L += MAX_N;
            R += MAX_N;
            int minValue = BIG_VALUE;
            int minIndex = -1;
            for (;L<R; L>>=1, R>>=1) {
                if(R&1) {
                    --R;
                    if (dat[R] < minValue){
                        minValue = dat[R];
                        minIndex = datIndexes[R];
                    }
                } //--Rが対応するインデックス
                if(L&1){
                    if (dat[L] < minValue){
                        minValue = dat[L];
                        minIndex = datIndexes[L];
                    }
                    L++;
                }//L++が対応するインデックス
            }
            return make_pair(minValue,minIndex);
        }
};

int defeat(ll hero_power, RMQ &monsters,ll k,ll left,ll right){
    if (left + 1 == right){
        return left;
    }
    ll center = (left + right)/2;
    if (hero_power >= - monsters.query(k,k+center) ){
        return defeat(hero_power,monsters,k,center,right);
    }else{
        return defeat(hero_power,monsters,k,left,center);
    }
};

int max_defeat(vector<pair<ll,ll>> &heros, RMQ &monsters,ll k,ll left,ll right){
    cout << left << " " <<right << endl;
    if (left + 1 == right){
        int left_defeat = defeat(heros[left].first,monsters,k,0,heros[left].second + 1);
        int right_defeat = defeat(heros[right].first,monsters,k,0,heros[right].second + 1);
        cout << left <<":" << left_defeat << " " << right <<":" << right_defeat << endl;
        return max(left_defeat,right_defeat);
    }

    ll left_center = (left * 2 + right)/3;
    ll right_center = (left + right * 2)/3;
    int left_center_defeat = defeat(heros[left_center].first,monsters,k,0,heros[left_center].second);
    int right_center_defeat = defeat(heros[right_center].first,monsters,k,0,heros[right_center].second);

    if (left_center_defeat < right_center_defeat){
        return max_defeat(heros,monsters,k,left_center,right);
    }else{
        return max_defeat(heros,monsters,k,left,right_center);
    }
}


int solve(){
    ll n,m;
    cin >> n;
    RMQ monsters(n);
    for(int i = 0;i<n;i++){
        ll a;
        cin >> a;
        monsters.update(i,-a);
    }
    cin >> m;
    vector<pair<ll,ll>> heros;
    for(int i = 0;i<m;i++){
        pair<ll,ll> p;
        cin >> p.first >> p.second;
        heros.push_back(p);
    }
    sort(heros.begin(),heros.end(),greater<pair<ll,ll>>());
    vector<pair<ll,ll>> strong_heros;
    for(int i = 0;i< n;i++){
        if (i == 0){
            strong_heros.push_back(heros[i]);
        }else if(heros[i].second > strong_heros.back().second){
            strong_heros.push_back(heros[i]);
        }
    }
    cout << max_defeat(strong_heros,monsters,0,0,strong_heros.size() - 1) << endl;
    return 0;
}
int main()
{
  ll t;
  cin >> t;
  for(int i = 0;i<t;i++){
      solve();
  }
  return 0;
}