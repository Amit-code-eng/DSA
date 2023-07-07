#include<bits/stdc++.h>
using namespace std;

void buildy(int xnd,int xst,int xen,int ynd,int yst,int yen,vector<vector<int>>&seg,vector<vector<int>>&v){


    if(yst==yen){


        if(xst==xen){

            seg[xnd][ynd]=v[xst][yst];
        }else{


            seg[xnd][ynd]=min(seg[2*xnd+1][ynd],seg[2*xnd+2][ynd]);
        }
    }
    else{



        int mid=yst+(yen-yst)/2;

        buildy(xnd,xst,xen,2*ynd+1,yst,mid,seg,v);
        buildy(xnd,xst,xen,2*ynd+2,mid+1,yen,seg,v);
        
        seg[xnd][ynd]=min(seg[xnd][2*ynd+1],seg[xnd][2*ynd+2]);



    }


}

void buildx(int nx,int nst,int nen,vector<vector<int>>&seg,vector<vector<int>>&v){


    if(nst==nen){

        buildy(nx,nst,nen,0,0,seg[0].size()/4-1,seg,v);
    }else{


        int mid=nst+(nen-nst)/2;

        buildx(2*nx+1,nst,mid,seg,v);
        buildx(2*nx+2,mid+1,nen,seg,v);
        buildy(nx,nst,nen,0,0,seg[0].size()/4-1,seg,v);
        
    }
    
}


void upy(int xnd,int xst,int xen,int ynd,int yst,int yen,int x,int y,int val,vector<vector<int>>&seg){


    if(yst==yen){



        if(xst==xen){

            seg[xnd][ynd]+=val;

        }

        else{

            seg[xnd][ynd]=min(seg[2*xnd+1][ynd],seg[2*xnd+2][ynd]);
        }

    }

    else{


        int mid=yst+(yen-yst)/2;

        if(yst<=y && y<=mid){


            upy(xnd,xst,xen,2*ynd+1,yst,mid,x,y,val,seg);
        }else{

            upy(xnd,xst,xen,2*ynd+2,mid+1,yen,x,y,val,seg);

        }

        seg[xnd][ynd]=min(seg[xnd][2*ynd+1],seg[xnd][2*ynd+2]);

    }


}

void upx(int xnd,int xst,int xen,int x,int y,int val,vector<vector<int>>&seg){





    if(xst==xen){

        upy(xnd,xst,xen,0,0,(seg[0].size()/4)-1,x,y,val,seg);


    }else{

        int mid=xst+(xen-xst)/2;

        if(xst<=x&&x<=mid){

            upx(2*xnd+1,xst,mid,x,y,val,seg);
        }else{

            upx(2*xnd+2,mid+1,xen,x,y,val,seg);
        }

        
        upy(xnd,xst,xen,0,0,(seg[0].size()/4)-1,x,y,val,seg);




    }



}


int qy(int xnd,int xst,int xen,int ynd,int yst,int yen,int lx,int ly,int rx,int ry,vector<vector<int>>&seg){


    if(yen<ly||ry<yst)return INT_MAX;

    if(ly<=yst && yen<=ry){

        return seg[xnd][ynd];
    }else{

        int mid=yst+(yen-yst)/2;

        int l=qy(xnd,xst,xen,2*ynd+1,yst,mid,lx,ly,rx,ry,seg);
        int r=qy(xnd,xst,xen,2*ynd+2,mid+1,yen,lx,ly,rx,ry,seg);

        return min(l,r);



    }


}

int qx(int xnd,int xst,int xen,int lx,int ly,int rx,int ry,vector<vector<int>>&seg){



    if(xen<lx||rx<xst)return INT_MAX;

    if(lx<=xst&&xen<=rx){


        return qy(xnd,xst,xen,0,0,(seg[0].size()/4)-1,lx,ly,rx,ry,seg);
    }else{



        int mid=xst+(xen-xst)/2;

        int l=qx(2*xnd+1,xst,mid,lx,ly,rx,ry,seg);
        int r=qx(2*xnd+2,mid+1,xen,lx,ly,rx,ry,seg);
        return min(l,r);
    }

}

int main(){


    int n,m;cin>>n>>m;

    vector<vector<int>>v(n,vector<int>(m));

    for(int i=0;i<n;i++){

        for(int j=0;j<m;j++){

            cin>>v[i][j];
        }
    }

    vector<vector<int>>seg(4*n,vector<int>(4*m));

    buildx(0,0,n-1,seg,v);
    int q;cin>>q;

    while(q--){

        char c;cin>>c;
        if(c=='q'){

            int lx,ly,rx,ry;cin>>lx>>ly>>rx>>ry;

            cout<<qx(0,0,n-1,lx-1,ly-1,rx-1,ry-1,seg)<<endl;
        }else{

            int x,y,val;cin>>x>>y>>val;

            upx(0,0,n-1,x-1,y-1,val,seg);

        }

    }



    return 0;
}