#include <iostream>

int getMinSteps( int n ){
    int dp[n+1], i;
    for( i = 2; i <= n; i ++ ){
        dp[i] = 1 + dp[i-1];
        if(i%2==0) dp[i] = std::min( dp[i], 1+dp[i/2]);
        if(i%3==0) dp[i] = std::min( dp[i], 1+dp[i/3]);
    }
    return dp[n];
}

int main() {
    std::cout << getMinSteps(7) << std::endl;
    return 0;
}