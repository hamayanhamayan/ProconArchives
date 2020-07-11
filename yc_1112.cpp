//https://yukicoder.me/problems/no/1112
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
int mod = 1000000007;
int add(int x, int y) { return (x += y) >= mod ? x - mod : x; }
template<class... T> int add(int x, T... y) { return add(x, add(y...)); }
int mul(int x, int y) { return 1LL * x * y % mod; }
template<class... T> int mul(int x, T... y) { return mul(x, mul(y...)); }
int sub(int x, int y) { return add(x, mod - y); }
int modpow(int a, long long b) {
    int ret = 1; while (b > 0) {
        if (b & 1) ret = 1LL * ret * a % mod; a = 1LL * a * a % mod; b >>= 1;
    } return ret;
}
int modinv(int a) { return modpow(a, mod - 2); }
typedef vector<int> Vec;
typedef vector<Vec> Mat;
Vec mulMatVec(Mat a, Vec b)
{
    int n = b.size(); Vec ret(n, 0);
    rep(i, 0, n) rep(j, 0, n) ret[i] = add(ret[i], mul(a[i][j], b[j]));
    return ret;
}
Mat mulMatMat(Mat a, Mat b)
{
    int n = a.size(); Mat ret(n, Vec(n, 0));
    rep(i, 0, n) rep(j, 0, n) rep(k, 0, n) ret[i][j] = add(ret[i][j], mul(a[i][k], b[k][j]));
    return ret;
}
Mat fastpow(Mat x, ll n)
{
    Mat ret(x.size(), Vec(x.size(), 0));
    rep(i, 0, x.size()) ret[i][i] = 1;
    while (0 < n) { if ((n % 2) == 0) { x = mulMatMat(x, x); n >>= 1; } else { ret = mulMatMat(ret, x); --n; } }
    return ret;
}
void printVec(Vec a) { cout << "[\t"; rep(i, 0, a.size()) cout << a[i] << "\t"; cout << "]" << endl; }
void printMat(Mat a) { rep(i, 0, a.size()) printVec(a[i]); }
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan0
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int K, M; ll N;
bool ok[6][6][6];
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> K >> M >> N;
    rep(i, 0, M) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--; c--;
        ok[a][b][c] = true;
    }

    Vec v(K * K);
    rep(b, 0, K) rep(c, 0, K) if(ok[0][b][c]) v[b * K + c] = 1;

    Mat m(K * K, Vec(K * K));
    rep(a, 0, K) rep(b, 0, K) rep(c, 0, K) if (ok[a][b][c]) {
        m[b * K + c][a * K + b] = 1;
    }

    m = fastpow(m, N - 3);
    v = mulMatVec(m, v);

    int ans = 0;
    rep(a, 0, K) ans = add(ans, v[a * K + 0]);
    cout << ans << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [行列累乗によるDP更新最適化](https://www.hamayanhamayan.com/entry/2017/03/20/234711)
///////////////////////// writeup2 start
知っていれば行列累乗が最初に候補に挙がってくる問題。
操作が10^18回ある問題なので、logNにする必要はあり、数学的にパッと解ける問題にも見えないので、
とりあえず行列累乗から考え始めるといった感じ。
なお、本解説では行列累乗についてのちゃんとした解説はしないので、ググってどこかで勉強してきてほしい。

## その前に

Nがもうちょっと少なかったらDPができる。
この1つ前の問題は似たような問題でDPで解くことができる。
dp[i][pre][lst] := i番目まで確定していて、1つ前がpreで、最後がlstである制約を満たしている曲の組合せ
iが10^18でダメなのだが、遷移が毎回定数値を使っていて同じような感じになる場合は行列累乗による高速化が使える

## 行列累乗

dp[i][pre][lst] -> dp[i + 1][lst][nxt]の更新だが、行列累乗では1次元にする必要があるので、
dp[i][pre * K + lst] -> dp[i + 1][lst * K + nxt]のように先頭以外で1次元にしておこう。
すると、dp[pre * K + lst]に何か計算をして、dp[lst * K + nxt]を作ることになる。
計算前と計算後はベクトルであるので、ベクトルに対する計算、つまり行列計算を行う事で、1回の遷移が行える。
dp_next = M * dp_prev
このMは遷移可能であれば1, 遷移不可能なら0としておけばいい。
1回の遷移なら行列はMだし、2回の遷移なら行列はM^2だし、N回の遷移なら行列はM^Nを使えばいい。
M^Nの行列計算は繰り返し二乗法を使えば効率的に計算可能。ここが『行列累乗』になる。
あとは、行列計算をうまいことやれば答え。
///////////////////////// writeup2 end */
