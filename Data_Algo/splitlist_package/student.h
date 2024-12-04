//round 2-------------------------------------
void splitList(list<T>& list1, list<T>& list2) {
    size_t n1 = (mSize + 1) / 2;
    size_t n2 = mSize - n1;
    node* pivot;
    node* lPivot; node* rPivot; node* start; node* last;
    // std::cout << "l : " << lPivot->data << " " << rPivot->data << '\n';

    if (n1 > 0) {
        pivot = mHeader->next;
        for (size_t i = 0;i < n1 - 1;i++) {
            pivot = pivot->next;
        }
        lPivot = pivot;
        rPivot = pivot->next;
        start = mHeader->next;
        last = mHeader->prev;
        // std::cout << "l : " << lPivot->data << " " << rPivot->data << '\n';

        node* end1 = list1.mHeader->prev;
        end1->next = start;
        start->prev = end1;
        lPivot->next = list1.mHeader;
        list1.mHeader->prev = lPivot;
    }
    if (n1 > 0 && n2 > 0) {
        node* end2 = list2.mHeader->prev;
        end2->next = rPivot;
        rPivot->prev = end2;
        last->next = list2.mHeader;
        list2.mHeader->prev = last;
    }

    mHeader->next = mHeader;
    mHeader->prev = mHeader;
    mSize = 0;
    list1.mSize += n1;
    list2.mSize += n2;
}





// void splitList(list<T>& list1, list<T>& list2) {
//     int n1 = (mSize % 2 == 0) ? mSize / 2 : (mSize / 2) + 1;
//     int n2 = mSize / 2;

//     if (n1 > 0) {
//         //find mid list this
//         node* mThis = mHeader->next;
//         for (int i = 0;i < n1 - 1;i++) {
//             mThis = mThis->next;
//         }
//         node* mThis2 = mThis->next;

//         (list1.mHeader->prev)->next = (mHeader->next); //last list1 <-> first this
//         (mHeader->next)->prev = (list1.mHeader->prev); //first this <-> last list1
//         mThis->next = list1.mHeader; //last this <-> mHeader list1
//         list1.mHeader->prev = mThis;//mHeader list1 <-> last this

//         if (n2 > 0) {
//             (list2.mHeader->prev)->next = mThis2; //last list2 <-> first2 this //mThis 
//             (mThis2)->prev = (list2.mHeader->prev); //last list2 <-> first2 this //mThis
//             (mHeader->prev)->next = list2.mHeader; //mid this <-> mHeader list2
//             list2.mHeader->prev = (mHeader->prev);//mid this <-> mHeader list2
//         }
//     }


//     //set up *this
//     mHeader->prev = mHeader;
//     mHeader->next = mHeader;
//     mSize = 0;

//     list1.mSize += n1;
//     list2.mSize += n2;
// }