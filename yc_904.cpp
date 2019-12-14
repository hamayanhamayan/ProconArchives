//https://yukicoder.me/problems/no/904
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














int N, A[37], B[37];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 1, N) cin >> A[i] >> B[i];

	int ans = 0;
	rep(a1, 0, 37 * 10101) {
		int a_sm = a1;
		rep(i, 1, N) a_sm += A[i];
		int b_sm = 0;
		rep(i, 1, N) b_sm += B[i];
		int b1 = a_sm - b_sm;

		A[0] = a1;
		B[0] = b1;

		if (b1 < 0) continue;

		bool ok = true;
		rep(i, 0, N) if (a_sm - B[i] < A[i]) ok = false;
		if (ok) ans++;
	}
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
難しい。
何もわからないが、Nが小さいのが気になる。

まず、わかることとして、Aの総和＝Bの総和であることは自明。
A1が決まると、Aの総和＝Bの総和なので、B1も一意に定まる。
A,Bの範囲もそんなに大きくないので、A1は全探索できそう。
そのためのNの小ささか。

どういうパターンでダメかという部分だが、
Bの総和 - B[i] < A[i]
こうなっていると、i番目に入った人がi番目で出るしかなくなってしまうのでダメ。
こうなっているものがないなら答えをインクリメント。
工夫できそうな気もするが、気にせずに全探索すると通る。
///////////////////////// writeup2 end */
