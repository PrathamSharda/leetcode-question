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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode*temp=head;
        if (head==nullptr||k==0||head->next==nullptr){
            return head;
        }
        int count=0;
        ListNode*prev=head;
        while(prev){
            count++;
            prev=prev->next;
        }
        prev=head;
        k=k%count;
        if (k==0){
            return head;
        }
        k=count-k;
        count=0;
        while(temp->next&&count<k){
            prev=temp;
            count++;
            temp=temp->next;
        }
       
            prev->next=nullptr;
            prev=temp;
            while(temp->next){
                temp=temp->next;
            }
            temp->next=head;
            head=prev;
            return head;

    }
};