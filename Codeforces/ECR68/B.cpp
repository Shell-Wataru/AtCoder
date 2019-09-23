#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    long long q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        ll n,m,min_count;
        vector<string> p;
        vector<set<ll>> x_whites,y_whites;
        cin >> n >> m;
        min_count = n+m-1;
        for(int j = 0;j<n;j++){
            set<ll> s;
            y_whites.push_back(s);
        }
        for(int j = 0;j<m;j++){
            set<ll> s;
            x_whites.push_back(s);
        }

        for (int j = 0;j < n ;j++){
            string s;
            cin >> s;
            p.push_back(s);
        }
        for(int j = 0;j<n;j++){
            for(int k = 0;k<m;k++){
                if (p[j][k] == '.'){
                    y_whites[j].insert(k);
                }
            }
        }

        for(int j = 0;j<m;j++){
            for(int k = 0;k<n;k++){
                if (p[k][j] == '.'){
                    x_whites[j].insert(k);
                }
            }
        }

        for(int j = 0;j<n;j++){
            for(int k = 0;k<m;k++){
                ll current = y_whites[j].size() + x_whites[k].size();
                if (x_whites[k].find(j) != x_whites[k].end()){
                    current--;
                }
                min_count = min(min_count,current);
            }
        }

        cout << min_count << endl;

   }
    return 0;
}