//https://www.hackerrank.com/contests/75th/challenges/nada-picnic
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
                      Welcome to My Coding Space!       @hamayanhamayan0
---------------------------------------------------------------------------------------------------*/












int N;
string destinations[3] = { "Shiitakerando", "Otsukakokusaibijutsukan", "Spring-8" };
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N;
    cout << destinations[N - 1] << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
良い問題。
なんとなくセンチメンタルになる。

答えは三択であるが、問題文からワードを取ってくるときは必ずコピペしてくること。
間違えんわ！って言ってるやつほど間違える。
///////////////////////// writeup2 end */
//　