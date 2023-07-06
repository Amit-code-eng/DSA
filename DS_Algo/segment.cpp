#include<bits/stdc++.h>
using namespace std;



void build(int nd,int st,int en,vector<int>&seg,vector<int>&lazy,vector<int>&v){


    if(st==en){

        seg[nd]=v[st];
    }else{


        int mid=st+(en-st)/2;

        build(2*nd+1,st,mid,seg,lazy,v);
        build(2*nd+2,mid+1,en,seg,lazy,v);

        seg[nd]=seg[2*nd+1]+seg[2*nd+2];
    }
    lazy[nd]=0;

}


void up(int nd,int st,int en,int l,int r,int val,vector<int>&seg,vector<int>&lazy){

    if(lazy[nd]){


        if(st!=en) {lazy[2*nd+1]+=lazy[nd];
        lazy[2*nd+2]+=lazy[nd];}

        seg[nd]+=(en-st+1)*lazy[nd];
        lazy[nd]=0;

    }

    if(en<l||r<st)return ;

    if(l<=st&&en<=r){


        if(st!=en){

            lazy[2*nd+1]+=val;
            lazy[2*nd+2]+=val;
        }

        seg[nd]+=(en-st+1)*val;
    }
    else{


        int mid=st+(en-st)/2;

        up(2*nd+1,st,mid,l,r,val,seg,lazy);
        up(2*nd+2,mid+1,en,l,r,val,seg,lazy);
        seg[nd]=seg[2*nd+1]+seg[2*nd+2];
        
    }


}


int qry(int nd,int st,int en,int l,int r,vector<int>&seg,vector<int>&lazy){



    if(lazy[nd]){

       if(st!=en) {lazy[2*nd+1]+=lazy[nd];
        lazy[2*nd+2]+=lazy[nd];}

        seg[nd]+=(en-st+1)*lazy[nd];
        lazy[nd]=0;
    }

    if(r<st||en<l)return 0;
    if(l<=st&&en<=r){

        return seg[nd];
    }

    else{


        int mid=st+(en-st)/2;

        return qry(2*nd+1,st,mid,l,r,seg,lazy)+qry(2*nd+2,mid+1,en,l,r,seg,lazy);
    }


}








int main(){


    int n;cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];

    vector<int> seg(4*n),lazy(4*n);
    build(0,0,n-1,seg,lazy,v);
    int q;cin>>q;
    while(q--){


        bool f;cin>>f;

        if(f){


            int l,r,val;cin>>l>>r>>val;

            up(0,0,n-1,l,r,val,seg,lazy);
        }else{


            int l,r;
            cin>>l>>r;
            cout<<qry(0,0,n-1,l,r,seg,lazy)<<endl;
        }

    }

    return 0;
}