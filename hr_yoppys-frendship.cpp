//https://www.hackerrank.com/contests/wasedajitsugyo-scienceclub-festival-contest2019/challenges/yoppys-frendship
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
//        Welcome to My Coding Space! @hamayanhamayan
//---------------------------------------------------------------------------------------------------

int N, M;
vector<int> E[5010];
//---------------------------------------------------------------------------------------------------
ll imos2D[5010][5010];
void add(int sx, int sy, int tx, int ty, ll x) { // [sx,tx], [sy, ty]
    imos2D[sy][sx] += x;
    imos2D[ty + 1][sx] -= x;
    imos2D[sy][tx + 1] -= x;
    imos2D[ty + 1][tx + 1] += x;
}
void build() {
    rep(y, 0, 5010) rep(x, 1, 5010) imos2D[y][x] += imos2D[y][x - 1];
    rep(x, 0, 5010) rep(y, 1, 5010) imos2D[y][x] += imos2D[y - 1][x];
}
//---------------------------------------------------------------------------------------------------
int L[5010], R[5010], rev[5010];
int idx = 0;
void euler(int cu, int pa = -1) { // [L[v],R[v])
    L[cu] = idx; idx++;
    for (int to : E[cu]) if (to != pa) euler(to, cu);
    R[cu] = idx;
}
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N >> M;
    int root = -1;
    rep(i, 0, N) {
        int w; cin >> w; w--;
        if (w == i) {
            root = i;
            continue;
        }
        E[w].push_back(i);
    }

    euler(root);
    rep(i, 0, N) rev[L[i]] = i;

    rep(m, 0, M) {
        int a, b, c; cin >> a >> b >> c; a--; b--;

        int al = L[a];
        int ar = R[a];
        int bl = L[b];
        int br = R[b];

        add(al, bl, ar - 1, br - 1, c);
        add(bl, al, br - 1, ar - 1, c);
        
        if (al <= bl and br <= ar) {
            add(bl, bl, br - 1, br - 1, -2LL * c);
        }

        if (bl <= al and ar <= br) {
            add(al, al, ar - 1, ar - 1, -2LL * c);
        }
    }

    build();

    vector<pair<int, int>> v;

    rep(i, 0, N) {
        int ans = -1; ll ma = -1;
        rep(j, 0, N) {
            if (ma < imos2D[i][j]) {
                ans = rev[j];
                ma = imos2D[i][j];
            }
            else if (ma == imos2D[i][j]) chmin(ans, rev[j]);
        }
        v.push_back({rev[i], ans});
    }

    sort(all(v));

    rep(i, 0, N) {
        if (i) printf(" ");
        printf("%d", v[i].second + 1);
    }
    printf("\n");
}

/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
Nの制約が小さく、ここが弱点になりそうな感じ。
しかもグラフの形も特別な形になっている。
自己辺が1つはあり、それを取り除くと、木の根付き木の形になる。
根は問題中の「少なくともある1人の連絡は全員に行き渡る」のある1人。W[i]=iの人。

根付き木であることを念頭に、操作を見てみる。
すると、A[i]とB[i]の関係性によってパターンが色々分かれる。
A[i]の部分木とB[i]の部分木が独立なら、はっきりA,Bグループに分かれる。
A[i]の部分木内にB[i]の部分木があれば、BグループはB[i]の部分木内部で、AグループはA[i]の部分木でBグループ以外になる。
グループが部分木になるというのは使えそうな性質。

他に使えそうな性質も見つからないので、全探索を考えてみる。
Mの制約が大きく、O(M)だけでだいぶきつい。
操作をO(logN)とかで何かに反映できないか？
部分木になるので、2つのグループはオイラーツアーとかで区間にはできる。
ここから発想の飛躍になるが、
グループAを縦軸、グループBを横軸としたときに、その関係全てに+Ciするというのは、
矩形addに対応する。
例えば、1 2 3 4と生徒がいて、グループAが1,2でグループBが3,4だと+Ciする部分は以下の部分になる。

|   | 1 | 2 | 3 | 4 |
|---|---|---|---|---|
| 1 |   |   | x | x |
| 2 |   |   | x | x |
| 3 | x | x |   |   |
| 4 | x | x |   |   |

なので、オイラーツアーの順番で表を作っておくと、仲良しの加算は矩形addになるので、2次元imosが使える。
2次元imosで加算領域を指定し、その後に累積和を取って正しい結果にする。
最後に自分と他の人を確認し、最も仲良しの相手を見つければいい。
///////////////////////// writeup2 end */
