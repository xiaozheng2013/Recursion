// This problem is asking us to reverse an array of numbers in a 
// group of k elements once. In the big recursion, it contains two 
// recursions, one is itself(of a smaller size), the other is the
// function reverse, which is the one super inspirative, it deals
// with reverse an array recursively, but with the minimal complexity
// , especially in this problem, I did some smart modification of the 
// end pointer of the first group of k numbers, and make the recursion
// super appealing.

class Solution {
public:
    ListNode *reverse(ListNode* head, ListNode* end) {
        //I want to reverse the first k nodes, and link it with end
        if(head->next == end) return head;
        else{
            ListNode* newHead = reverse(head->next,end);
            head->next->next = head;
            head->next = end;
            return newHead;
        }
    }
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(k<=1 || head==NULL) return head;
        int i=0;
        ListNode *nd = head;
        ListNode *prev = head;
        while(nd!=NULL && i<k) {
            prev = nd;
            nd = nd->next;
            i++;
        }
        if(i<k) return head;
        else {
            ListNode *end = reverseKGroup(nd,k);
            prev->next = end;
            return reverse(head,end);
        }
    }

};
