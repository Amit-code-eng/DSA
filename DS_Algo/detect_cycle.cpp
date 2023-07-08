#include <bits/stdc++.h>
using namespace std;



class ListNode{

    public:
    int val;
    bool vis;
    ListNode* next;
    ListNode(){


        val=-1;
        vis=0;
        this->next=NULL;
    }

};


bool detect_cycle(ListNode* head){


    if(!head)return 0;

    unordered_set<ListNode*>st;
    while(head){

        if(st.find(head)!=st.end()){

            st.insert(head);
            head=head->next;
        }
        else {
            return 1;
        }

    }
    return 0;

}


bool cycle(ListNode* head){


    if(!head)return 0;

    while(head){


        if(head->vis)return 1;
        else {

            head->vis=1;
            head=head->next;
        }
    }

    return 0;

}


bool hasCycle(ListNode *head)
{



       
        // if(head==NULL)return 0;
        
        // ListNode* slow=head,*fast=head;
        
        // do{
            
        //     if(fast->next==NULL || fast->next->next==NULL)return 0;
        //     slow=slow->next;
        //     fast=fast->next->next;
        // }while(slow!=fast);
        
        // return 1;

    if (!head || !head->next)
        return 0;

    ListNode *slow = head, *fast = head;
    while (fast && fast->next)
    {

        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return 1;
    }
    return 0;
}

int main()
{

    return 0;
}