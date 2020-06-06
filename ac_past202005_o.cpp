//https://atcoder.jp/contests/past202005-open/tasks/past202005_o
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
template<int NV, class V> struct MinCostFlow {
    struct edge {
        int to, capacity; V cost; int reve; edge(int a, int b, V c, int d) {
            to = a; capacity = b; cost = c; reve = d;
        }
    }; vector<edge> E[NV];
    int prev_v[NV], prev_e[NV]; V dist[NV];
    void add_edge(int x, int y, int cap, V cost) {
        E[x].push_back(edge(y, cap, cost, (int)E[y].size()));
        E[y].push_back(edge(x, 0, -cost, (int)E[x].size() - 1));
    }
    V mincost(int from, int to, int flow) {
        V res = 0; int i, v; rep(i, 0, NV) prev_v[i] = 0;
        rep(i, 0, NV) prev_e[i] = 0; while (flow > 0) {
            fill(dist, dist + NV, infl); dist[from] = 0;
            priority_queue<pair<V, int> > Q; Q.push(make_pair(0, from)); while (Q.size()) {
                V d = -Q.top().first; int cur = Q.top().second; Q.pop(); if (dist[cur] != d) continue;
                if (d == infl) break; rep(i, 0, E[cur].size()) {
                    edge& e = E[cur][i];
                    if (e.capacity > 0 && dist[e.to] > d + e.cost) {
                        dist[e.to] = d + e.cost; prev_v[e.to] = cur;
                        prev_e[e.to] = i; Q.push(make_pair(-dist[e.to], e.to));
                    }
                }
            }
            if (dist[to] == infl) return -1; int lc = flow;
            for (v = to; v != from; v = prev_v[v]) lc = min(lc, E[prev_v[v]][prev_e[v]].capacity);
            flow -= lc; res += lc * dist[to]; for (v = to; v != from; v = prev_v[v]) {
                edge& e = E[prev_v[v]][prev_e[v]]; e.capacity -= lc; E[v][e.reve].capacity += lc;
            }
        }
        return res;
    }
};
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan0
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int N, M, A[505], B[505], R[3];
//---------------------------------------------------------------------------------------------------
ll add(int i, int j) {
    ll res = A[j];
    rep(_, 0, i + 1) res *= B[j];
    return res % R[i];
}
ll del(int i, int j) {
    ll res = A[j];
    rep(_, 0, i + 1) res *= B[j];
    return res;
}
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N >> M;
    rep(i, 0, N) cin >> A[i];
    rep(i, 0, N) cin >> B[i];
    rep(i, 0, 3) cin >> R[i];

    MinCostFlow<510, ll> mcf;

    int s = N;
    int round[3] = { N + 1, N + 2, N + 3 };
    int t = N + 4;

    rep(r, 0, 3) mcf.add_edge(s, round[r], M, 0);
    rep(r, 0, 3) rep(i, 0, N) mcf.add_edge(round[r], i, 1, -add(r, i));
    rep(i, 0, N) {
        ll cst1 = del(0, i);
        ll cst2 = del(1, i);
        ll cst3 = del(2, i);
        mcf.add_edge(i, t, 1, cst1);
        mcf.add_edge(i, t, 1, (cst2 - cst1));
        mcf.add_edge(i, t, 1, (cst3 - cst2));
    }

    ll ans = mcf.mincost(s, t, M * 3);
    ans *= -1;
    cout << ans << endl;
}




/* ///////////////////////// writeup1 start
# 前提知識
- [最小費用流](https://www.hamayanhamayan.com/entry/2017/05/09/120428)
///////////////////////// writeup2 start
問題を見ると色々な制約がある。
各ラウンド事に命中させると点数を得ることができ、かつ、全ラウンドが終了したときの状態で点数が減算される。
最初はDPを疑い、制約の大きさを見ながら色々なDP定義を当てはめてみるが、やはりどうにも減算をうまく扱えない。
しかも各ラウンドでは必ずM本の異なる棒にする必要もあるし…
ん？必ずM本が確定する？最小費用流か？（唐突）

ということで最小費用流を使うのだが、自分自身も最近はあまり見てない気がするので、最近の人は知らないかも。
知らない人は、どこかで勉強してきてほしい。
いや、最小費用流を学ぶ前に最大フローを学んでからの方がいいかもしれない。
なお、一般に「フロー問題」とか言うと、最大フローか最小費用流になる。

フローの形は以下の通りである。

todo

減算処理の部分だけ変な感じになっているので説明する。
減算ルールは
0本なら0減
1本ならAB減
2本ならAB^2減
3本ならAB^3減
となる。だが、フローではそのような表現はできないので、流量1の辺をいくつも配置することで疑似的にそのような状況を作る。
以下のような辺を貼る。
(1, AB)
(1, AB^2-AB)
(1, AB^3-AB^2)
1個だけ輪がかかっているときは一番上の辺だけ使われる。
2個かかっているときは上の2つ。
3個かかっているならば、全部使われるので、結果的には、元の減算ルールと等しくなる。
このように差分を辺として増やすことで累乗のコストを表現するテクがある。

あとは、最小費用流は最小を求めるものなので、全部のコストを正負逆転すること。
そうすると、得られた最小値を正負逆転すると、最大コストにすることができる。
///////////////////////// writeup2 end */
