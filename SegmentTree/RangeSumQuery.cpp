void buildTree(int *arr ,ll *st, int i,int l,int r){
    
    if(l==r){
        st[i]=arr[l];
        return;
    }
    int mid=(l+r)/2;
    buildTree(arr,st,2*i+1,l,mid);
     buildTree(arr,st,2*i+2,mid+1,r);
     st[i]=st[2*i+1]+st[2*i+2];
    
}

void updateSegTree(int *arr, ll *st,int i,int idx,int val,int l,int r){
    if(l==r){
        arr[idx]=val;//update original array
        st[i]=val; //update seg tree
        return;
    }
    
    int mid=(l+r)/2;
    
    if(idx<=mid){
        updateSegTree(arr,st,2*i+1,idx,val,l,mid);
    }else{
         updateSegTree(arr,st,2*i+2,idx,val,mid+1,r);
    }
    st[i]=st[2*i+1]+st[2*i+2];
}

void updateValue(int *arr, ll *st, int n, int index, int new_val) {
    // add code here
    updateSegTree(arr, st, 0, index,new_val,0,n-1);
}

// Function to return sum of elements in range from index qs (query start)
// to qe (query end).

ll Query(ll *st, int start, int end, int i, int l, int r) {
    // No overlap
    if (r < start || l > end)
        return 0;

    // Complete overlap
    if (l <= start && end <= r)
        return st[i];

    int mid = (start + end) / 2;

    // Partial overlap → go both sides
    ll left = Query(st, start, mid, 2 * i + 1, l, r);
    ll right = Query(st, mid + 1, end, 2 * i + 2, l, r);

    return left + right;
}

ll getsum(ll *st, int n, int l, int r) {
    // Wrapper for Query
    if (l < 0 || r >= n || l > r)
        return 0;

    return Query(st, 0, n - 1, 0, l, r);
}

