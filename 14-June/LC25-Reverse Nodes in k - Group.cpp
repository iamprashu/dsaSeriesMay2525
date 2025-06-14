//https://leetcode.com/problems/reverse-nodes-in-k-group/
class Solution {
public:

    void reverseK(ListNode* &head,ListNode* &current,ListNode* &previous,int &k){
        int counter = 1;
        while(counter <= k){
            ListNode* nextNode = current->next;
            current->next = previous;
            previous = current;
            current = nextNode;
            counter++;
        }
    }

    int getLength(ListNode* head){
        int length = 0;
        ListNode* temp = head;

        while(temp != NULL){
            length++;
            temp = temp->next;
        }

        return length;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        //edge cases
        if(head==NULL || head->next == NULL){
            return head;//if no node or single node then return head
        }
        
        int lengthofLL = getLength(head);

        if(lengthofLL < k){
            return head;
        }

        //reverse k
        ListNode* previous = NULL;
        ListNode* current = head;
        reverseK(head,current,previous,k); // passing actual memory address taki copy na bane
        
        // yaha tak reverse 

        if(current != NULL){
            ListNode* recursionHead = reverseKGroup(current,k); // as curent node har bar head banegi

            head->next = recursionHead;
        }

        return previous; // ye sabse front me hoga always
    }
};