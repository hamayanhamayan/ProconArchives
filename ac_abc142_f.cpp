//https://atcoder.jp/contests/abc142/tasks/abc142_f
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
//#pragma GCC optimize ("-O3")
using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
//---------------------------------------------------------------------------------------------------
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/

int N, M, A[2020], B[2020];
vector<int> E[1010];
bool vis[1010];
int dist[1010], back[1010];
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N >> M;
    rep(i, 0, M) {
        cin >> A[i] >> B[i];
        A[i]--;
        B[i]--;
    }

    int mi = inf;
    vector<int> ans;
    rep(er, 0, M)
    {
        rep(i, 0, N) E[i].clear();
        rep(i, 0, M) if (er != i) E[A[i]].push_back(B[i]);
        int st = A[er];
        int gr = B[er];

        rep(i, 0, N) {
            vis[i] = false;
            dist[i] = 0;
        }

        queue<int> que;
        que.push(gr);
        vis[gr] = true;
        dist[gr] = 0;

        while(!que.empty()) {
            int cu = que.front();
            que.pop();
            fore(to, E[cu]) if(!vis[to]) {
                vis[to] = true;
                dist[to] = dist[cu] + 1;
                back[to] = cu;
                que.push(to);
            }
        }

        if (!vis[st]) continue;

        int len = dist[st] + 1;
        if (chmin(mi, len)) {
            ans.clear();

            int x = st;
            while(x != gr) {
                ans.push_back(x);
                x = back[x];
            }
            ans.push_back(gr);
        }
    }

    if (mi == inf) {
        cout << -1 << endl;
        return;
    }

    sort(all(ans));

    int K = ans.size();
    printf("%d\n", K);
    fore(i, ans) printf("%d\n", i + 1);
}

/* ///////////////////////// writeup1 start
- [BFS](https://www.hamayanhamayan.com/entry/2018/06/16/093035)
///////////////////////// writeup2 start
まず、どこから手を付けようかという感じであるが、NもMも制約がゆるい。
うーん。
作りたいグラフはサイクルである。
サイクルだけのグラフを作りたい。
これ枝刈り全探索通るのでは？
いや、1つ閉路を見つけて、そこから最小化していけばいい？
いや、最小のサイクルを探せばいいのか。

最小のサイクルを探す。
もし、あればそれが答え。
辺に注目すると、a->bの辺を削除した上で、bからaへの最短距離を計算する。
これで、a->b->...aのサイクルとその長さが得られる。
この長さが最小のものが答え。サイクルを復元していこう。
最短経路はBFSで計算可能。
///////////////////////// writeup2 end */
