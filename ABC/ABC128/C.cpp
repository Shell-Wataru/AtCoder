#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>

using namespace std;

struct s{
    vector<long long> denkyus;
};
int main()
{
        // 整数の入力
    long long N,M,total;
    total = 0;
    vector<s> ss;
    vector<long long > ps;

    cin >> N >> M;
    for (int i=0;i<N;i++){
        s new_s;
        ss.push_back(new_s);
    }
    for (int i = 0;i<M;i++){
        long long k;
        cin >> k;
        for(int j = 0;j< k;j++){
            long long s_index;
            cin >> s_index;
            ss[s_index - 1].denkyus.push_back(i);
        }
    }
    for (int i=0;i<M;i++){
        long long temp_p;
        cin >> temp_p;
        ps.push_back(temp_p);
    }

    // {0, 1, ..., n-1} の部分集合の全探索
    for (int bit = 0; bit < (1<<N); ++bit) {
        int *dekyu_status = new int[M];
        fill(dekyu_status,dekyu_status+M,0);
        for (int i = 0; i < N; ++i) {
            if (bit & (1<<i)) { // i が bit に入るかどうか
                for (auto dekyu_index: ss[i].denkyus){
                    dekyu_status[dekyu_index]++;
                }
            }
        }

        bool cleared = true;
        for (int i = 0; i <M ;i++) {
            if (dekyu_status[i] % 2  != ps[i]){
                cleared = false;
            }
        }

        if(cleared){
            total++;
        }
    }

    cout << total << endl;
    return 0;
}