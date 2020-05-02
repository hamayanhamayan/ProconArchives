//https://atcoder.jp/contests/abc165/tasks/abc165_f
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
typedef int V;
// NV=3010101 -> 38MB
#define NV 6010101
#define def 0
struct PersistentSegmentTree { //[L,R)
    V comp(V a, V b) { return max(a,b); }




    // -- template ---------------------
    struct S { int l, r; V x; } v[NV];
    int cnt = 1, n = -1;
    void init(int _n) { n = _n; rep(i, 0, NV) v[i].l = v[i].r = 0, v[i].x = def; }
    void add(int &root, int l, int r, int i, int val) {
        v[cnt] = v[root]; root = cnt++;if (l + 1 == r) { v[root].x += val; return; }
        int mi = (l + r) / 2;if (i < mi) add(v[root].l, l, mi, i, val);
        else add(v[root].r, mi, r, i, val);
        v[root].x = comp(v[v[root].l].x, v[v[root].r].x);}
    void add(int &root, int i, int val) { assert(0 < n);add(root, 0, n, i, val); }
    void update(int &root, int l, int r, int i, int val) {v[cnt] = v[root];root = cnt++;
        if (l + 1 == r) {v[root].x = val;return;}int mi = (l + r) / 2;
        if (i < mi) update(v[root].l, l, mi, i, val);else update(v[root].r, mi, r, i, val);
        v[root].x = comp(v[v[root].l].x, v[v[root].r].x);}
    void update(int &root, int i, int val) {assert(0 < n);update(root, 0, n, i, val);}
    V allget(int root) { assert(0 < n); return v[root].x;}
    V get(int root, int l, int r, int L, int R) {
        if (l >= r) return def;if (l == L && r == R) return v[root].x;int mi = (L + R) / 2;
        V le = get(v[root].l, max(l, L), min(r, mi), L, mi);
        V ri = get(v[root].r, max(l, mi), min(r, R), mi, R);return comp(le, ri);}
    V get(int root, int l, int r) {assert(0 < n);return get(root, l, r, 0, n);}
};
vector<int> compress1(int* v, int n) {
    vector<int> dic;
    rep(i, 0, n) dic.push_back(v[i]);
    sort(all(dic));
    dic.erase(unique(all(dic)), dic.end());
    rep(i, 0, n) v[i] = lower_bound(all(dic), v[i]) - dic.begin();
    return dic;
}
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan0
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int N, a[201010];
vector<int> E[201010];
//---------------------------------------------------------------------------------------------------
PersistentSegmentTree pst;
int ans[201010];
void dfs(int cu = 0, int pa = -1, int root = 0) {
    int root2 = root;
    int ma = pst.get(root, 0, a[cu]);
    pst.update(root2, a[cu], max(pst.get(root, a[cu], a[cu] + 1), ma + 1));

    ans[cu] = pst.get(root2, 0, N);
    fore(to, E[cu]) if (to != pa) dfs(to, cu, root2);
}
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N;
    rep(i, 0, N) cin >> a[i];
    compress1(a, N);

    rep(i, 0, N - 1) {
        int u, v; cin >> u >> v;
        u--; v--;
        E[u].push_back(v);
        E[v].push_back(u);
    }

    pst.init(N);
    dfs();

    rep(i, 0, N) printf("%d\n", ans[i]);
}





/* ///////////////////////// writeup1 start
# 前提知識
- 座標圧縮
- [セグメントツリーを使ったLIS解法](https://www.hamayanhamayan.com/?page=1493538812)
- [永続セグメントツリー（部分永続でOK）](https://www.hamayanhamayan.com/entry/2017/05/21/001252)
///////////////////////// writeup2 start
データ構造ズルをして解いた。
自分は手元に完全永続セグメントツリーがあったので、それを貼った。
部分永続セグメントツリーならセグメントツリーからちょっと工夫すれば書けるので、それが想定解ではないかなと思っている。
さて、ABCにratedで出ている方には『永続データ構造』は分からない人が大半だろうと思う。
それで問題無いように解説は書いていこう。

早速だが、「座標圧縮」と「セグメントツリーを使ったLIS解法」を知らない場合は、先にそっちを学習してきてほしい。
自分と想定解が同じなら、公式解説動画でも教えてくれるかもしれないし、そっちで学んでもいい。
[座標圧縮 - Google 検索](https://www.google.com/search?q=%E5%BA%A7%E6%A8%99%E5%9C%A7%E7%B8%AE&oq=%E5%BA%A7%E6%A8%99%E5%9C%A7%E7%B8%AE&aqs=chrome..69i57j0l7.2041j0j1&sourceid=chrome&ie=UTF-8)
[lis セグメントツリー - Google 検索](https://www.google.com/search?sxsrf=ALeKk02KaoXkoMZqvQzo-CSRBeG149a7gA%3A1588425581346&ei=bXOtXuLTFJGpoASQ563ADw&q=lis+%E3%82%BB%E3%82%B0%E3%83%A1%E3%83%B3%E3%83%88%E3%83%84%E3%83%AA%E3%83%BC&oq=lis+%E3%82%BB%E3%82%B0%E3%83%A1%E3%83%B3%E3%83%88%E3%83%84%E3%83%AA%E3%83%BC&gs_lcp=CgZwc3ktYWIQAzoECAAQRzoECCMQJzoFCAAQgwE6AggAOgQIABBDOgQIABAKOgQIABANOgYIABANEAo6BQgAEM0CUNlRWJpjYMNkaABwAXgAgAGfAYgB3RGSAQQwLjE5mAEAoAEBqgEHZ3dzLXdpeg&sclient=psy-ab&ved=0ahUKEwiivpy0opXpAhWRFIgKHZBzC_gQ4dUDCAw&uact=5)
これを説明するにはちょっと長い。

さて、LISの典型として、大小関係だけが重要であるので、配列aは座圧をして、[0,N)の範囲に数を収めておこう。
頂点1から頂点kまでの最短パスを考えているが、頂点1を根とすれば、根から頂点kまでの数列のLISを求める問題になる。
ここでLISを求めるのにセグメントツリーを使ってみよう。
区間max, 1点更新ができるセグメントツリーがあれば、LISを解くことができる。
試しに分岐が無い木で考えてみると、これは通常のLISと同様であり、根から順に値を見ながら、セグメントツリーを更新していけば解ける。

画像

分岐があった場合は、どうなるだろうか。
木なのでDFSで頂点を見ていくが、一旦片方の更新までいって、戻ってくることになる。

画像

この時に戻ってきたところまでセグメントツリーを「戻して」おきたくなる。
このように、ある更新地点まで戻せるデータ構造を永続データ構造という。

この戻せるセグメントツリーをいかに実装するかというのが問題だが、自分はライブラリになってるので貼ってしまった。
戻す方法の常套テクとして、履歴を残しておくという方法がある。
セグメントツリーの一点更新時に、更新場所と元々あった数をstackとかで覚えておいて、1手戻したくなったら、stackから最新の履歴を1つ取り出して適用すれば戻せる。
こういうundo機構を工夫して作ればACが得られる。
（ただ、自分のライブラリはそういうタイプじゃないので、自分の実装は参考にしないでください）
///////////////////////// writeup2 end */
