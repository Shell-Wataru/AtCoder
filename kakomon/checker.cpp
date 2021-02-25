#include <iostream>
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

using namespace std;
using ll = long long;

vector<map<ll, ll>> directions = {
    {
        {1, -1},
        {2, 3},
        {3, 4},
        {4, -1},
        {6, 1},
        {7, -1},
        {8, -1},
        {9, -1},
    },
    {
        {1, 3},
        {2, 4},
        {3, 5},
        {4, 0},
        {6, 2},
        {7, -1},
        {8, -1},
        {9, -1},
    },
    {
        {1, 4},
        {2, 5},
        {3, -1},
        {4, 1},
        {6, -1},
        {7, -1},
        {8, -1},
        {9, -1},
    },
    {
        {1, -1},
        {2, -1},
        {3, -1},
        {4, -1},
        {6, 4},
        {7, -1},
        {8, 0},
        {9, 1},
    },
    {
        {1, -1},
        {2, -1},
        {3, -1},
        {4, 3},
        {6, 5},
        {7, 0},
        {8, 1},
        {9, 2},
    },
    {
        {1, -1},
        {2, -1},
        {3, -1},
        {4, 4},
        {6, -1},
        {7, 1},
        {8, 2},
        {9, -1},
    }};

bool dfs(vector<string> &cards, vector<ll> &order, vector<bool> &status, vector<ll> &positions, vector<ll> &candidates, ll depth)
{
    // for(auto c:candidates){
    //     cout << c;
    // }
    // cout << endl;
    if (depth == 6)
    {
        return true;
    }else if(candidates.size() == 0){
        return false;
    }

    for(auto c:candidates){
        positions.push_back(c);
        status[c] = true;
        vector<ll> next_candidates;
        for(auto d: cards[order[depth]]){
            ll next = directions[c][d-'0'];
            // cout << "!!" << endl;
            // cout << d-'0' << endl;
            // cout << next << endl;

            if (next != -1 && !status[next]){
                next_candidates.push_back(next);
            }
        }
        if (dfs(cards,order,status,positions,next_candidates,depth+1)){
            return true;
        }
        status[c] = false;
        positions.pop_back();
    }
    return false;
}

int main()
{
    // 整数の入力
    vector<string> cards(6);

    for (int i = 0; i < 6; i++)
    {
        cin >> cards[i];
    }
    vector<ll> order(6);
    iota(order.begin(), order.end(), 0);
    do
    {
        vector<bool> initial_status = vector<bool>(6, false);
        vector<ll> positions;
        vector<ll> candidates(6);
        iota(candidates.begin(), candidates.end(), 0);
        if (dfs(cards, order, initial_status, positions,candidates, 0)){
            for(int i = 0;i < 6;i++){
                cout << order[i];
            }
            cout << " ";
            for(int i = 0;i < 6;i++){
                cout << positions[i];
            }
            cout << endl;
        }else{
            for(int i = 0;i < 6;i++){
                cout << order[i];
            }
            cout << " X";
            cout << endl;
            return 0;
        }
    } while (next_permutation(order.begin(), order.end()));
    return 0;
}