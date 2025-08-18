class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      ListNode* first=headA;
      ListNode* second=headB;
     int countA=0;
     int countB=0;

     while(first){
        countA++;
        first=first->next;
     }
     while(second){
        countB++;
        second=second->next;
     }
while(countA>countB){
    countA--;
   headA=headA->next;
}
while(countB>countA){
    countB--;
   headB=headB->next;
}

while(headA!=headB){
     headA=headA->next;
    headB=headB->next;
}
return headA;
    }
};