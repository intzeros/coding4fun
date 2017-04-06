#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;
 
double solve(double p, double q){
    double rst = 0;
    if(fabs(p-1.0) < 0.000000001) return 1.0;
    if(p > 0.000000001) rst += 1*p;
    int k = 1;
    double tmp = 1;
    while(true){
        if(p + k*q >= 1.0){
            tmp *= (1.0 - p - (k-1)*q);
            rst += (k+1) * tmp * 1.0;
            break;
        }else{
            tmp *= (1.0 - p - (k-1)*q);
            rst += (k+1) * tmp * (p+k*q);
        }
        k++;
    }
    return rst;
}
 
int main(){
    int P, Q, N;
    cin >> P >> Q >> N;
    double ans = 0, q = Q/100.0;
    int x = 1;
    for(int i = 1; i <= N; i++){
        double p = P/x / 100.0;
        ans += solve(p, q);
        if(p > 0.000000001){   // 避免 x 溢出
            x *= 2;
        }
    }
    printf("%.2lf\n", ans);
    return 0;
}
