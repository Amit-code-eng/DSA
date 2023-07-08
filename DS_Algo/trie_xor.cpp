

#include<bits/stdc++.h>
using namespace std;



class node{
    
    
  public:
    
    node* next[2];
    
};


class Trie{
    
    
  public:
    
    
    node* root;
    
    Trie(){
        
        
        root=new node();
        
    }
    
    
    
    
    void insert(int n){
        
        
        
        node* r=root;
        
        
        
        for(int i=31;i>=0;i--){
            
            int bit=(n>>i)&1;
            
            if(r->next[bit]==NULL){
                
                
                r->next[bit]=new node();
                
            }
            
            r=r->next[bit];
            
            
        }
        
        
        
        
    }
    
    
    
    int search(int n){
        
        
        
        int ans=0;
        
        node* r=root;
        
        for(int i=31;i>=0;i--){
            
            
            
            int bit=(n>>i)&1;
            
            if(r->next[1-bit]){
                
                
                ans|=(1<<i);
                
                r=r->next[1-bit];
                
            }
            
            else if(r->next[bit]){
                
                r=r->next[bit];
            }
            else break;
            
            
        }
        
        return ans;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
};




class p{
    
  
    public:
    
    int num,mx,id;
    
    p(int num,int mx,int id){
        
        
        this->mx=mx;
        this->num=num;
        this->id=id;
    }
    
    
    
};


struct cmp{
    
    
    bool operator()(p a,p b){
        
        
        return a.mx>b.mx;
        
    }
    
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        
        
        Trie r;
        int n=queries.size();
        
        vector<int>res(n);
        
        
        sort(nums.begin(),nums.end());
        
        
        
        priority_queue<p,vector<p>,cmp>pq;
        
        for(int i=0;i<n;i++){
            
            
            pq.push(p(queries[i][0],queries[i][1],i));
            
            
        }
        
         n=nums.size();
        int i=0;
        while(pq.size()){
            
            
            
            
            p a=pq.top();
            pq.pop();
            
            
            if(a.mx<nums[0]){
                
                res[a.id]=-1;continue;
                
            }
            
            
            while(i<n&& nums[i]<=a.mx){
                
                
                r.insert(nums[i++]);
                
                
                
                
            }
            
            
            res[a.id]=r.search(a.num);
            
            
        }
        
        return res;
        
    }
};




























