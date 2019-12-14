//https://yukicoder.me/problems/no/932
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
vector<string> split(string str, string delim) { // strをdelimそれぞれで分割
	vector<string> items;
	size_t dlm_idx;
	if (str.npos == (dlm_idx = str.find_first_of(delim))) {
		items.push_back(str.substr(0, dlm_idx));
	}
	while (str.npos != (dlm_idx = str.find_first_of(delim))) {
		if (str.npos == str.find_first_not_of(delim)) {
			break;
		}
		items.push_back(str.substr(0, dlm_idx));
		dlm_idx++;
		str = str.erase(0, dlm_idx);
		if (str.npos == str.find_first_of(delim) && "" != str) {
			items.push_back(str);
			break;
		}
	}
	return items;
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














string S;
//---------------------------------------------------------------------------------------------------
#define yes "Done!"
#define no "Failed..."
void _main() {
	cin >> S;
	auto v = split(S, ",");

	fore(s, v) if (s != "AC") {
		cout << no << endl;
		return;
	}

	cout << yes << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
便利なカンマで分割する関数を作ろう。
（この機に作ると主にyukicoderで役に立つ。自分が使ってるやつも借りてきたやつなんですけどね）

///////////////////////// writeup2 end */
