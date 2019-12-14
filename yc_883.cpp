//https://yukicoder.me/problems/no/883
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

int N, K;
int M;
string ans[1010];
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N >> K;

    rep(m, 1, 1010) {
        if(m < K and N <= m * m) {
            M = m;
            break;
        }
        if(K <= m and N <= K * m) {
            M = m;
            break;
        }
    }

    rep(y, 0, M) rep(x, 0, M) ans[y] += ".";
    rep(y, 0, M) rep(dx, 0, K) ans[y][(y + dx) % M] = '#';

    int cnt = 0;
    rep(y, 0, M) rep(x, 0, M) if(ans[y][x] == '#') {
        if(cnt == N)
            ans[y][x] = '.';
        else
            cnt++;
    }
    
    printf("%d\n", M);
    rep(y, 0, M) printf("%s\n", ans[y].c_str());
}

/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
構築問題は色々な方針があるが、今回は最適方針があり、それで構築する方針を取ろう。
頑張れば全部の行と列でK個配置することができる。
つまり、Mを固定したときにMK個配置することが可能である。条件の制約的にこれが最適であることは自明である。
M<Kのときは、M^2個が上限なので、上限一杯に置いて、削ればいい。
そうでないときも上限一杯に置いて、削ればいいが、どのようにして置けば最適だろうか。

```
###.
.###
#.##
##.#
```

こんな感じに置けばいい。
Mについては、10^3くらいまで試せばいいから、全探索すればいい。
上限がK以上となったら、そのMを採用して、構築を進めていく。
///////////////////////// writeup2 end */
