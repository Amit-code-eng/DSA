#include<bits/stdc++.h>
using namespace std;


// for String ABZ and its corresponding number n:
// n = (A+1) * 26^2 + (B+1) * 26^1 + (Z+1) * 26^0

// both sides -1
// n-1 = (A+1) * 26^2 + (B+1) * 26^1 + Z

// (n-1)%26 =  Z                                                  (1)
// (n-1)/26 = (A+1) * 26^1 + (B+1) * 26^0                         (2)


string convertToTitle(int columnNumber) {
        


        int n=columnNumber;string s="";
        while(n){


            n--;
            s.push_back('A'+n%26);
            n/=26;
        }
        reverse(s.begin(),s.end());

        return s;



    }

int main(){



    return 0;

}