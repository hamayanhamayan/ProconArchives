//https://atcoder.jp/contests/abc151/tasks/abc151_c
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














int N, M;
bool solved[101010];
int wa[101010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> M;

	rep(i, 0, M) {
		int p; string s; cin >> p >> s;
		p--;

		if (s == "WA" and !solved[p]) wa[p]++;
		if (s == "AC") solved[p] = true;
	}

	int correct = 0, penalty = 0;
	rep(i, 0, N) if (solved[i]) {
		correct++;
		penalty += wa[i];
;	}

	cout << correct << " " << penalty << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
シミュレーション問題となる。
各問題についてACしているかどうかを保持する配列solvedとWA数を保持する配列waを定義しておいて、
時系列順にシミュレーションする。
シミュレーション後に、2つの配列を見て、正答数とペナルティ数を集計して答えよう。
///////////////////////// writeup2 end */
