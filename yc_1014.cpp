//https://yukicoder.me/problems/no/1014
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



struct DirectedGraphRangeEdge {
    int NV;
    vector<vector<int>> E;
    void init(int n) {
        NV = 1; while (NV < n) NV *= 2;
        E.resize(NV * 2);
        rep(i, 1, NV) {
            E[i].push_back(i * 2);
            E[i].push_back(i * 2 + 1);
        }
    }
    // [x, y)
    void add(int from, int x, int y) { add(from + NV, x, y, 0, NV, 1); }
    void add(int from, int x, int y, int l, int r, int k) {
        if (r <= x || y <= l) return;
        if (x <= l && r <= y) {
            E[from].push_back(k);
            return;
        }
        add(from, x, y, l, (l + r) / 2, k * 2);
        add(from, x, y, (l + r) / 2, r, k * 2 + 1);
    }
};




int N;
DirectedGraphRangeEdge dgre;
vector<tuple<int, int, int, int>> ABCi;
ll ans[101010];
//---------------------------------------------------------------------------------------------------
ll memo[1 << 19]; // -1: not visited      -2: pending     0<=: cached    infl: BAN
ll dfs(int cu) {
    if (0 <= memo[cu]) return memo[cu];
    if (memo[cu] == -2) return memo[cu] = infl;
    memo[cu] = -2;

    ll res = 0;
    fore(to, dgre.E[cu]) chmax(res, dfs(to));

    if (res == infl) return infl;
    if (dgre.NV <= cu) res += get<1>(ABCi[cu - dgre.NV]);
    return memo[cu] = res;
}
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N;
    dgre.init(N);
    rep(i, 0, N) {
        int a, b, c; cin >> a >> b >> c;
        ABCi.push_back(make_tuple(a, b, c, i));
    }
    sort(all(ABCi));

    rep(i, 0, N) {
        int b, c, _; tie(_, b, c, _) = ABCi[i];

        int idx = lower_bound(all(ABCi), make_tuple(b - c + 1, -1, -1, -1)) - ABCi.begin();

        if (i < idx) {
            if (0 < i) dgre.add(i, 0, i);
            if (i + 1 < idx) dgre.add(i, i + 1, idx);
        } else dgre.add(i, 0, idx);
    }

    rep(i, 0, 1 << 19) memo[i] = -1;
    rep(i, 0, N) ans[get<3>(ABCi[i])] = dfs(i + dgre.NV);

    rep(i, 0, N) {
        if (ans[i] == infl) printf("BAN\n");
        else printf("%lld\n", ans[i]);
    }
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
技xから技yへコンボがつなげられる関係を有向辺として考えることにする。
すると、N頂点の有向グラフが形成できる。
このグラフをもとにアルゴリズムを考える。

まずは、簡単化して解いてみよう。
無限コンボがないとしておく。
この時、有向グラフはループがない、DAGとなる。

このときの答えは、メモ化をしながらDFSしていけば求めることができる。
dfs(cu) := 頂点cuから遷移を始めたときのコンボ威力の最大値
cuからの遷移先をto配列とすると、のようにして計算していけばいい。
dfs(cu) = max(dfs(to[0]), dfs(to[1]), dfs(to[2]), ...) + B[cu]
dfs(cu)の値はメモ化すれば、全体O(N^2)で計算ができる。
だが、これは間に合わない。

これを発展して解いていく。
技をAでソートしておくと、ある技からコンボをつなげられる技は、区間で表現できる。
こうしておくと、今回の有向グラフは、ある頂点からの遷移先は、ある区間の頂点となる。
このように区間に対して効率的に有向辺を貼る問題に対するテクニックが存在する。
セグメントツリーが理解できてないと、このテクニックは理解できない。
もしセグメントツリーが分からない場合は勉強してこよう。

セグメントツリーの要領で有向グラフをあらかじめ作成しておく。
例えば、頂点0,1,2,3があった場合は、それを+4しておき1～3をセグメントツリーのように二分木っぽく有向辺を貼る。
以下のような感じ。

TODO: 図

すると、例えば、0から1,2,3へ有向辺を貼りたい場合は、
4 -> 5
4 -> 3
へ2箇所に有向辺を貼ることで遷移を表現することができる。
こうすると、区間に対して辺を貼る本数がlogN本くらいでよくなるので、遷移数を格段に減らすことができる。
よって、こうして作成した有向グラフに対して同様のDFSをすればいい。
注意は、追加した頂点では、威力は追加されないようにしておく。

最後にほったらかしにしておいた無限コンボ、BANの話であるが、
DFSをするときに、遷移先のDFSを始める前に自分に「処理中フラグ」を立てておく。
こうすることで、DFSを進めていき、自分に戻ってきて処理中フラグであれば、ループ発生を検知できる。
その場合は、結果としてBANを返すようにしておけばいい。
BANは∞にしておくと、子供のmaxを取って1つでも∞があれば、結果を∞にできるので、おすすめ。
///////////////////////// writeup2 end */
