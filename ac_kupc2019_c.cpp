//https://atcoder.jp/contests/kupc2019/tasks/kupc2019_c
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














ll M, K;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> M >> K;

	ll bundo = 1;
	int ans = 1;
	ll ma = K;
	while (ma < M) {
		bundo = ma * 2 + 1;
		ans++;
		ma += bundo * K;
	}
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
最初の分銅は1gにする。
すると、1～Kgは測れる。
次に用意する分銅はK+1としたい所だが、(2K+1)gを用意すればいい。
例えば、K+1gを測りたいときは、
(2K+1)=(K+1)+K
とすれば測れる。
こうすると上限はK+(2K+1)*Kまで測れるようになる。
これで上限をジャンジャン増やしていけばいい。
///////////////////////// writeup2 end */
