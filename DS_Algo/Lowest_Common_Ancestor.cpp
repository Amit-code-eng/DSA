#include<bits/stdc++.h>
using namespace std;



class HLD{


    public:

    vector<int>dep,sz,p,hv,head,lt;
    vector<vector<int>>g;
    int n,idx=1;

    HLD(vector<vector<int>>&g){

        this->n=g.size();
        this->g=g;

        dep.assign(n+1,0);
        sz.assign(n+1,0);
        p.assign(n+1,0);
        hv.assign(n+1,0);
        head.assign(n+1,0);
        lt.assign(n+1,0);
        


        dfs(1);
        dfsHLD(1,1);


    }

    void dfs(int nd){





        for(int &c:g[nd]){

            dep[c]=dep[nd]+1;

            p[c]=nd;

            dfs(c);
            if(sz[c]>sz[hv[nd]]){

                hv[nd]=c;
            }
            sz[nd]+=sz[c];


        }


        sz[nd]++;


    }


    void dfsHLD(int nd,int chn){

        head[nd]=chn;
        lt[nd]=idx++;

        if(hv[nd]!=0){

            dfsHLD(hv[nd],chn);
        }

        for(int &c:g[nd]){


            if(c!=hv[nd]){

                dfsHLD(c,c);
            }
        }


    }



    int lca(int a,int b){


        while(head[a]!=head[b]){

            if(dep[head[a]]<dep[head[b]])swap(a,b);

            a=p[head[a]];


        }

        if(dep[b]<dep[a])swap(a,b);

        return a;

    }


};

int main(){


    int t;cin>>t;
    int k=1;
    while(k<=t){


        int n;
        cin>>n;
        vector<vector<int>>g(n+1);

        for(int i=1;i<=n;i++){


            int s;cin>>s;
            while(s--){

                int x;cin>>x;
                g[i].push_back(x);
            }
        }

        HLD lcs(g);
        cout<<"Case "<<k<<":"<<endl;
        int q;cin>>q;
        while(q--){


            int a,b;cin>>a>>b;

            cout<<lcs.lca(a,b)<<endl;

        }
        k++;
    }


    return 0;
}