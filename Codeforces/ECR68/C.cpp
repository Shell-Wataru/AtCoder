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

int main()
{
    // 整数の入力

    long long q,N,M,K,planed,removed,current_page,total;
    vector<ll> P;
    cin >> q;
    for(int i = 0;i< q;i++){
        string s,t,p;
        bool clear = true;
        map<char,ll> amari,p_box;
        cin >> s >> t >> p;
        ll t_index = 0;
        for (auto c:t){
            amari[c]++;
        }
        for (int j = 0;j< s.size();j++){
            bool found = false;
            for (;t_index< t.size();t_index++){
                if (s[j] == t[t_index]){
                    found = true;
                    amari[t[t_index]]--;
                    t_index++;
                    break;
                }
            }
            if (!found){
                // cout << "hohohohoh" << endl;
                clear = false;
            }
        }
        for (auto c:p){
            p_box[c]++;
        }
        for(auto pair: amari){
            // cout << pair.first << ":" << p_box[pair.first] - pair.second << endl;
            if(p_box[pair.first] - pair.second < 0){
                clear = false;
            }
        }

        if (clear){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
   return 0;
}