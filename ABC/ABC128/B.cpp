#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
using namespace std;

struct r {
    long long index;
    string s;
    long long p;
    bool operator<(const r &another) const
    {
        if (s == another.s){
            return p > another.p;
        }else{
            return s < another.s;
        }
    };
};

int main()
{
    // 整数の入力
    long long N,D,i;
    vector<r> rs;
    cin >> N;

    for(int i = 0;i< N;i++){
        r new_r;
        new_r.index = i+1;
        cin >> new_r.s >> new_r.p;
        rs.push_back(new_r);
    }
    sort(rs.begin(),rs.end());
    for (auto a: rs){
        cout << a.index << endl;
    }

    return 0;
}