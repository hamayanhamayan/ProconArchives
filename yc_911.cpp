//https://yukicoder.me/problems/no/911
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
vector<pair<int, int>> runLengthEncoding(vector<int> s) {
	int n = s.size();

	vector<pair<int, int>> res;
	int pre = s[0];
	int cnt = 1;
	rep(i, 1, n) {
		if (pre != s[i]) {
			res.push_back({ pre, cnt });
			pre = s[i];
			cnt = 1;
		}
		else cnt++;
	}

	res.push_back({ pre, cnt });
	return res;
}
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int N; ll L, R, A[201010];
//---------------------------------------------------------------------------------------------------
ll dp[62][2];
ll solve(ll X) {
	if (X < 0) return 0;

	rep(dgt, 0, 62) rep(isless, 0, 2) dp[dgt][isless] = 0;
	dp[0][0] = 1;

	vector<int> grp;
	grp.push_back(0);
	grp.push_back(N);

	rep(dgt, 0, 61) {
		int n = grp.size();
		ll msk = 1LL << (60 - dgt);

		int f0 = 0, f1 = 0, f01 = 0;

		vector<int> grp2;
		rep(i, 0, n - 1) {
			int l = grp[i];
			int r = grp[i + 1];

			vector<int> v01;
			rep(i, l, r) {
				if (A[i] & msk) v01.push_back(1);
				else v01.push_back(0);
			}

			auto v01run = runLengthEncoding(v01);
			if (v01run.size() == 1) {
				f01++;
				grp2.push_back(l);
			}
			else if (v01run.size() == 2) {
				if (v01run[0].first == 0) f0++;
				else f1++;

				grp2.push_back(l);
				grp2.push_back(l + v01run[0].second);
			}
			else return 0;
		}
		grp2.push_back(N);
		swap(grp, grp2);

		if (0 < f0 and 0 < f1) return 0;

		int cur_dgt = 0;
		if (X & msk) cur_dgt = 1;

		vector<int> v_nxt;

		if (0 < f0) {
			// 0じゃないとだめ
			v_nxt.push_back(0);
		}
		else if (0 < f1) {
			// 1じゃないとだめ
			v_nxt.push_back(1);
		}
		else {
			// 0でも1でもいいよ
			v_nxt.push_back(0);
			v_nxt.push_back(1);
		}

		rep(isless, 0, 2) fore(nxt, v_nxt) {
			if (!isless and cur_dgt < nxt) continue;
			int isless2 = isless;
			if (nxt < cur_dgt) isless2 = 1;
			dp[dgt + 1][isless2] += dp[dgt][isless];
		}
	}

	return dp[61][0] + dp[61][1];
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> L >> R;
	rep(i, 0, N) cin >> A[i];

	ll ans = solve(R) - solve(L - 1);
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [桁DP](https://www.hamayanhamayan.com/entry/2017/04/23/212728)
- [XOR](https://www.hamayanhamayan.com/entry/2017/05/20/145021)
///////////////////////// writeup2 start
まずはいつもの区間テクを使おう。
[L,R]区間で選んだときの答えであるが、[1,R]-[1,L)としよう。
なので、[1,X]区間でxを選んだときの答えを求めよう。

XORなので、ビットごとに決定していくのがいい。
今回は大小関係を見たいので、上位ビットから順に考えていこう。
一番最初の操作では、数列Aの最上位ビットは、00...0011....11とならないとまずはダメである。
こうなるためにはxの最上位ビットは0か1かで確定する。
全部0とか全部1になる場合はそのビットは大小関係には影響しないので、0でも1でもどっちでもいい。
こうすると、0と1の間では大小関係が確定するので、その間は考える必要がなく、考えるべき区間が2つに分かれる。
次のビットについても同様のことを別れた区間について行っていく。
各区間について0にするか1にするかで割れた場合には単調増加は達成できないので0が答え。
すべての区間に別れた場合はビットは0でも1でもどっちでもいいので、2通りになる。

これで各桁について0にすべき、1にすべき、0でも1でもOKというのがわかった。
あとは、最大値に制約があるので、桁DPをして条件を満たすxを数え上げよう。
dp[dgt][isless] := 上位dgt桁まで確定していて、Xよりもすでに小さくなったかがislessのときの組み合わせ
///////////////////////// writeup2 end */
