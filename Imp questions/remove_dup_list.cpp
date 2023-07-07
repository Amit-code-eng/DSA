

#include<bits/stdc++.h>
using namespace std;


//  * Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };



 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(!head||!(head->next))return head;
        ListNode* temp=head;
        head=head->next;
        ListNode* t=temp;

        while(head){


            if(head->val!=temp->val){

                temp->next->val=head->val;
                temp=temp->next;

            }
            head=head->next;
        }

        temp->next=NULL;

        return t;




    }
};