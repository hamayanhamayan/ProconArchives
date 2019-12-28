//https://atcoder.jp/contests/agc041/tasks/agc041_c
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














int N;
string ans[1010];
//---------------------------------------------------------------------------------------------------
void copy(int sx, int sy, vector<string>& vs) {
	int n = vs.size();
	rep(dx, 0, n) rep(dy, 0, n) ans[sy + dy][sx + dx] = vs[dy][dx];
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	if (N == 2) {
		cout << -1 << endl;
		return;
	}

	if (N == 3) {
		cout << "aa." << endl;
		cout << "..a" << endl;
		cout << "..a" << endl;
		return;
	}

	if (N == 7) {
		cout << "aabbcc." << endl;
		cout << "dd.dd.a" << endl;
		cout << "..d..da" << endl;
		cout << "..d..db" << endl;
		cout << "dd.dd.b" << endl;
		cout << "..d..dc" << endl;
		cout << "..d..dc" << endl;
		return;
	}

	rep(y, 0, N) rep(x, 0, N) ans[y] += ".";

	int a, b, c = -1;
	rep(c4, 0, N + 1) rep(c5, 0, N + 1) {
		int d = N - c4 * 4 - c5 * 5;
		if (0 <= d and d % 6 == 0) {
			a = c4, b = c5, c = d / 6;
		}
	}

	vector<string> vs4 = {
		"aabc",
		"ddbc",
		"bcaa",
		"bcdd"
	};

	vector<string> vs5 = {
		"aabba",
		"bcc.a",
		"b..cb",
		"a..cb",
		"abbaa"
	};


	vector<string> vs6 = {
		"aabc..",
		"ddbc..",
		"..aabc",
		"..ddbc",
		"bc..aa",
		"bc..dd"
	};
	
	int x = 0, y = 0;
	
	rep(i, 0, a) {
		copy(x, y, vs4);
		x += 4;
		y += 4;
	}
	rep(i, 0, b) {
		copy(x, y, vs5);
		x += 5;
		y += 5;
	}
	rep(i, 0, c) {
		copy(x, y, vs6);
		x += 6;
		y += 6;
	}
	
	rep(y, 0, N) printf("%s\n", ans[y].c_str());

}





/* ///////////////////////// writeup1 start
# 関連
- [構築](https://www.hamayanhamayan.com/entry/2017/08/21/102212)
///////////////////////// writeup2 start
DPとかできないか色々考える。
何も出てこない。

これは、あれか、なんか性質を仮定して解くやつか。
クオリティはそんなに大きくならないんじゃないか。
クオリティ1はN=3以外はちょっと難しそう。
それじゃ、全部クオリティ2で作れるんやろ、ちっちゃいやつ実験するか…
AGC完。

クオリティ3でした。
実験じゃなくて全探索を書きなさいという話ですが、その書き方すらわからん。
N=4,5,6でクオリティ3を作る盤面が存在する。
これを根性（か、全探索）で見つける。
あとは、Nを4x+5y+6zで表現できないか全探索する。
x,yを全探索すれば、zは求めることができるの。
あとは、斜めに配置していけば、クオリティ3を作ることができる。

コーナーケース
N=2は解が無いので-1
N=3はクオリティ2が答えなので、
aa.
..a
..a
N=7が唯一4x+5y+6zで作れないので、適当に考える。
[公式解説](https://img.atcoder.jp/agc041/editorial.pdf)に書いてある以下のようなやつを考える。
aabbcc.
dd.dd.a
..d..da
..d..db
dd.dd.b
..d..dc
..d..dc
///////////////////////// writeup2 end */
