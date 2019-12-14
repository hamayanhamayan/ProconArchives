//https://yukicoder.me/problems/no/893
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

int N;
queue<int> Q[1010];
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N;
    rep(i, 0, N) {
        int P; cin >> P;
        rep(j, 0, P) {
            int a;
            cin >> a;
            Q[i].push(a);
        }
    }

    vector<int> buf;
    rep(_, 0, 100) {
        rep(i, 0, N) if(!Q[i].empty()) {
            buf.push_back(Q[i].front());
            Q[i].pop();
        }
    }

    int M = buf.size();
    rep(i, 0, M) {
        if(i) printf(" ");
        printf("%d", buf[i]);
    }
    printf("\n");
}



/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
シミュレーションする。
Pの上限が10^2なので、最高でも100周はする。
レジが10^3個あるので、1周に10^3回確認するとしても、
全体の確認回数は10^5回なので間に合う。
先頭から順番にとっていく構造はqueueあたりを使うと、先頭管理がしやすい。
///////////////////////// writeup2 end */
