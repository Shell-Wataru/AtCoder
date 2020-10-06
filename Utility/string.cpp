#include <map>
#include <set>
#include <vector>
#include <iostream>

using ll = long long;
using namespace std;

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

int main(){
    string S = "a,b,c,d,e,f";
    for(auto s:split(S,',')){
        cout << s << endl;
    }
    cout << is_starts_with(S,"a,") << endl;
    cout << is_starts_with(S,"b,") << endl;
    cout << is_ends_with(S,",f") << endl;
    cout << is_ends_with(S,"a") << endl;
    return 0;
}

