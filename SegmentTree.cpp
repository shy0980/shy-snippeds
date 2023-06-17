class streeMin{
private:
	int *st;
	int n;
	int max_size;
public:
	streeMin(int arr[], int size) {
		n  = size;
		int x = (int)(ceil(log2(n)));
 
	    //Maximum size of segment tree
	    max_size = 2*(int)pow(2, x) - 1;
	 
	    // Allocate memory
	    st = new int[max_size];
	 
	    // Fill the allocated memory st
	    constructSTUtil(arr, 0, n-1, 0);
	}

	int constructSTUtil(int arr[], int ss, int se, int si) {
		if (ss == se)
	    {
	        st[si] = arr[ss];
	        return arr[ss];
	    }
	 
	    // If there are more than one elements, then recur for left and
	    // right subtrees and store the sum of values in this node
	    int mid = (ss+se)/2;
	    st[si] = min(constructSTUtil(arr, ss, mid,si*2+1),
	    	            constructSTUtil(arr, mid+1, se, si*2+2));
	    return st[si];
	}

	int getMinUtil(int ss, int se, int qs, int qe, int si)
	{
	    // If segment of this node is a part of given range, then return
	    // the sum of the segment
	    if (qs <= ss && qe >= se)
	        return st[si];
	 
	    // If segment of this node is outside the given range
	    if (se < qs || ss > qe)
	        return INT_MAX;
	 
	    // If a part of this segment overlaps with the given range
	    int mid = (ss+se)/2;
	    return min(getMinUtil(ss, mid, qs, qe, 2*si+1),
	    	        getMinUtil(mid+1, se, qs, qe, 2*si+2));
	}

	int getMin(int qs, int qe)
	{
	    // Check for erroneous input values
	    if (qs < 0 || qe > n-1 || qs > qe)
	    {
	        cout<<"Invalid Input";
	        return -1;
	    }
	 
	    return getMinUtil(0, n-1, qs, qe, 0);
	}

	int UpdateVal(int val, int index, int ss, int se,int si) {
		if(ss==se && ss==index) {
			st[si] = val;
			return st[si];
		}

		if(index<ss || index>se) {
			return st[si];
		}

		int mid = (ss+se)/2;
		st[si] = min(UpdateVal(val,index,ss,mid,si*2+1),UpdateVal(val,index,mid+1,se,si*2+2));
		return st[si];
	}

	void updateValue(int val, int index) {
		UpdateVal(val, index, 0,n-1, 0);
	}

	void display() {
		for (int i = 0; i < max_size; ++i)
		{
			cout<<st[i]<<" ";  
		}
		cout<<endl;
	}

};

class streeMin{
private:
	int *st;
	int n;
	int max_size;
public:
	streeMin(int arr[], int size) {
		n  = size;
		int x = (int)(ceil(log2(n)));
 
	    //Maximum size of segment tree
	    max_size = 2*(int)pow(2, x) - 1;
	 
	    // Allocate memory
	    st = new int[max_size];
	 
	    // Fill the allocated memory st
	    constructSTUtil(arr, 0, n-1, 0);
	}

	int constructSTUtil(int arr[], int ss, int se, int si) {
		if (ss == se)
	    {
	        st[si] = arr[ss];
	        return arr[ss];
	    }
	 
	    // If there are more than one elements, then recur for left and
	    // right subtrees and store the sum of values in this node
	    int mid = (ss+se)/2;
	    st[si] = constructSTUtil(arr, ss, mid,si*2+1)+
	    	            constructSTUtil(arr, mid+1, se, si*2+2);
	    return st[si];
	}

	int getSumUtil(int ss, int se, int qs, int qe, int si)
	{
	    // If segment of this node is a part of given range, then return
	    // the sum of the segment
	    if (qs <= ss && qe >= se)
	        return st[si];
	 
	    // If segment of this node is outside the given range
	    if (se < qs || ss > qe)
	        return 0;
	 
	    // If a part of this segment overlaps with the given range
	    int mid = (ss+se)/2;
	    return getSumUtil(ss, mid, qs, qe, 2*si+1)+
	    	        getSumUtil(mid+1, se, qs, qe, 2*si+2);
	}

	int getSum(int qs, int qe)
	{
	    // Check for erroneous input values
	    if (qs < 0 || qe > n-1 || qs > qe)
	    {
	        cout<<"Invalid Input";
	        return -1;
	    }
	 
	    return getSumUtil(0, n-1, qs, qe, 0);
	}

	int UpdateVal(int val, int index, int ss, int se,int si) {
		if(ss==se && ss==index) {
			st[si] = val;
			return st[si];
		}

		if(index<ss || index>se) {
			return st[si];
		}

		int mid = (ss+se)/2;
		st[si] = (UpdateVal(val,index,ss,mid,si*2+1)+UpdateVal(val,index,mid+1,se,si*2+2));
		return st[si];
	}

	void updateValue(int val, int index) {
		UpdateVal(val, index, 0,n-1, 0);
	}

	void display() {
		for (int i = 0; i < max_size; ++i)
		{
			cout<<st[i]<<" ";  
		}
		cout<<endl;
	}

};

#define tree st
class streeMin{
private:
	int *st;
	int n;
	int max_size;
	int *lazy;
public:
	streeMin(int arr[], int size) {
		n  = size;
		int x = (int)(ceil(log2(n)));
 
	    //Maximum size of segment tree
	    max_size = 2*(int)pow(2, x) - 1;
	 
	    // Allocate memory
	    st = new int[max_size];

	    lazy = new int[max_size];
	 
	    // Fill the allocated memory st
	    constructSTUtil(arr, 0, n-1, 0);
	}

	int constructSTUtil(int arr[], int ss, int se, int si) {
		if (ss == se)
	    {
	        st[si] = arr[ss];
	        return arr[ss];
	    }
	 	lazy[si]=0;
	    // If there are more than one elements, then recur for left and
	    // right subtrees and store the sum of values in this node
	    int mid = (ss+se)/2;
	    st[si] = constructSTUtil(arr, ss, mid,si*2+1)+
	    	            constructSTUtil(arr, mid+1, se, si*2+2);
	    return st[si];
	}

	int getSumUtil(int ss, int se, int qs, int qe, int si)
	{
		// If lazy flag is set for current node of segment tree,
	    // then there are some pending updates. So we need to
	    // make sure that the pending updates are done before
	    // processing the sub sum query
	    if (lazy[si] != 0)
	    {
	        // Make pending updates to this node. Note that this
	        // node represents sum of elements in arr[ss..se] and
	        // all these elements must be increased by lazy[si]
	        tree[si] += (se-ss+1)*lazy[si];
	 
	        // checking if it is not leaf node because if
	        // it is leaf node then we cannot go further
	        if (ss != se)
	        {
	            // Since we are not yet updating children os si,
	            // we need to set lazy values for the children
	            lazy[si*2+1] += lazy[si];
	            lazy[si*2+2] += lazy[si];
	        }
	 
	        // unset the lazy value for current node as it has
	        // been updated
	        lazy[si] = 0;
	    }
	 
	    // Out of range
	    if (ss>se || ss>qe || se<qs)
	        return 0;
	 
	    // At this point we are sure that pending lazy updates
	    // are done for current node. So we can return value
	    // (same as it was for query in our previous post)
	 
	    // If this segment lies in range
	    if (ss>=qs && se<=qe)
	        return tree[si];
	 
	    // If a part of this segment overlaps with the given
	    // range
	    int mid = (ss + se)/2;
	    return getSumUtil(ss, mid, qs, qe, 2*si+1) +
	           getSumUtil(mid+1, se, qs, qe, 2*si+2);
	}

	int getSum(int qs, int qe)
	{
	    // Check for erroneous input values
	    if (qs < 0 || qe > n-1 || qs > qe)
	    {
	        cout<<"Invalid Input";
	        return -1;
	    }
	 
	    return getSumUtil(0, n-1, qs, qe, 0);
	}

	void updateRangeUtil(int si, int ss, int se, int us, int ue, int diff)
	{
	    // If lazy value is non-zero for current node of segment
	    // tree, then there are some pending updates. So we need
	    // to make sure that the pending updates are done before
	    // making new updates. Because this value may be used by
	    // parent after recursive calls (See last line of this
	    // function)
	    if (lazy[si] != 0)
	    {
	        // Make pending updates using value stored in lazy
	        // nodes
	        tree[si] += (se-ss+1)*lazy[si];
	 
	        // checking if it is not leaf node because if
	        // it is leaf node then we cannot go further
	        if (ss != se)
	        {
	            // We can postpone updating children we don't
	            // need their new values now.
	            // Since we are not yet updating children of si,
	            // we need to set lazy flags for the children
	            lazy[si*2 + 1]   += lazy[si];
	            lazy[si*2 + 2]   += lazy[si];
	        }
	 
	        // Set the lazy value for current node as 0 as it
	        // has been updated
	        lazy[si] = 0;
	    }
	 
	    // out of range
	    if (ss>se || ss>ue || se<us)
	        return ;
	 
	    // Current segment is fully in range
	    if (ss>=us && se<=ue)
	    {
	        // Add the difference to current node
	        tree[si] += (se-ss+1)*diff;
	 
	        // same logic for checking leaf node or not
	        if (ss != se)
	        {
	            // This is where we store values in lazy nodes,
	            // rather than updating the segment tree itself
	            // Since we don't need these updated values now
	            // we postpone updates by storing values in lazy[]
	            lazy[si*2 + 1]   += diff;
	            lazy[si*2 + 2]   += diff;
	        }
	        return;
	    }
	 
	    // If not completely in rang, but overlaps, recur for
	    // children,
	    int mid = (ss+se)/2;
	    updateRangeUtil(si*2+1, ss, mid, us, ue, diff);
	    updateRangeUtil(si*2+2, mid+1, se, us, ue, diff);
	 
	    // And use the result of children calls to update this
	    // node
	    tree[si] = tree[si*2+1] + tree[si*2+2];
	}

	void updateRange(int val, int start, int end) {
		updateRangeUtil(0,0,n-1,start,end,val);
	}

	void display() {
		for (int i = 0; i < max_size; ++i)
		{
			cout<<st[i]<<" ";  
		}
		cout<<endl;
		for (int i = 0; i < max_size; ++i)
		{
			cout<<st[i]<<" ";  
		}
		cout<<endl;
	}

};