//https://atcoder.jp/contests/past201912-open/tasks/past201912_f
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














string S;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> S;
	int N = S.length();

	vector<pair<string,string>> v;
	string buf = "";
	int big = 0;
	rep(i, 0, N) {
		buf += S[i];
		if ('A' <= S[i] and S[i] <= 'Z') {
			big++;
			if (big % 2 == 0) {
				string lower = buf;
				transform(all(lower), lower.begin(), tolower);
				v.push_back({ lower, buf });
				buf = "";
			}
		}
	}

	sort(all(v));
	string ans = "";
	fore(p, v) ans += p.second;
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
単語は大文字2つで挟まれているので、大文字が2つ現れた時点で文字列を分裂していく。
単語分割が問題の最も難しい部分である。
先頭から分割していくのがいい。
実際に分割すると、添字がおかしな感じになるので、抜き出してくような感じで分割する。

あとは、分割後の文字列群をソートして連結して答える。
ソートは通常のソートではだめで、全て小文字にした状態でソートする必要がある。
pair<string,string>とかにしておいて、一番目を全て小文字にしたもの、二番目を答えとしておこう。
///////////////////////// writeup2 end */
