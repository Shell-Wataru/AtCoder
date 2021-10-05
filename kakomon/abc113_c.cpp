#include <string>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <iomanip>
using namespace std;
using ll = long long;

int main(){
    ll N,M;
    cin >> N >> M;
    vector<pair<ll,ll>> cities(M);
    map<pair<ll,ll>,ll> answers;
    map<ll,ll>  city_counts;
    map<ll,vector<ll>>  prefecture_cities;
    for(int i = 0;i < M;i++){
        cin >> cities[i].first >> cities[i].second;
        prefecture_cities[cities[i].first].emplace_back(cities[i].second);
    }
    for(auto &p:prefecture_cities){
        sort(p.second.begin(),p.second.end());
        for(int j = 0;j < p.second.size();j++){
            answers[{p.first,p.second[j]}] = j+1;
        }
    }

    for(int i = 0;i < M;i++){
        ll p = cities[i].first;
        ll number = answers[cities[i]];
        cout << setw(6) << setfill('0') << p;
        cout << setw(6) << setfill('0') << number << "\n";
    }
    cout << flush;
    return 0;
}