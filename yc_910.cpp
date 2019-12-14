//https://yukicoder.me/problems/no/910
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














int N; string S;
bool used[201010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> S;

	int ans = 0;

	// 3,5,7
	rep(i, 0, N) if (S[i] != '1' and S[i] != '9') {
		used[i] = true;
		ans++;
	}

	// 19
	queue<int> ones;
	rep(i, 0, N) if (!used[i]) {
		if (S[i] == '1') ones.push(i);
		if (S[i] == '9') {
			if (1 <= ones.size()) {
				int one = ones.front(); ones.pop();
				used[one] = true;
				used[i] = true;
				ans++;
			}
		}
	}

	// 991
	queue<int> nines;
	rep(i, 0, N) if (!used[i]) {
		if (S[i] == '9') nines.push(i);
		if (S[i] == '1') {
			if (2 <= nines.size()) {
				int nine1 = nines.front(); nines.pop();
				int nine2 = nines.front(); nines.pop();
				used[nine1] = true;
				used[nine2] = true;
				used[i] = true;
				ans++;
			}
		}
	}

	// 11
	int cnt1 = 0;
	rep(i, 0, N) if (!used[i] and S[i] == '1') cnt1++;
	ans += cnt1 / 2;

	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
サンプル1で97を削除しているが、これは7に変えても問題ない。
つまり、削除するときに最小単位があるような気がする。

3
5
7
これは個別に消すのがいい。1つで1回稼げるので割と自明。
あとは、1と9であるが、11は素数。19も素数。91はダメ。
111は11の方がいい、119は11か19。191は11か19。
なるほど。
なるべく19でとるほうがよさそう。9は単体だと絶対無理だから。
9の消費方法として991もある。これも作れるなら貪欲に作るほうがいい。
あとは、残った1を11として作ればいい。

ということで、
- 3,5,7を貪欲にとる
- 19を貪欲にとる
- 991を貪欲にとる
- 11を貪欲にとる
が答えになる。
///////////////////////// writeup2 end */
