//https://atcoder.jp/contests/jsc2019-qual/tasks/jsc2019_qual_e
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














int N, H, W;
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N >> H >> W;
    vector<pair<int,pair<int,int>>> E;
    rep(i, 0, N) {
        int y, x, a; cin >> y >> x >> a;
        y--; x--;
        E.push_back({a, {x, y + W}});
    }

    UnionFind uf(H + W + 1);
    sort(all(E));
    reverse(all(E));

    ll ans = 0;
    fore(p, E) {
        int c = p.first;
        int a = p.second.first;
        int b = p.second.second;

        if(uf[a] == uf[b]) {
            if(uf[a] == uf[H + W]) continue;

            ans += c;
            uf(a, H + W);
        } else {
            ans += c;
            uf(a, b);
        }
    }
    cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
とりあえずは、[解説放送](https://www.youtube.com/watch?v=JTH27weC38k)を見るのがいい。
これを元にして考察過程を想像して書いてみる。

グリッドの問題は行と列をそれぞれ頂点とした2部グラフを考える場合がある。
A[i][j]に対応するのは、A[i][j]をコストとして行iと列jを結ぶ辺である。
これで、問題は無向グラフに重みがついた辺があり、辺を選択する問題となった。
問題に立ち返って考えると、問題では行か列に対して、カードを選択するというものであった。
これはグラフで考えると、ある頂点について1つの辺を選択するというものになる。
ここで「N頂点N辺のグラフ」と聞くと、「なもりグラフ」が思い浮かぶ。
なので、問題に対する答えは、重み付き2部グラフについて、連結成分が木かなもりグラフであるものの中で、
辺のコストの総和の最大値を答える問題となった。

似た問題で、最小全域木が思い浮かぶ。
大体似た問題と似たような解法になることが多いので、貪欲法で解いてみる。
これで信じて出すとAC。
頂点として0～H+Wを用意する。
頂点H+Wはなもりグラフとしておく。
これでufをとった時に両方なもりグラフであれば、同じになって結合できないので、都合がいい。
///////////////////////// writeup2 end */
