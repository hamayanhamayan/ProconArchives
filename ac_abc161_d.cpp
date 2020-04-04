//https://atcoder.jp/contests/abc161/tasks/abc161_d
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














int K;
//---------------------------------------------------------------------------------------------------
string increment(string from) {
	int N = from.size();

	rrep(i, N - 1, 1) {
		int cu = from[i] - '0';
		int nxt = from[i - 1] - '0';

		if (cu < 9 && abs(cu + 1 - nxt) <= 1) {
			from[i]++;
			rep(j, i + 1, N) from[j] = max('0', (char)(from[j - 1] - 1));
			return from;
		}
	}

	int top = from[0] - '0';
	
	if (top < 9) {
		from[0]++;
		rep(j, 1, N) from[j] = max('0', (char)(from[j - 1] - 1));
		return from;
	}

	string res = "1";
	rep(i, 0, N) res += "0";
	return res;
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> K;

	string ans = "1";
	rep(k, 0, K - 1) ans = increment(ans);
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
サンプルを見ると10^5の場合が紹介されている。
あまり桁数が増えていないので、普通にインクリメント作業をしても間に合いそうだ。
x++のような関数を作ろう。
increment(from) := ルンルン数上でfrom+1を返す
基本的には普通のインクリメントと同様で一番下の桁を+1する。
した結果ルンルン数でなくなる場合は、その次の桁を+1する。
繰り上がりのような感じで考えればいい。
例えば、
434からのインクリメントは、末尾の4を+1すると、ルンルン数でなくなるので、次の桁の3をインクリメントする。
44_となるが、そこより下の桁はなるべく小さい数を置くので、4から-1した443となる。
これが、44__であれば、4から-1して、そこからさらに次の桁では-1するので、4432となる。
こういったことを頑張ってやる。
///////////////////////// writeup2 end */
