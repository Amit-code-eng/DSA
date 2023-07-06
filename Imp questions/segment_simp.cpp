#include<bits/stdc++.h>
using namespace std;


void build(int nd,int st,int en,vector<int>&seg,vector<int>&v){



    if(st==en){

        seg[nd]=v[st];
    }else{


        int mid=st+(en-st)/2;
        build(2*nd+1,st,mid,seg,v);
        build(2*nd+2,mid+1,en,seg,v);
        seg[nd]=max(seg[2*nd+1],seg[2*nd+2]);

    }
}


int qry(int nd,int st,int en,int l,int r,vector<int>&seg){


    if(en<l||r<st)return INT_MIN;

    if(l<=st&&en<=r)return seg[nd];
    else{

        int mid=st+(en-st)/2;
        return max(qry(2*nd+1,st,mid,l,r,seg),qry(2*nd+2,mid+1,en,l,r,seg));
    }

}


int main(){

    int n;cin>>n;
    vector<int>v(n);

    for(int i=0;i<n;i++)cin>>v[i];

    vector<int>seg(4*n);

    build(0,0,n-1,seg,v);

    int q;cin>>q;
    while(q--){


        int l,r;
        cin>>l>>r;
        cout<<qry(0,0,n-1,l,r,seg)<<endl;
    }

    return 0;
}