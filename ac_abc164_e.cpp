//https://atcoder.jp/contests/abc164/tasks/abc164_e
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
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan0
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int N, M, S;
vector<pair<int,int>> E[50];
int A[101], B[101], C[50], D[50];
ll dist[50][3010];
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
bool vis[50][3010];
ll ans[50];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> M >> S;
    chmin(S, 3000);
	rep(i, 0, M) {
		int u, v; cin >> u >> v; u--; v--;
		cin >> A[i] >> B[i];
		E[u].push_back({ v, i });
		E[v].push_back({ u, i });
	}
	rep(i, 0, N) cin >> C[i] >> D[i];

    rep(i, 0, N) rep(s, 0, 3001) dist[i][s] = infl;
    rep(i, 0, N) rep(s, 0, 3001) vis[i][s] = false;
    rep(i, 0, N) ans[i] = infl;

    min_priority_queue<pair<ll, int>> que;

    dist[0][S] = 0;
    que.push({ 0, 0 * 5010 + S });

    while (!que.empty()) {
        auto q = que.top(); que.pop();

        ll cst = q.first;
        int cu = q.second / 5010;
        int s = q.second % 5010;

        if (vis[cu][s]) continue;
        vis[cu][s] = true;

        chmin(ans[cu], cst);

        fore(p, E[cu]) {
            int to = p.first;
            int i = p.second;
            if (s < A[i]) continue;

            ll cst2 = cst + B[i];
            if (chmin(dist[to][s - A[i]], cst2)) que.push({ dist[to][s - A[i]], to * 5010 + s - A[i] });
        }

        ll cst2 = cst + D[cu];
        int s2 = min(3000, s + C[cu]);
        if (chmin(dist[cu][s2], cst2)) que.push({ dist[cu][s2], cu * 5010 + s2 });
    }

    rep(i, 1, N) printf("%lld\n", ans[i]);
}





/* ///////////////////////// writeup1 start
# 前提知識
- [拡張ダイクストラ法](https://www.hamayanhamayan.com/entry/2017/05/14/134606)
///////////////////////// writeup2 start
まず、今回の問題はダイクストラを理解していないと解けない。
そちらが分からない場合は、より簡単な問題でダイクストラを勉強することをオススメする。
以下、拡張ダイクストラについて少し触れてから解説する。

拡張ダイクストラとは何だろう。
端的に言うと、普通のダイクストラは(頂点)を状態として最短距離を求めるが、
拡張ダイクストラでは、(頂点,何か)のように複数要素で1状態として考えて、最短距離を求めるというもの。
それだけである。
今回は、「(頂点, 持っている銀貨の枚数)を状態として、ある頂点にいて、ある銀貨の枚数を持っているときの
これまでにかかった時間の最短を求める」ということをする。

なぜこれができるか考えてみよう。
今回の問題で最も見落としてはいけない制約が「A[i]≦50」である。
仮に1回も金貨の交換を行わなかった場合に必要な銀貨は頂点が50個あり、各辺で最大50銀貨必要なので、
2500枚くらいが必要な最大枚数となる。
逆に言うと、3000枚以上くらいあれば、絶対金貨を交換する必要はない。
よって、Sが10^9の上限があっても、持っている銀貨は3000枚以下を想定すれば十分であるということになる。
よって、ダイクストラで(頂点, 持っている銀貨の枚数)というのを状態とするが、状態数は50*3000くらいで、
計算できる量になる。

さて、ダイクストラできそうな見た目になってきたので、後は遷移を考える。
頂点から頂点へ普通に遷移するのは問題ないとして、金貨の交換はどう遷移させるかというのが問題になる。
例えば銀貨を3枚持っていて、今いる都市では金貨1枚を銀貨4枚にできるとする。
すると、遷移は7,11,15,19,...枚への遷移があるように見えるが、実際は金貨1枚の交換だけを考えればいい。
11枚への遷移が必要ではないか？と考えるかもしれないが、他の状態として銀貨7枚持っている状態も別で考えるので、
そこからの遷移で11枚はカバーすればいい。
このように複数回動作を行える場合であっても、1回だけ動作を行うことで連鎖的に複数回の操作をカバーできたりする。
これは典型テクなので、覚えておくといいだろう。

あとは、ダイクストラの実装を頑張ると答え。

///////////////////////// writeup2 end */
