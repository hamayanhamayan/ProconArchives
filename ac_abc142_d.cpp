//https://atcoder.jp/contests/abc142/tasks/abc142_d
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
ll gcd(ll a,ll b){return a?gcd(b%a,a):b;}
map<ll,int> enumpr(ll n) {
	map<ll,int> V;
	for(ll i=2;i*i<=n;i++) while(n%i==0) V[i]++,n/=i;
	if(n>1) V[n]++;
	return V;
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

ll A, B;
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> A >> B;
    auto ep = enumpr(gcd(A, B));
    int ans = ep.size() + 1;
    cout << ans << endl;
}






/* ///////////////////////// writeup1 start
# 前提知識
- [最大公約数計算、素因数分解](https://www.hamayanhamayan.com/entry/2017/10/14/125941)
///////////////////////// writeup2 start
AもBの公約数を列挙する。
といっても、公約数は最大公約数の約数となるので、とりあえず、最大公約数を求める。
互いに素であるということは、同じ素数を使っていないということになる。
つまり、最大公約数を素因数分解したときに、構成される素数の個数分分けるのが最適になる。
なので、素因数分解をして、その個数を求めたら答え。
///////////////////////// writeup2 end */
