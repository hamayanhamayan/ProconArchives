//https://atcoder.jp/contests/past-sample/tasks/abc127_f
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










template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<typename T> struct MedianStructure {
	min_priority_queue<T> bigger; T sm_bigger = 0;
	priority_queue<T> smaller; T sm_smaller = 0;
	T center;
	int cnt = 0;

	void add(T v) {
		if (cnt == 0) center = v;
		else if (cnt == 1) {
			bigger.push(max(center, v)); sm_bigger += max(center, v);
			smaller.push(min(center, v)); sm_smaller += min(center, v);
		}else if (cnt % 2 == 0) {
			vector<T> vec; T a;
			a = bigger.top(); vec.push_back(a); bigger.pop(); sm_bigger -= a;
			a = smaller.top(); vec.push_back(a); smaller.pop(); sm_smaller -= a;
			vec.push_back(v);
			sort(all(vec));
			smaller.push(vec[0]); sm_smaller += vec[0];
			center = vec[1];
			bigger.push(vec[2]); sm_bigger += vec[2];
		}
		else {
			vector<T> vec; T a;
			a = bigger.top(); vec.push_back(a); bigger.pop(); sm_bigger -= a;
			a = smaller.top(); vec.push_back(a); smaller.pop(); sm_smaller -= a;
			vec.push_back(v);
			vec.push_back(center);
			sort(all(vec));
			smaller.push(vec[0]); sm_smaller += vec[0];
			smaller.push(vec[1]); sm_smaller += vec[1];
			bigger.push(vec[2]); sm_bigger += vec[2];
			bigger.push(vec[3]); sm_bigger += vec[3];
		}

		cnt++;
	}
	T getMedianGetSmall() {
		if (cnt % 2 == 0) return smaller.top();
		else return center;
	}
};





int Q;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> Q;

	MedianStructure<ll> ms;
	ll b_sm = 0;

	rep(_, 0, Q) {
		int t; cin >> t;
		if (t == 1) {
			int a, b; cin >> a >> b;
			ms.add(a);
			b_sm += b;
		}
		else {
			ll ans1 = ms.getMedianGetSmall();
			ll ans2 = b_sm;

			ans2 += ms.sm_bigger - ans1 * (ms.cnt / 2);
			ans2 += ans1 * (ms.cnt / 2) - ms.sm_smaller;

			printf("%lld %lld\n", ans1, ans2);
		}
	}
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
///////////////////////// writeup2 end */
