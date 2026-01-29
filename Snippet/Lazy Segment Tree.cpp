int seg[4*N], lazy[4*N], ar[N];
void build(int n, int b, int e){
	if(b==e){
		seg[n]=ar[b];
		return;
	}
	int mid=(b+e)>>1, l=n<<1, r=l|1;
	build(l, b, mid);
	build(r, mid+1, e);
	seg[n]=seg[l]+seg[r];
	lazy[n]=0;
}
void push(int n, int b, int e){
	if(lazy[n]==0)
		return;
	seg[n]=lazy[n]*(e-b+1);
	int l=n<<1, r=l|1;
	if(b!=e){
		lazy[l]=lazy[n];
		lazy[r]=lazy[n];
	}
	lazy[n]=0;
}
void update(int n, int b, int e, int i, int j, int x){
	push(n, b, e);
	if(b>j or e<i)
		return;
	if(b>=i and e<=j){
		lazy[n]=x;
		push(n, b, e);
		return;
	}
	int mid=(b+e)>>1, l=n<<1, r=l|1;
	update(l, b, mid, i, j, x);
	update(r, mid+1, e, i, j, x);
	seg[n]=seg[l]+seg[r];
}
int query(int n, int b, int e, int i, int j){
	push(n, b, e);
	if(b>j or e<i)
		return 0;
	if(b>=i and e<=j)
		return seg[n];
	int mid=(b+e)>>1, l=n<<1, r=l|1;
	int ll=query(l, b, mid, i, j);
	int rr=query(r, mid+1, e, i, j);
	return ll+rr;
}
