#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
using namespace std;
using ll = long long;

int suffix_pairs(bool first,vector<string> texts){
    map<char,vector<string>> m;

    for (int i = 0; i < texts.size();i++ ){
        if (texts[i].size() > 1){
            m[texts[i].front()].push_back(texts[i].substr(1));
        }else if(texts[i].size() == 1){
            m[texts[i].front()].push_back("");
        }else{
            m[' '].push_back("");
        }
    }

    ll sum = 0;
    ll size_one = 0;
    for (const auto a : m){
        if (a.second.size() == 1){
            size_one++;
        }else if ( a.first == ' '){
            size_one += a.second.size();
        } else if (a.second.size() >= 2){
            ll p = suffix_pairs(false,a.second);
            sum += p;
            size_one += a.second.size() - p;
        }
    }

    if (size_one >= 2 && !first){
        sum += 2;
    }
    return sum;
}

int main()
{
    // 整数の入力
    ll T;
    cin >> T;

    for(int i = 1; i<= T;i++){
        ll N,ssize;
        vector<string> texts;
        cin >> N;
        string S;
        for (int j = 0; j < N ;j++){
            cin >> S;
            reverse(S.begin(),S.end());
            texts.push_back(S);
        };

        cout << "Case #" << i << ": " << suffix_pairs(true,texts) << endl;

    }

    return 0;
}