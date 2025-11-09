class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return NULL;
        map<int,int>m;
vector<int>arr;
vector<int>ans;
ListNode*temp=head;

while(temp){
    arr.push_back(temp->val);
    temp=temp->next;
}

for(auto &t:arr){
    m[t]++;
}

for(auto it=m.begin();it!=m.end();it++){

    if(it->second<2){
        ans.push_back(it->first);
    }
}
if(ans.empty()) return NULL;
ListNode* newHead=new ListNode(ans[0]);
ListNode*curr=newHead;
for(int i=1;i<ans.size();i++){
    curr->next=new ListNode(ans[i]);
    curr=curr->next;
}
return newHead;
    }