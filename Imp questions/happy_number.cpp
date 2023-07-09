

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    int solve(int n){
        
        int sum=0;
        while(n!=0){
            int k=n%10;
            sum+=k*k;
            n/=10;
        }
        return sum;
    }
    
    bool isHappy(int n) {
       
        
        int fast=n,slow=n;
        
        do{
            slow=solve(slow);
            fast=solve(solve(fast));
        }while(slow!=fast);
        return slow==1;
        
    }
};