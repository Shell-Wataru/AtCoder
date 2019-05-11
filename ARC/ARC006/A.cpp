#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>

using namespace std;
int main()
{
    // 整数の入力
    long long temp;
    vector<long long> Es;
    bool includesB = false;
    long long B;
    vector<long long> Ls;
    for (int i = 0; i < 6; i++)
    {

        cin >> temp;
        Es.push_back(temp);
    }
    cin >> B;

    for (int i = 0; i < 6; i++)
    {
        cin >> temp;
        Ls.push_back(temp);
    }

    long long count = 0;
    for (int i = 0;i < 6;i++){
        if (B == Ls[i]){
            includesB = true;
        }
        auto itr = std::find(Es.begin(), Es.end(), Ls[i]);    //  最初の要素5へのイテレータを返す
        if( itr != Es.end() ) {     // 発見した場合
            count++;
        }
    }

    if (count == 6){
        cout << 1 << endl;
    }else if (count ==5){
        if (includesB){
            cout << 2 << endl;
        }else{
            cout << 3 << endl;
        }
    }else if (count == 4){
        cout << 4 << endl;
    }else if (count == 3){
        cout << 5 << endl;
    }else{
        cout << 0 << endl;
    }
    return 0;
}