//https://atcoder.jp/contests/past202005-open/tasks/past202005_l
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
#define def make_pair(-1,-1)
template<class V, int NV> struct SegTree { //[l,r)
    V comp(V& l, V& r) { return max(l, r); };
 
    vector<V> val; SegTree() { val = vector<V>(NV * 2, def); }
    V get(int x, int y, int l = 0, int r = NV, int k = 1) {
        if (r <= x || y <= l)return def; if (x <= l && r <= y)return val[k];
        auto a = get(x, y, l, (l + r) / 2, k * 2);
        auto b = get(x, y, (l + r) / 2, r, k * 2 + 1);
        return comp(a, b);
    }
    void update(int i, V v) {
        i += NV; val[i] = v;
        while (i > 1) i >>= 1, val[i] = comp(val[i * 2], val[i * 2 + 1]);
    }
    void add(int i, V v) { update(i, val[i + NV] + v); }
    V operator[](int x) { return get(x, x + 1); }
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














int N, M;
int K[101010]; deque<int> T[101010];
SegTree<pair<int, int>, 1 << 17> st[3];
//---------------------------------------------------------------------------------------------------
int getmax(int t, int cnt) {
    int res = -1;
    rep(i, 0, cnt) if (i + 1 <= T[t].size()) chmax(res, T[t][i]);
    return res;
}
//---------------------------------------------------------------------------------------------------
void popAndUpdate(int ma, int shelf) {
    if (T[shelf].front() == ma) {
        T[shelf].pop_front();
    }
    else {
        int top1 = T[shelf].front(); T[shelf].pop_front();
        T[shelf].pop_front();
        T[shelf].push_front(top1);
    }
 
    st[1].update(shelf, { getmax(shelf, 1), shelf });
    st[2].update(shelf, { getmax(shelf, 2), shelf });
}
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N;
    rep(i, 0, N) {
        cin >> K[i];
        rep(k, 0, K[i]) {
            int t; cin >> t;
            T[i].push_back(t);
        }
    }
 
    rep(i, 0, N) st[1].update(i, { getmax(i, 1), i });
    rep(i, 0, N) st[2].update(i, { getmax(i, 2), i });
 
    cin >> M;
    rep(_, 0, M) {
        int a; cin >> a;
 
        auto p = st[a].get(0, N);
        int ans = p.first;
        int shelf = p.second;
 
        popAndUpdate(ans, shelf);
 
        printf("%d\n", ans);
    }
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
この問題の制約で1≦ai≦2というどう見てもおかしい制約があるので、ここから考える。
ai=1かai=2の2パターンしかないことになるので、それぞれ考えてみる。

ai=1の場合は、全ての棚の先頭のうち最大のものがどれかが分かればいい。
これはセグメントツリーを使えば簡単そうだ。
で、最大のものを取り出した後は、そこに棚の次のものを入れておけば、それ以降の処理も同様に行える。

ai=2の場合は、全ての棚の先頭と二番目のうち最大のものがどれかが分かればいい。
これも同様の方法を使えばできそうだ。

よって、先頭から1つ、と、先頭から2つまでの商品について消費期限をセグメントツリーに入れて管理しておこう。
そして、商品が取られた棚については、セグメントツリーをどちらも更新して、それ以降の処理に備える。

自分はサブ関数を作って、実装を行っている。
getmax関数では、先頭から何個での消費期限の最大値を求めている。
棚の商品管理にはdequeを使っている。先頭からデータをpopすることができるし、何より添え字を使ったランダムアクセスが便利。
popAndUpdate関数では、商品が棚から取られた処理を書いている。
一番目の商品か二番目の商品かを判定し、取り出したあと、セグメントツリーを更新している。
///////////////////////// writeup2 end */
