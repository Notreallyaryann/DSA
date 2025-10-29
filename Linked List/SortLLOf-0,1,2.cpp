class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        Node*temp=head;
        vector<int>arr;
        
        while(temp){
            arr.push_back(temp->data);
            temp=temp->next;
        }
        
        int n=arr.size();
        int left=0,mid=0,right=n-1;
        
        while(mid<=right){
            
            if(arr[mid]==0){
                swap(arr[mid],arr[left]);
                left++;
                mid++;
            }else if(arr[mid]==1){
                mid++;
            }else{
                swap(arr[mid],arr[right]);
                right--;
            }
        }
        
    Node*dummy=new Node(-1);
    Node*curr=dummy;
    
    for(int i=0;i<n;i++){
        curr->next=new Node(arr[i]);
        curr=curr->next;
    }
        return dummy->next;
        
        
    }
};