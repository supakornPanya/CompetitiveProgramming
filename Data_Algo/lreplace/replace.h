node* mCopy(list<T> other) {
  using std::swap;
  node* head = NULL; size_t sizee = 0;
  swap(head, other.mHeader);
  swap(sizee, other.mSize);
  return head;
}

void replace(const T& x, list<T>& y) {
  node* now = mHeader->next;
  while (now != mHeader) {
    // std::cout << "node : " << now->data << '\n';

    if (now->data == x) {
      node* temp = mCopy(y); //copy y
      mSize += y.size() - 1;
      //restucture pointer
      if(y.size() != 0) {
        auto yHead = temp->next;
        auto yLast = temp->prev;
        auto xPre = now->prev;
        auto xNext = now->next;
        xPre->next = yHead;
        xNext->prev = yLast;
        yHead->prev = xPre;
        yLast->next = xNext;
      } else {
        now->prev->next = now->next;
        now->next->prev = now->prev; 
      }
    }

    now = now->next;
  }
}