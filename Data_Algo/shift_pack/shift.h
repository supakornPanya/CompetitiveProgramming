void shift(int k) {
	
}






//round 1 ----------------------------------------------
// void shift(int k) {
// 	int n = mSize;
// 	if (k % n == 0) return;

// 	if (k > 0) {
// 		k = k % n;
// 	} else {
// 		k = k % n;
// 		k = n + k;
// 		k = k % n;
// 	}
// 	node* r = mHeader->next;
// 	for (int i = 0;i < k;i++) {
// 		r = r->next;
// 	}

// 	node* l = r->prev;
// 	node* s = mHeader->next;
// 	node* e = mHeader->prev;
// 	// std::cout << "mSize : " << mSize << ", k : " << k << '\n';
// 	// std::cout << s->data << ", " << l->data << ", " << r->data << ", " << e->data << '\n';
// 	r->prev = mHeader;
// 	mHeader->next = r;
// 	e->next = s;
// 	s->prev = e;
// 	mHeader->prev = l;
// 	l->next = mHeader;
// }