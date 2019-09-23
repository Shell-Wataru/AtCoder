#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include<map>

using namespace std;
using ll = long long;

ll clear_index(vector<map<char,ll>> &used_characters,map<char,ll> &name_chars , ll r,ll l){
    if (r + 1 == l){
        return l;
    }else{
        ll center = (r + l)/2;
        bool is_clear = true;
        for(auto c: name_chars){
            // cout << c.first << " " << c.second  << " " << used_characters[center][c.first] << endl;
            if (c.second > used_characters[center][c.first]){
                is_clear = false;
            }
        }
        if (is_clear){
            return clear_index(used_characters,name_chars,r,center);
        }else{
            return clear_index(used_characters,name_chars,center,l);
        }
    }
}

int main()
{
    // 整数の入力
    long long N;
    string s;
    vector<map<char,ll>> used_characters;
    cin >> N >> s;
    for(int i = 0;i< N;i++){
        if (i == 0){
            map<char,ll> cs;
            cs[s[i]]++;
            used_characters.push_back(cs);
        }else{
            map<char,ll> cs = used_characters[i - 1];
            cs[s[i]]++;
            used_characters.push_back(cs);
        }
    }

    ll M;
    cin >> M;
    for (int i = 0; i< M;i++){
        string name;
        cin >> name;
        map<char,ll> name_chars;
        for (auto c: name){
            name_chars[c]++;
        }
        ll ans = clear_index(used_characters,name_chars,-1,N-1);
        cout << ans + 1<< endl;
    }
    return 0;
}