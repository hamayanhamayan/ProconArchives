//https://yukicoder.me/problems/no/929
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














int N;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	vector<int> idx;
	rep(i, 1, N + 1) {
		int B; cin >> B;
		rep(j, 0, B) idx.push_back(i);
	}

	ll ans = 0;
	rep(i, 0, N) ans += abs(idx[i] - (i + 1));
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
なんとなく貪欲でやれば良さそうな気がする。
先頭からなければ前から持ってくるか、後ろから持ってくるかすればいい。
これはボールに最初にある場所の添字を付けて、昇順ソートしたときの位置が最適な位置になるので、
添字とボールに付いている添字との差を取っていけば答え。
///////////////////////// writeup2 end */
