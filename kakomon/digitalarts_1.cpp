#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <iomanip>
#include <cmath>
#include <set>
#include <numeric>
#include <boost/multiprecision/cpp_int.hpp>
#include <regex>
using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

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


int main()
{
    string S;
    getline(cin,S);
    vector<string> words = split(S,' ');
    ll N;
    cin >> N;
    vector<string> ng_words(N);
    for (int i = 0; i < N; i++)
    {
        cin >> ng_words[i];
    }
    for(int i = 0; i < words.size();i++){
        bool ng = false;
        for(auto ng_word:ng_words){
            replace(ng_word.begin(),ng_word.end(),'*','.');
            regex re("^" + ng_word + "$");
            if (regex_match(words[i],re)){
                ng = true;
                break;
            }
        }
        if (i != 0){
            cout << " ";
        }
        if (ng){
            for(int j = 0;j < words[i].size();j++){
                cout << "*";
            }
        }else{
            cout << words[i];
        }
    }
    cout << endl;
    return 0;
}