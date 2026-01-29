
int seg[4*N], ar[N];
void build(int n, int b, int e){
	if(b==e){
		seg[n]=ar[b];
		return;
	}
	int mid=(b+e)>>1, l=n<<1, r=l|1;
	build(l, b, mid);
	build(r, mid+1, e);
	seg[n]=seg[l]+seg[r];
}
void update(int n, int b, int e, int i, int x){
	if(b>i or e<i)
		return;
	if(b==e and e==i){
		seg[n]=x;
		return;
	}
	int mid=(b+e)>>1, l=n<<1, r=l|1;
	update(l, b, mid, i, x);
	update(r, mid+1, e, i, x);
	seg[n]= seg[l]+seg[r];
}
int query(int n, int b, int e, int i, int j){
	if(b>j or e<i)
		return 0;
	if(b>=i and e<=j)
		return seg[n];
	int mid=(b+e)>>1, l=n<<1, r=l|1;
	int ll= query(l, b, mid, i, j);
	int rr= query(r, mid+1, e, i, j);
	return ll+rr;
}

