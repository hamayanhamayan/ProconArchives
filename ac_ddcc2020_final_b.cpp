//https://atcoder.jp/contests/ddcc2020-final/tasks/ddcc2020_final_b
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
using TN = pair<ll,ll>; using Vec = vector<TN>; using Mat = vector<Vec>;
#define zero make_pair(-infl, -infl)
#define one make_pair(0, -infl)
TN mul(TN a, TN b) {
	if (a == zero || b == zero) return zero;
	return { a.first + b.first, max(a.first + b.second, a.second) };
}
TN add(TN a, TN b) {
	return { max(a.first, b.first), max(a.second, b.second) };
}
Vec mulMatVec(Mat a, Vec b) {
    int n = b.size(); Vec ret(n, zero);
    rep(i, 0, n) rep(j, 0, n) ret[i] = add(ret[i], mul(a[i][j], b[j]));
    return ret;
}
Vec mulVecMat(Vec a, Mat b) {
    int n = b.size(); Vec ret(n, zero);
    rep(i, 0, n) rep(j, 0, n) ret[i] = add(ret[i], mul(a[j], b[j][i]));
    return ret;
}
Mat mulMatMat(Mat a, Mat b) {
    int n = a.size(); Mat ret(n, Vec(n, zero));
    rep(i, 0, n) rep(j, 0, n) rep(k, 0, n) ret[i][j] = add(ret[i][j], mul(a[i][k], b[k][j]));
    return ret;
}
Mat fastpow(Mat x, ll n) {
    Mat ret(x.size(), Vec(x.size(), zero));
    rep(i, 0, x.size()) ret[i][i] = one;
    while (0 < n) { if ((n % 2) == 0) { x = mulMatMat(x, x); n >>= 1; } else { ret = mulMatMat(ret, x); --n; } }
    return ret;
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














int N, M; ll W; int S, K;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> M >> W >> S >> K;
	S--;
	
	Mat mat(N, Vec(N, zero));
	rep(i, 0, M) {
		int u, v, w; cin >> u >> v >> w;
		u--; v--;
		mat[v][u] = { w, 0 };
	}
	mat = fastpow(mat, K);

	Vec vec(N, zero);
	vec[S] = { W, 0 };

	vec = mulMatVec(mat, vec);

	ll ans = -1;
	rep(i, 0, N) {
		ll point = max(vec[i].first, vec[i].second);
		chmax(ans, point);
	}
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
///////////////////////// writeup2 end */
