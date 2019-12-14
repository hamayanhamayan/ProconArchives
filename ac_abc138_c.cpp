//https://atcoder.jp/contests/abc138/tasks/abc138_c
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
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int N; double v[50];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) cin >> v[i];
	sort(v, v + N);

	double ans = v[0];
	rep(i, 1, N) ans = (ans + v[i]) / 2;
	printf("%.10f\n", ans);
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
abcの具材があったときに、((a+b)/2+c)/2=a/4+b/4+c/2のような場合が考えられる。
なるべく、分母が大きいものは、なるべく小さい数にあてるのがいい。
そして、早く合成に使うと分母が大きくなる。
ここからはエスパーだが、まだ300点問題なので、ソートして、小さい順から順番に合成させていく。
///////////////////////// writeup2 end */
