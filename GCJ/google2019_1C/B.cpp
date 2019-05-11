#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    ll T,F;
    cin >> T >> F;
    cerr << T << " " << F << endl;
    for (int i = 1; i <= T; i++)
    {
        string answer = "";
        string *figures = new string[119];

        fill(figures,figures+119,"");
        ll normal = 24;

        for(int k = 1;k <= 4;k++){
            cerr << "---------------" << k << endl;
            int counts[5];
            fill(counts,counts+5,0);

            for (int j = 0;j< 119;j++){
                if(figures[j] != answer){
                    continue;
                }
                cerr << j * 5 + k << endl;
                cout << j * 5 + k << endl;
                char c;
                cin >> c;
                cerr << c << endl;
                figures[j] += c;
                counts[c - 'A']++;
            }

            ll first_index;
            cerr << "normal" << normal << endl;
            for (int j = 0;j< 5;j++){
                cerr << j << ":" << counts[j] <<  endl;
                bool already = false;
                for (int l = 0;l< answer.size();l++){
                    if (answer[l] - 'A' == j){
                        already = true;
                    }
                }
                if (counts[j] == normal - 1 && !already){
                    cerr << "hogehoge" << endl;
                    first_index = j;
                }
            }
            normal = normal/(5-k);
            answer += 'A' + first_index;
            cerr << answer << endl;
        }
        for (int j = 0;j< 5;j++){
                bool already = false;
            for (int l = 0;l< answer.size();l++){
                if (answer[l] - 'A' == j){
                    already = true;
                }
            }

            if (!already){
                answer += 'A' + j;
            }


        }

        for (int j = 0; j < F - 150; j++){
            cout << 1 << endl;
            char c;
            cin >> c;
        }
        cerr << answer << endl;
        cout << answer << endl;
        string result;
        cin >> result;
        cerr << result << endl;
    }

    return 0;
}