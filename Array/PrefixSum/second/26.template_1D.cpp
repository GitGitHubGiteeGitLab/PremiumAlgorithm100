#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    
    vector<int> v(n+1);
    for(int i = 1; i <= n; i++)cin >> v[i];

    vector<long long> dp(n+1);
    dp[0] = 0;
    for(int i = 1; i <= n; i++)dp[i] = v[i] + dp[i-1];

    int l, r;
    while(q){
       cin >> l >> r;
       cout << dp[r] - dp[l-1] << endl;
       q--;
    }
    return 0;
}