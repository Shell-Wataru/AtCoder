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

// int score(vector<pair<char,int>> &blocks,ll Y, ll Z,map<char,int> &color_points){
//     set<char> used_colors;
//     int value = 0;
//     for(auto &p: blocks){
//         value += color_points[p.first] * p.second + Y * (p.second - 1);
//         used_colors.insert(p.first);
//     }
//     if (used_colors.size() == color_points.size()){
//         value += Z;
//     }
//     return value;
// }

// int remove_color_score(vector<pair<char,int>> &blocks,ll Y, ll Z,map<char,int> &color_points,char remove_color){
//     vector<pair<char,int>> color_removed_blocks;
//     for(auto p: blocks){
//         if (p.first == remove_color){
//             continue;
//         }
//         if (color_removed_blocks.size() == 0 || color_removed_blocks.back().first != p.first){
//             color_removed_blocks.push_back({p.first,p.second});
//         }else{
//             color_removed_blocks.back().second += p.second;
//         }
//     }
//     return score(color_removed_blocks,Y,Z,color_points);
// }

// int all_color_score(vector<pair<char,int>> &blocks,ll Y, ll Z,map<char,int> &color_points){
//     vector<pair<char,int>> all_color_blocks;
//     for(auto p: blocks){
//         if (all_color_blocks.size() == 0 || all_color_blocks.back().first != p.first){
//             all_color_blocks.push_back({p.first,p.second});
//         }else{
//             all_color_blocks.back().second += p.second;
//         }
//     }
//     return score(all_color_blocks,Y,Z,color_points);
// }

int main()
{
    // 整数の入力
    ll n,m,Y,Z;
    map<char,int> color_points;
    vector<pair<char,int>> blocks;
    map<pair<char,set<char>>,int> best_scores;
    best_scores[{'-',set<char>()}] = 0;
    cin >> n >> m >> Y >> Z;
    for(int i = 0;i < m;i++){
        char c;
        int p;
        cin >> c >> p;
        color_points[c] = p;
    }
    for(int i = 0;i < n;i++){
        char c;
        cin >> c;
        if (blocks.size() == 0 || blocks.back().first != c){
            blocks.push_back({c,1});
        }else{
            if (Y + color_points[c] > 0){
                blocks.back().second += 1;
            }
        }
    }
    for(auto p:blocks){
        map<pair<char,set<char>>,int> next_best_scores = best_scores;
        for(auto best_score: best_scores){
            char last_color = best_score.first.first;
            set<char> used_colors = best_score.first.second;
            used_colors.insert(p.first);
            pair<char,set<char>> key = make_pair(p.first,used_colors);
            int plus;
            if (p.first == last_color){
                plus = color_points[p.first] * p.second + Y * p.second;
            }else{
                plus = color_points[p.first] * p.second + Y * (p.second - 1);
            }

            if (next_best_scores.find(key) == next_best_scores.end() ||  best_score.second + plus > next_best_scores[key]){
                next_best_scores[key] = best_score.second + plus;
            }
        }
        best_scores = next_best_scores;
    }

    ll best = 0;
    for(auto p: best_scores){
        // cout << p.first.first << ",";
        // for(auto used_char: p.first.second){
        //     cout << used_char << " ";
        // }
        ll score;
        if (p.first.second.size() == color_points.size()){
            score = p.second + Z;
        }else{
            score = p.second;
        }
        best = max(best,score);
    }
    cout << best << endl;
    return 0;
}