#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

namespace CP {

template <typename T>
class list
{
  protected:
    class node {
      friend class list;
      public:
        T data;
        node *prev;
        node *next;

        node() :
          data( T() ), prev( this ), next( this ) { }

        node(const T& data,node* prev, node* next) :
          data ( T(data) ), prev( prev ), next( next ) { }
    };

    class list_iterator {
      friend class list;
      protected:
        node* ptr;
      public:

        list_iterator() : ptr( NULL ) { }

        list_iterator(node *a) : ptr(a) { }

        list_iterator& operator++() {
          ptr = ptr->next;
          return (*this);
        }

        list_iterator& operator--() {
          ptr = ptr->prev;
          return (*this);
        }

        list_iterator operator++(int) {
          list_iterator tmp(*this);
          operator++();
          return tmp;

        }
        list_iterator operator--(int) {
          list_iterator tmp(*this);
          operator--();
          return tmp;
        }

        T& operator*() { return ptr->data; }
        T* operator->() { return &(ptr->data); }
        bool operator==(const list_iterator& other) { return other.ptr == ptr; }
        bool operator!=(const list_iterator& other) { return other.ptr != ptr; }
    };

  public:
    typedef list_iterator iterator;

  protected:
    node *mHeader; // pointer to a header node
    size_t mSize;


  public:
    //-------------- constructor & copy operator ----------

    // copy constructor
    list(list<T>& a) :
      mHeader( new node() ), mSize( 0 ) {
      for (iterator it = a.begin();it != a.end();it++) {
        push_back(*it);
      }
    }

    // default constructor
    list() :
      mHeader( new node() ), mSize( 0 ) { }

    // copy assignment operator using copy-and-swap idiom
    list<T>& operator=(list<T> other) {
      // other is copy-constructed which will be destruct at the end of this scope
      // we swap the content of this class to the other class and let it be descructed
      using std::swap;
      swap(this->mHeader, other.mHeader);
      swap(this->mSize, other.mSize);
      return *this;
    }

    ~list() {
      clear();
      delete mHeader;
    }

    //------------- capacity function -------------------
    bool empty() const {
      return mSize == 0;
    }

    size_t size() const {
      return mSize;
    }


    //----------------- iterator ---------------
    iterator begin() {
      return iterator(mHeader->next);
    }

    iterator end() {
      return iterator(mHeader);
    }
    //----------------- access -----------------
    T& front() { return mHeader->next->data; }

    T& back() { return mHeader->prev->data; }

    //----------------- modifier -------------
    void push_back(const T& element) {
      insert(end(),element);
    }

    void push_front(const T& element) {
      insert(begin(),element);
    }

    void pop_back() {
      erase(iterator(mHeader->prev));
    }

    void pop_front() {
      erase(begin());
    }

    iterator insert(iterator it,const T& element) {
      node *n = new node(element,it.ptr->prev, it.ptr);
      it.ptr->prev->next = n;
      it.ptr->prev = n;
      mSize++;
      return iterator(n);
    }

    iterator erase(iterator it) {
      iterator tmp(it.ptr->next);
      it.ptr->prev->next = it.ptr->next;
      it.ptr->next->prev = it.ptr->prev;
      delete it.ptr;
      mSize--;
      return tmp;
    }

    void clear() {
      while (mSize > 0) erase(begin());
    }

    void print() {
      std::cout << " Header address = " << (mHeader) << std::endl;
      int i;
      iterator before;
      for (iterator it = begin();it!=end();before = it, it++,i++) {
        std::cout << "Node " << i << ": " << *it;
        std::cout << " (prev = " << it.ptr->prev << ", I'm at " << it.ptr << ", next = " << it.ptr->next << ")" <<  std:: endl;
      }
    }

    void check() {
      node* p;
      int n;
      p = mHeader;
      n = mSize+1;
      while (n--) p = p->next;
      if (p != mHeader) {
        std::cout << "next POINTER ERROR" << std::endl;
      }
      p = mHeader;
      n = mSize+1;
      while (n--) p = p->prev;
      if (p != mHeader) {
        std::cout << "prev POINTER ERROR" << std::endl;
      }
    }


    void reorder(int pos, std::vector<int> selected) {
      auto it = begin();
      for(int i = 0;i < pos;i++) {
        it++;
      }
      int idx = 0, i = 0;
      auto now = begin();
      while(now != end()) {
        if(selected[idx] == i) {
          insert(it, *now);
          erase(now);
          idx++;
        }
        now++; i++;
      }
    }

    //round 1-------------------------------------------------------
    // void reorder(int pos,std::vector<int> selected) {
    //   //find index insert
    //   node* position = mHeader->next;//use this
    //   for(int i = 0;i < pos;i++) {
    //     position = position->next;
    //   }

    //   //find set of insert
    //   node* it2 = mHeader->next;
    //   int idx = 0;
    //   std::vector<T> v; //set of position at pos
    //   int n = mSize;
    //   // std::cout << "mSize : " << mSize << '\n';
    //   for(int i = 0;i < n;i++) {
    //     // std::cout << "i : " << i << ", it2 : " << it2->data << ", " << selected[idx] << '\n';
    //     if(i == selected[idx]) {
    //       v.push_back(it2->data);
    //       erase(it2);
    //       idx++;
    //     }
    //     it2 = it2->next;
    //   }

    //   // std::cout << "size : " << mSize << '\n';
    //   // std::cout << "vSize " << v.size() << " : ";
    //   // for(int i = 0;i < v.size();i++) {
    //   //   std::cout << v[i] << " ";
    //   // } std::cout << '\n';

    //   for(int i = 0;i < v.size();i++) {
    //     insert(position, v[i]);
    //   }
    // }

};

}

//----------------------------------------------
int main() {
  int n;
  std::cin >> n;

  CP::list<std::string> l;
  int pos;
  std::vector<int> selected;

  while(n--) {
    std::string st;
    std::cin >> st;
    l.push_back(st);
  }

  std::cin >> n;
  while(n--) {
    int a;
    std::cin >> a;
    selected.push_back(a);
  }
  std::sort(selected.begin(),selected.end());

  //call student function
  std::cin >> pos;
  l.reorder(pos,selected);

  //check result
  l.check();
  auto it = l.begin();
  while (it != l.end()) {
    std::cout << *it << " ";
    it++;
  }
  std::cout << std::endl;
  it = l.end(); it--;
  while (it != l.end()) {
    std::cout << *it << " ";
    it--;
  }
  std::cout << std::endl;

}


