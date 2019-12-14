//https://atcoder.jp/contests/abc139/tasks/abc139_b
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














int A, B;
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> A >> B;
    int ans = (B - 1 + A - 2) / (A - 1);
    cout << ans << endl;
}

/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
B口以上に拡張と問題にはあるが、すでに1口はあるので、B-1口増やしたいという問題で考える。
電源タップを1つ使うと、1つの口がA個に増える。
つまり、1つ使うと、A-1個だけ口が増える。
なので、B-1個増やそうとした場合は、(B-1)/(A-1)の切り上げが答えになる。
切り上げする場合は、分子に分母-1を足すことで切り上げが可能。
///////////////////////// writeup2 end */
