//https://atcoder.jp/contests/abc153/tasks/abc153_b
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
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan0
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int H, N, A[101010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> H >> N;
	rep(i, 0, N) cin >> A[i];

	int tot = 0;
	rep(i, 0, N) tot += A[i];

	if (H <= tot) cout << "Yes" << endl;
	else cout << "No" << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
同じ必殺技を2度以上使うことなく勝てるかという問題を言い換えて考える。
必殺技をそれぞれ1回使うことで勝てるかを考える。
つまり、放てる最高の攻撃力をぶつけることを考える。
これはAの総和であるため、Aの総和がH以上であれば、勝つことができる。
///////////////////////// writeup2 end */
