#include <iostream>
#include <vector>
using namespace std;
 
int main(){
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    
    int i = 0, a = 0, b = 0, ans = n;
    while(i < n){
        if(nums[i]&1){
            while(i < n && nums[i]&1) i++, a++;
            while(i < n && !(nums[i]&1)) i++, b++;
        }else{
            while(i < n && !(nums[i]&1)) i++, a++;
            while(i < n && nums[i]&1) i++, b++;
        }
        
        if(a > b){
            ans -= 2*b;
            a = a - b;
            b = 0;
        }else{
            ans -= 2*a;
            b = b - a;
            a = 0;
        }
    }
    cout << ans << endl;
    return 0;
}
