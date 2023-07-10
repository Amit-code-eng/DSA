#include<bits/stdc++.h>
using namespace std;

static int seg[1000000+7];
class HLD{

    public:

    vector<vector<int>>g;

    vector<int>dep,hv,head,lt,pos,par,sz;

    int n,idx=1;
    HLD(vector<vector<int>>&g){


        this->g=g;
        this->n=g.size();
        dep.assign(n+1,0);
        sz.assign(n+1,0);
        hv.assign(n+1,0);
        pos.assign(n+1,0);
        par.assign(n+1,0);
        lt.resize(n+1);
        head.assign(n+1,0);

        dfs(1);
        dfsHLD(1,1);

        // seg.assign(4*(n+1),0);

        for(int i=0;i<4*(n+1);i++)seg[i]=0;
        

    }

    void dfs(int nd){


        for(int &c:g[nd]){

            if(c!=par[nd]){

                par[c]=nd;
                dep[c]=dep[nd]+1;

                dfs(c);
                if(sz[c]>sz[hv[nd]])hv[nd]=c;
                sz[nd]+=sz[c];
            }
        }

        sz[nd]++;
    }


    void dfsHLD(int nd,int chn){


        
        head[nd]=chn;
        lt[idx]=nd;
        pos[nd]=idx++;

        if(hv[nd]!=0){

            dfsHLD(hv[nd],chn);
        }

        for(int &c:g[nd]){


            if(c==par[nd]||c==hv[nd])continue;

            dfsHLD(c,c);
        }

    }

    // segment build initial zero

    void upd(int x){


        up(0,0,n,pos[x]);

    }

    int qry(int x){

        int v=x;
        
        while(v){

            int res=q(0,0,n,pos[head[v]],pos[v]);
            
            if(res)return res;
            v=par[head[v]];
        

        }

        return -1;


    }

    void up(int nd,int st,int en,int x){


        if(st==en){

            seg[nd]=(seg[nd])?0:lt[en];
            return ;
        }

        else{



            int mid=st+(en-st)/2;

            if(st<=x&&x<=mid){

                up(2*nd+1,st,mid,x);
            }else{

                up(2*nd+2,mid+1,en,x);
            }

            seg[nd]=(seg[2*nd+2])?seg[2*nd+2]:seg[2*nd+1];


            
        }



    }


    int q(int nd,int st,int en,int l,int r){

    

        if(r<st||en<l)return 0;

        if(l<=st&&en<=r)return seg[nd];

        else{


            int mid=st+(en-st)/2;

            int rt=q(2*nd+2,mid+1,en,l,r);
            if(rt)return rt;
            return q(2*nd+1,st,mid,l,r);
        }
    }

};


int main(){


    int n,q;cin>>n>>q;

    vector<vector<int>>g(n+1);

    for(int i=1;i<n;i++){

        int a,b;cin>>a>>b;

        g[a].push_back(b);
        g[b].push_back(a);

    }

    HLD hld(g);
    static int ans[1000000+7];
    int i=0;
    while(q--){

        int f,x;cin>>f>>x;

        if(f){


            ans[i++]=hld.qry(x);
        }

        else{

            hld.upd(x);
        }

    }

    for(int j=0;j<i;j++){

        cout<<ans[j]<<endl;
    }
    

    return 0;
}