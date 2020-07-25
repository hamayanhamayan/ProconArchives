//https://atcoder.jp/contests/aising2020/tasks/aising2020_f
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














int N;
//---------------------------------------------------------------------------------------------------
void solve() {
	cin >> N;

	if (N <= 4) {
		printf("0\n");
		return;
	}

	Mat m(16 * 2, Vec(16 * 2));

	rep(group, 0, 16) rep(p, 0, 2) {
		m[group * 2 + 1 - p][group * 2 + p] += 1;
		if (group < 5 && p == 1) continue;
		rep(dest, group + 1, 16) m[dest * 2 + 1][group * 2 + p] += 1;
	}

	Vec v(16 * 2);
	v[0] = 1;

	m = fastpow(m, N - 4);
	v = mulMatVec(m, v);

	int ans = add(v[15 * 2], v[15 * 2 + 1]);
	printf("%d\n", ans);
}
//---------------------------------------------------------------------------------------------------
void _main() {
	int T; cin >> T;
	rep(t, 0, T) solve();
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
///////////////////////// writeup2 end */
