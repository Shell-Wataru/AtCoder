#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
using namespace std;
using ll = long long;

string find_strategy(ll A,string *robots){
    string impossible = "IMPOSSIBLE";
    string tejun = "";

    ll max_string_length = 0;
    for(int i = 0;i < A;i++){
        if (max_string_length < robots[i].size()){
            max_string_length = robots[i].size();
        }
    }

    bool *won = new bool[(int)A];
    fill(won,won+A,false);

    for(int i = 0;i <= max_string_length;i++){
        bool pa = false;
        bool choki = false;
        bool goo = false;
        for(int j = 0;j < A;j++){
            if (!won[j]){
                char te = robots[j][i % robots[j].size()];
                 if(te == 'R'){
                     goo = true;
                 }
                 if(te == 'P'){
                     pa = true;
                 }
                 if(te == 'S'){
                     choki = true;
                 }
            }
        }

        if (goo && pa && choki){
            return impossible;
        }else if (goo && pa && !choki){
            tejun.append("P");
        }else if (goo && !pa && choki){
            tejun.append("R");
        }else if (!goo && pa && choki){
            tejun.append("S");
        }else if (goo && !pa && !choki){
            tejun.append("P");
            return tejun;
        }else if (!goo && !pa && choki){
            tejun.append("R");
            return tejun;
        }else if (!goo && pa && !choki){
            tejun.append("S");
            return tejun;
        }else{
            return tejun;
        }
        char last = tejun[tejun.size() - 1];
        for(int j = 0;j < A;j++){
            if (!won[j]){
                char te = robots[j][i % robots[j].size()];
                 if(te == 'R' && last == 'P'){
                     won[j] = true;
                 }
                 if(te == 'P' && last == 'S'){
                     won[j] = true;
                 }
                 if(te == 'S' && last == 'R'){
                     won[j] = true;
                 }
            }
        }

    }
    return tejun;
}
int main()
{
    // 整数の入力
    ll T;
    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        ll A;
        cin >> A;
        string *robots = new string[A];
        for (int j = 0; j < A; j++)
        {
            cin >> robots[j];
        }

        string strategy = find_strategy(A,robots);
        cout << "Case #" << i << ": " << strategy << endl;
    }

    return 0;
}