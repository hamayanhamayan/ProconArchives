//https://yukicoder.me/problems/no/891
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
typedef long long ll;
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
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int a, b, n;
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> a >> b >> n;

    Mat m(2, Vec(2, 0));
    m[0][0] = 0;
    m[0][1] = 1;
    m[1][0] = b;
    m[1][1] = a;

    m = fastpow(m, n);

    Vec v(2, 0);
    v[0] = 0;
    v[1] = 1;

    v = mulMatVec(m, v);
    cout << v[0] << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [行列累乗](https://www.hamayanhamayan.com/entry/2017/03/20/234711)
///////////////////////// writeup2 start
問題を見るとフィボナッチ数の定義に似ている。
ある項のフィボナッチ数を高速に求める方法として、行列累乗が知られている。
今回の問題もこれで解ける。
///////////////////////// writeup2 end */
