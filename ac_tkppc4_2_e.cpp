//https://atcoder.jp/contests/tkppc4-2/tasks/tkppc4_2_e
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
struct UnionFind {
    vector<int> par; // uf(x,y)->y
    UnionFind() {}
    UnionFind(int NV) { init(NV); }
    void init(int NV) { par.clear(); rep(i, 0, NV) par.push_back(i); }
    void reset() { rep(i, 0, par.size()) par[i] = i; }
    int operator[](int x) { return par[x] == x ? x : par[x] = operator[](par[x]); }
    void operator()(int x, int y) { x = operator[](x); y = operator[](y); if (x != y) par[x] = y; }
};
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int N, M, Q, A[101010], B[101010];
ll C[101010];
ll ans[101010];
int sz[101010];
//---------------------------------------------------------------------------------------------------
multiset<int> ms;
void erase(int x) {
    auto ite = ms.find(x);
    ms.erase(ite);
}
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N >> M >> Q;
    map<ll,vector<int>> edges;
    rep(i, 0, M) {
        cin >> A[i] >> B[i] >> C[i];
        A[i]--; B[i]--;
        edges[C[i]].push_back(i);
    }

    UnionFind uf(N);
    rep(i, 0, N) ms.insert(1);
    rep(i, 0, N) sz[i] = 1;
    rep(i, 0, 101010) ans[i] = -1;
    int pre = 1;
    ans[1] = 0;
    fore(p, edges) {
        ll L = p.first;
        auto v = p.second;

        fore(i, v) {
            int a = A[i];
            int b = B[i];

            if(uf[a] != uf[b]) {
                a = uf[a];
                b = uf[b];
                int sz2 = sz[a] + sz[b];
                erase(sz[a]);
                erase(sz[b]);
                uf(a, b);
                int ab = uf[a];
                sz[ab] = sz[a] + sz[b];
                ms.insert(sz[ab]);
            }
        }

        int mi = *ms.begin();
        while(pre < mi) {
            pre++;
            ans[pre] = L;
        }
    }

    rep(i, 0, Q) {
        int q; cin >> q;
        if(0 <= ans[q]) printf("%lld\n", ans[q]);
        else printf("trumpet\n");
    }
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
何から手をつけたものかと思うのだが、何か全探索対象か固定できるものを考える。
q[i]を固定してみると、操作がやりづらいが、Lを固定すると都合がいい。
Lを固定すると、C[i]≦Lを満たす辺が移動に使える。
この時、満たす辺を使って連結成分を考えたときに頂点数が最も少ない連結成分の頂点数が会える天使になる。
こういう事情を考えると、Lとして使う候補はC[i]に限られる。
なので、Lを全探索して、クエリで答える答えを前計算しておこう。
Lの候補を小さい方から見ていき、UnionFindを使って「連結→連結成分の最小値取得」をする。
連結成分の最小値取得は、multisetを使えばいい。
///////////////////////// writeup2 end */
