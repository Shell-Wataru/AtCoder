#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <ctime>
#include <map>

using namespace std;

int main()
{
    // 整数の入力
    long long N,M,listened_disc;
    map<long long,long long> cd_case;
    long long current = 0;

    cin >> N >> M;
    for (int i = 0;i <= N;i++){
        cd_case[i] = i;
    }
    for (int i = 0;i < M;i++){
        cin >> listened_disc;
        long long cd_index = cd_case[listened_disc];
        cd_case[listened_disc] = 0;
        cd_case[current] = cd_index;
        current = listened_disc;
    }

    long long *list = new long long[N+1];
    for (int i = 0;i <= N;i++){
        list[cd_case[i]] = i;
    }

    cout << "--" << endl;
    for (int i = 1;i <= N;i++){
        cout << list[i]<< endl;
    }

    return 0;
}