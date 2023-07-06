#include<bits/stdc++.h>
using namespace std;


class sparse{


    public:

    vector<vector<int>>spr;
    int K;
    sparse(vector<int>&v){


        int n=v.size();
        K=log2(n);
        spr.resize(K+1,vector<int>(n));

        spr[0]=v;

        for(int i=1;i<=K;i++){


            for(int j=0;j+(1<<i)<=n;j++){


                spr[i][j]= fun(spr[i-1][j],spr[i-1][j+(1<<(i-1))],"min");
            }
        }

    }

    int fun(int a,int b,string s){

        
        if(s=="min")return min(a,b);
        else if(s=="max")return max(a,b);
        else if(s=="sum")return a+b;
        return -1;

    }


    int query(int l,int r,string s){



        int cnt=r-l+1;
        int k=log2(cnt);


        if(s=="min"){

            return min(spr[k][l],spr[k][r-(1<<k)+1]);
        }
        else if(s=="max")return max(spr[k][l],spr[k][r-(1<<k)+1]);
        else if(s=="sum"){

            int sum=0;
            for(int i=K;i>=0;i--){

                if((1<<i)<=(r-l+1)){

                    sum+=spr[i][l];
                    l+=(1<<i);
                }

            }
            return sum;
        }

        return -1;
    }

};


int main(){

	int n;cin>>n;
	vector<int>v(n);
	for(int i=0;i<n;i++){
		
		cin>>v[i];
	}
	int q;cin>>q;
	sparse res(v);
	while(q--){
		
		
		
		int l,r;cin>>l>>r;
		
		cout<<res.query(l,r,"min")<<endl;
	}



    return 0;
}