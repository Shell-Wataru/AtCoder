#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <limits>
#include <cmath>
#include <iomanip>
#include <functional>
#include <random>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;

const int NONE = -1;

struct S
{
    long long node, cost, prev;
    S(long long n, long long c, long long p) : node(n), cost(c), prev(p) {}
    bool operator>(const S &s) const
    {
        return cost > s.cost;
    }
};

class G
{
    long long n;
    vector<map<long long, long long> > cost;

  public:
    vector<long long> minc;
    vector<long long> prev;

    G(long long n, vector<map<long long, long long> > cost) : n(n), cost(cost), minc(n, NONE), prev(n, NONE) {}

    void dijkstra(long long start)
    {
        minc.assign(n, NONE);
        priority_queue<S, vector<S>, greater<S> > pq;
        pq.push(S(start, 0, NONE));
        while (!pq.empty())
        {
            S s = pq.top();
            pq.pop();
            if (minc[s.node] != NONE)
            {
                continue;
            }
            minc[s.node] = s.cost;
            prev[s.node] = s.prev;
            for (auto itr = cost[s.node].begin(); itr != cost[s.node].end(); ++itr)
            {
                pq.push(S(itr->first, s.cost + itr->second, s.node));
            }
        }
    }

    void output()
    {
        for (int i = 0; i < n; i++)
        {
            cout << i << ":" << minc[i] << endl;
        }
    };

    vector<ll> path(ll last)
    {
        vector<ll> stack;
        stack.push_back(last);
        while(prev[stack.back()] != NONE){
            stack.push_back(prev[stack.back()]);
        }
        reverse(stack.begin(),stack.end());
        return stack;
    };
};

bool can_move(string &s1, string &s2){
    if (s1.size() != s2.size()){
        return false;
    }else{
        ll difference = 0;
        for(int i = 0; i< s1.size();i++){
            if(s1[i] != s2[i]){
                difference++;
            }
        }
        return difference <= 1;
    }
}

int main()
{
    // 整数の入力
    set<string> word_list;
    map<string,ll> dictionary;
    map<ll,string> inverse_dictionary;
    string first,last;
    ll N;
    cin >> first >> last;
    cin >> N;
    word_list.insert(first);
    word_list.insert(last);
    for(int i = 0;i<N;i++){
        string w;
        cin >> w;
        word_list.insert(w);
    }
    if (first == last){
        cout << 0 << endl;
        cout << first << endl;
        cout << last << endl;
        return 0;
    }

    ll index = 0;
    for(auto s:word_list){
        dictionary[s] = index;
        inverse_dictionary[index] = s;
        index++;
    }
    vector<map<long long, long long>> cost(dictionary.size(),map<long long, long long>());
    for(auto s1:word_list){
        for(auto s2:word_list){
            if (s1 == s2){
                cost[dictionary[s1]][dictionary[s2]] = 0;
            }else if(can_move(s1,s2)){
                cost[dictionary[s1]][dictionary[s2]] = 1;
            }
        }
    }
    G dickstra(dictionary.size(),cost);
    dickstra.dijkstra(dictionary[first]);
    ll min_cost = dickstra.minc[dictionary[last]];

    if (min_cost == NONE){
        cout << -1 << endl;
        return 0;
    }else{
        cout << min_cost - 1 << endl;
        vector<ll> path = dickstra.path(dictionary[last]);
        for(auto s:path){
            cout << inverse_dictionary[s] << endl;
        }
        return 0;
    }
}