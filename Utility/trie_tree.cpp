#include <iostream>
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
#include <cstring>

using namespace std;
using ll = long long;

// cstring をincludeすること
// https://ei1333.github.io/luzhiled/snippets/structure/trie.htmlを一部変更
// 空白を追加する場合はidに注意
// https://atcoder.jp/contests/agc047/tasks/agc047_b
template <int char_size>
struct TrieNode
{
    int nxt[char_size];

    int exist;
    vector<int> accept;

    TrieNode() : exist(0)
    {
        memset(nxt, -1, sizeof(nxt));
    }
};

template <int char_size, int margin>
struct Trie
{
    using Node = TrieNode<char_size>;

    vector<Node> nodes;
    int root;

    Trie() : root(0)
    {
        nodes.push_back(Node());
    }

    void update_direct(int node, int id)
    {
        nodes[node].accept.push_back(id);
    }

    void update_child(int node, int child, int id)
    {
        ++nodes[node].exist;
    }

    void add(const string &str, int str_index, int node_index, int id)
    {
        if (str_index == str.size())
        {
            update_direct(node_index, id);
        }
        else
        {
            const int c = str[str_index] - margin;
            if (nodes[node_index].nxt[c] == -1)
            {
                nodes[node_index].nxt[c] = (int)nodes.size();
                nodes.push_back(Node());
            }
            add(str, str_index + 1, nodes[node_index].nxt[c], id);
            update_child(node_index, nodes[node_index].nxt[c], id);
        }
    }

    void add(const string &str, int id)
    {
        add(str, 0, 0, id);
    }

    void add(const string &str)
    {
        add(str, nodes[0].exist);
    }

    // 帰りがけ順
    // f,gの位置で行きがけ順にできる．
    void query(const string &str, const function<void(int)> &f, const function<void(int)> &g, int str_index, int node_index)
    {
        if (str_index < str.size())
        {
            const int c = str[str_index] - margin;
            if (nodes[node_index].nxt[c] != -1)
            {
                query(str, f, g, str_index + 1, nodes[node_index].nxt[c]);
            }
        }
        g(str_index);
        for (auto &idx : nodes[node_index].accept){
            f(idx);
        }

    }

    void query(const string &str, const function<void(int)> &f, const function<void(int)> &g)
    {
        query(str, f, g, 0, 0);
    }

    int count() const
    {
        return (nodes[0].exist);
    }

    int size() const
    {
        return ((int)nodes.size());
    }
};

int main()
{
    Trie<26, 'a'> trie;
    vector<string> S = {
        "a",
        "ab",
        "abc",
        "abcd",
        "abcde"
    };
    for (auto s:S)
    {
        trie.add(s);
    }

    auto f = [&](int idx)
    {
        cout << S[idx] << endl;
    };
    auto g = [&](int string_idx)
    {

    };
    trie.query("abcd",f,g);
    cout << "!!" << endl;
    trie.query("abe",f,g);
    return 0;
}