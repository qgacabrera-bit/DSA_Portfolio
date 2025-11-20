#include <iostream>

int getMinSteps( int n, int *memo ){
    if( n == 1 ) return 0;
    if( memo[n] != -1 ) return memo[n];
    int r = 1 + getMinSteps( n-1, memo );
    if ( n%2 == 0 ) r = std::min( r, 1 + getMinSteps( n / 2, memo));
    if ( n%3 == 0 ) r = std::min( r, 1 + getMinSteps( n / 3, memo ));
    memo[n] = r;
    return memo[n];
}

int getMinSteps( int n ){
    int memo[n+1];

    for(int i = 0; i <= n; i++){
        memo[i] = -1;
    }
    return getMinSteps(n, memo);
}

int main() {
    std::cout << getMinSteps(100) << std::endl;
    return 0;
}