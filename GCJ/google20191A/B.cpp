#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
using namespace std;
using ll = long long;

long long gcd(long long a, long long b){
    if (a%b == 0){
        return b;
    }else{
        return gcd(b,a%b);
    }
}
int main()
{
    // 整数の入力
    ll T;
    cin >> T;

    for(int i = 1; i<= T;i++){
        ll R,C;
        cin >> R >> C;
        ll small = min(R,C);
        ll big = max(R,C);
        if (small == 2){
            if (big <= 4){
               cout << "Case #" << i << ": " << "IMPOSSIBLE" << endl;
               continue;
            }
        }else if (small == 3){
            if (big <= 3){
               cout << "Case #" << i << ": " << "IMPOSSIBLE" << endl;
               continue;
            }
        }

        cout << "Case #" << i << ": " << "POSSIBLE" << endl;
        ll first_move,second_move;
        for (int j = small + 3; j< small * big;j++){
            if (gcd(small,j) == 1 && j != small + big - 1 && j/small != j%small &&  j/small + 1 != small - j % small){
                first_move = j;
                break;
            }
        }

        for (int j = small + 3; j< small * big;j++){
            if (gcd(small,j) == 1 && j != small + big - 1 && j/small != j%small &&  j/small + 1 != small - j % small){
                second_move = j;
                break;
            }
        }

        ll postion = 0;
        // first_move = 11;
        // second_move = 7;
        set<long long> s;
        cout << first_move << "-" << second_move <<  endl;
        for (int k = 0; k < small * big;k++){
            ll before_a,before_b,now_a,now_b;
            before_a = postion % small;
            before_b = postion / small;

            if (k % 2 == 0){
                postion = (postion + first_move) % (small * big);
            }else{
                postion = (postion + second_move) % (small * big);
            }

            s.insert(postion);
            if (small == R){
                cout << (postion % small) + 1 << " " << (postion/small) + 1 << endl;
            }else {
                cout << (postion/small) + 1 << " " << (postion % small) + 1 << endl;
            }

            now_a = postion % small;
            now_b = postion / small;
            ll diff_x = before_a - now_a;
            ll diff_y = before_b - now_b;
            if (diff_x == 0 || diff_y == 0 || abs(diff_x) == abs(diff_y)){
                cout << "Error!!!!!" << endl;
            }
        }
        cout << "size:" << s.size() << endl;

    }

    return 0;
}