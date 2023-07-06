#include<bits/stdc++.h>
using namespace std;


void build(int nd,int st,int en,vector<int>&seg,vector<int>&v){


    if(st==en){

        seg[nd]=v[st];
    }else{


        int mid=st+(en-st)/2;
        build(2*nd+1,st,mid,seg,v);
        build(2*nd+2,mid+1,en,seg,v);
        seg[nd]=0;
    }
}


void up(int nd,int st,int en,int l,int r,int val,vector<int>&seg){

    if(st!=en&&seg[nd]){

        seg[2*nd+1]+=seg[nd];
        seg[2*nd+2]+=seg[nd];
        seg[nd]=0;

    }

    if(r<st||en<l)return;


    if(l<=st && en<=r){

        seg[nd]+=val;
    }else{


        int mid=st+(en-st)/2;
        up(2*nd+1,st,mid,l,r,val,seg);
        up(2*nd+2,mid+1,en,l,r,val,seg);
        
    }


}

int qry(int nd,int st,int en,int pos,vector<int>&seg){

    if(st!=en && seg[nd]){

        seg[2*nd+1]+=seg[nd];
        seg[2*nd+2]+=seg[nd];
        seg[nd]=0;
    }
    if(st==en)return seg[nd];

    else{


        int mid=st+(en-st)/2;
        if(st<=pos && pos<=mid)return qry(2*nd+1,st,mid,pos,seg);
        
        else return qry(2*nd+2,mid+1,en,pos,seg);
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

        bool f;cin>>f;

        if(f){

            int l,r,val;cin>>l>>r>>val;

            up(0,0,n-1,l,r,val,seg);

        }else{

            int pos;cin>>pos;

            cout<<qry(0,0,n-1,pos,seg)<<endl;

            
        }

    }



    return 0;
}