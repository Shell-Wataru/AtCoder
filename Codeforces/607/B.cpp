#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>

using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;

void rename_name(string &s,ll start){
    char min_char = '~';
    ll last_min_char_index = -1;
    for(int i = start;i< s.length();i++){
        if (s[i] <= min_char){
            min_char = s[i];
            last_min_char_index = i;
        }
    }

    if (s[start] == min_char){
        ll next_start = -1;
        for(int i = start;i< s.length();i++){
            if (s[i] != min_char){
                next_start = i;
                break;
            }
        }
        if (next_start != -1){
            rename_name(s, next_start);
        }
    }else{
        s[last_min_char_index] = s[start];
        s[start] = min_char;
    }
}
int solve(){
    string s,c;
    cin >> s >> c;
    rename_name(s,0);

    if (s < c){
        cout << s << endl;
    }else{
        cout << "---" << endl;
    }
    return 0;
}
int main()
{
    ll t;
    cin >> t;
    for(int i=0;i<t;i++){
        solve();
    }
   return 0;
}
