#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
using namespace std;
using ll = long long;

vector<string> split(const string &s, char delim) {
    vector<string> elems;
    string item;
    for (char ch: s) {
        if (ch == delim) {
            elems.push_back(item);
            item.clear();
        }
        else {
            item += ch;
        }
    }
    elems.push_back(item);
    return elems;
}

bool is_starts_with(const std::string& s, const std::string& prefix) {
   auto size = prefix.size();
   if (s.size() < size) return false;
   return std::equal(std::begin(prefix), std::end(prefix), std::begin(s));
}

bool is_ends_with(const std::string& s, const std::string& suffix) {
   if (s.size() < suffix.size()) return false;
   return std::equal(std::rbegin(suffix), std::rend(suffix), std::rbegin(s));
}
string solve(){
    string ans = "";
    ll N;
    cin >> N;
    vector<string> starts_with;
    vector<string> ends_with;
    vector<string> contains;
    for(int i = 0;i< N;i++){
        string P;
        cin >> P;
        vector<string> splitted = split(P,'*');
        // cout << "!!!" << endl;
        // for(auto s:splitted){
        //     cout << s << ",";
        // }
        // cout << endl;
        if(splitted[0] != ""){
            starts_with.push_back(splitted[0]);
        }

        if(splitted[splitted.size()-1] != ""){
            ends_with.push_back(splitted[splitted.size()-1]);
        }
        string contain_s = "";
        for(int j = 1;j < splitted.size()-1;j++){
            contain_s += splitted[j];
        }
        if (contain_s != ""){
            contains.push_back(contain_s);
        }
    }
    bool can_make =true;
    string prefix = "";
    for(auto p:starts_with){
        if (p.size() > prefix.size()){
            swap(p,prefix);
        }
        // cout << prefix << endl;

        if (!is_starts_with(prefix,p)){
            // cout << prefix << " " << p << "!"<< endl;
            can_make = false;
        }
    }

    string suffix = "";
    for(auto p:ends_with){
        if (p.size() > suffix.size()){
            swap(p,suffix);
        }

        // cout << suffix << endl;
        if (!is_ends_with(suffix,p)){
            // cout << suffix << " " << p << "!" << endl;
            can_make = false;
        }
    }

    if (can_make){
        string ans;
        ans += prefix;
        for(auto p:contains){
            ans += p;
        }
        ans += suffix;
        return ans;
    }else{
        return "*";
    };
}
int main()
{
    // 整数の入力
    ll T;
    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        string ans = solve();
        cout << "Case #" << i << ": " << ans << endl;
    }

    return 0;
}