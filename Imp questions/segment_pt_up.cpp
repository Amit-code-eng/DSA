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


void up(int nd,int st,int en,int pos,int val,vector<int>&seg,vector<int>&v){

    
    if(st==en){

        seg[nd]=val;
        v[pos]=val;
    }
    else{

        int mid=st+(en-st)/2;

        if(st<=pos&&pos<=mid)    up(2*nd+1,st,mid,pos,val,seg,v);
        else up(2*nd+2,mid+1,en,pos,val,seg,v);
        seg[nd]=max(seg[2*nd+1],seg[2*nd+2]);
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


        int q,l,r;
        cin>>q>>l>>r;
        if(q)cout<<qry(0,0,n-1,l,r,seg)<<endl;
        else{

            up(0,0,n-1,l,r,seg,v);

        }
    }

    return 0;
}