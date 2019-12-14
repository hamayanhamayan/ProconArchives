//https://yukicoder.me/problems/no/933
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














int N; ll P[101010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) cin >> P[i];

	rep(i, 0, N) if (P[i] == 0) {
		cout << 0 << endl;
		return;
	}

	ll ans = 1;
	rep(i, 0, N) ans = (ans * P[i]) % 9;
	if (ans == 0) ans = 9;
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
これ難しくないか？
ん？まじで何も分からん。
多倍長整数で殴れそうな気もするけど、ほんとか？
あれっ？あれっ？

こんなときはランキングを見るとヒントがあったりする。
2分とかで解いてる人がいる。
性質見抜く系か。
あーだめだ。わかんねぇ。

数字根という話があるらしい。
自分は勉強として競技プログラミングしてるので、こういう新しい話は嬉しい。
ある数Nの数字根はNを9で割った余りと等しいらしい（9の倍数のときは9）
これくらいなら実験したら気づけたかも。反省。
九去法ってのもあるらしい。数字根をチェックサムとして使用する手法。
なので、mod9で掛け合わせて、数を見ればいい。
P[i]に0が含まれるときは0が答えなので、これがコーナーケース。
///////////////////////// writeup2 end */
