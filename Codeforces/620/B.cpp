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


int solve(){
    ll n,m;
    cin >> n >> m;
    set<string> strings;
    vector<string> strings_array;
    string reversible = "";
    for(int i = 0;i< n;i++){
        string s;
        cin >> s;
        strings_array.push_back(s);
        string reversed_s = s;
        reverse(reversed_s.begin(),reversed_s.end());
        if (s == reversed_s){
            reversible = s;
        }else{
            strings.insert(s);
        }
    }

    // cout << reversible << endl;
    deque<string> answer = {reversible};
    // cout << "aa"  << endl;
    for(auto s:strings_array){
        string reversed_s = s;
        reverse(reversed_s.begin(),reversed_s.end());

        if (strings.find(reversed_s) != strings.end()){
            answer.push_back(s);
            answer.push_front(reversed_s);
            // cout << s << endl;
            // cout << reversed_s << endl;
            strings.erase(s);
            strings.erase(reversed_s);
        }
    }

    // cout << "bb" << endl;
    string answer_string;
    for(auto s:answer){
        answer_string += s;
    }
    cout << answer_string.length() << endl;
    cout << answer_string << endl;
    return 0;
}
int main()
{
    // ll t;
    // cin >> t;
    // for(int i = 1;i<= t;i++){
        solve();
    // }
    return 0;
}
