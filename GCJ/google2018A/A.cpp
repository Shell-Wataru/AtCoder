#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
using namespace std;
using ll = long long;

bool is_possible(ll R, ll C, ll H, ll V, string *texts)
{
    vector<ll> h_indexes;
    vector<ll> v_indexes;
    ll *row_sum = new ll[R];
    ll *column_sum = new ll[C];
    fill(row_sum, row_sum + R, 0);
    fill(column_sum, column_sum + C, 0);
    ll total_chocos = 0;
    for (int j = 0; j < R; j++)
    {
        for (int k = 0; k < C; k++)
        {
            if (texts[j][k] == '@')
            {
                total_chocos++;
                row_sum[j]++;
                column_sum[k]++;
            }
        }
    };

    if (total_chocos % ((H + 1) * (V + 1)) != 0)
    {
        return false;
    }
    else
    {
        ll block_chocos = total_chocos / ((H + 1) * (V + 1));
        ll row_block_chocos = total_chocos / (H + 1);
        ll current_row_block_total = 0;
        h_indexes.push_back(0);
        for (int j = 0; j < R; j++)
        {
            current_row_block_total += row_sum[j];
            if (current_row_block_total == row_block_chocos)
            {
                current_row_block_total = 0;
                h_indexes.push_back(j + 1);
            }
        }

        ll column_block_chocos = total_chocos / (V + 1);
        ll current_column_block_total = 0;
        v_indexes.push_back(0);
        for (int j = 0; j < C; j++)
        {
            current_column_block_total += column_sum[j];
            if (current_column_block_total == column_block_chocos)
            {
                current_column_block_total = 0;
                v_indexes.push_back(j + 1);
            }
        }

        if (h_indexes.size() <= H + 1 || v_indexes.size() <= V + 1)
        {
            return false;
        }
        else
        {
            for (int j = 0; j < H + 1; j++)
            {
                for (int k = 0; k < V + 1; k++)
                {
                    ll current_block_chocos = 0;
                    for (int l = h_indexes[j]; l < h_indexes[j+1]; l++)
                    {
                        for (int m = v_indexes[k]; m < v_indexes[k+1]; m++)
                        {
                            if (texts[l][m] == '@'){
                                current_block_chocos++;
                            }
                        }
                    }

                    if (current_block_chocos != block_chocos){
                        return false;
                    }
                }
            }
            return true;
        }
    }
}

int main()
{
    // 整数の入力
    ll T;
    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        ll R, C, H, V;
        cin >> R >> C >> H >> V;
        string *texts = new string[R];
        for (int j = 0; j < R; j++)
        {
            cin >> texts[j];
        };

        if (is_possible(R,C,H,V,texts)){
            cout << "Case #" << i << ": " << "POSSIBLE" << endl;
        }else{
            cout << "Case #" << i << ": " << "IMPOSSIBLE" << endl;
        }
    }

    return 0;
}