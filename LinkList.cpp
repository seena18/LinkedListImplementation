#include <iostream>
#include <string>
using namespace std;

template <typename Elem> class Link { 
  public: 
  Elem element;
  Link *next;  
  Link(const Elem& elemval, Link* nextval = NULL) { 
    element = elemval; 
    next = nextval; 
  } 
  Link(Link* nextval = NULL) 
  { 
    next = nextval; 
  } 
};

template <typename Elem>
class LList{
  private:
    Link<Elem>* head;
    Link<Elem>* tail;
    Link<Elem>* fence; 
    int left,right;
    int size;
  public:
    LList(int s){
      size=s;
      fence = tail = head = new Link<Elem>; 
      left = right = 0; 
    }
    bool append(const Elem& it) { 
      tail = tail->next = new Link<Elem>(it, NULL); 
      right++; 
      return true; 
    }
    void next() { 
      if (fence != tail) { 
        fence = fence->next; 
        right--; left++; 
        } 
      }
    const Elem& getValue() const { 
       return fence->next->element; 
    }
    void movetoStart() { 
      fence = head; 
      right += left; 
      left = 0; 
    }
    bool isPal(){
      movetoStart();
      int pal[size];
      for(int i=0;i<size;i++){
        pal[i]=getValue();
        next();
      }
      for(int i=0;i<size;i++){
        if(pal[i]!=pal[size-1-i]){
          return false;
        }
      }
      return true;
    }
    

};

int main() {
  while(true){
    string userI;
    cout<<"Enter a series of integers: ";
    cin>>userI;
    LList<int> l(userI.size());

    for(int i = 0; i<userI.size();i++){
      l.append(userI[i]);
    }
 
    if(l.isPal()){
      cout<<endl<<"Series is a palindrome"<<endl<<endl;
    }
    else{
      cout<<endl<<"Series is NOT a palindrome"<<endl<<endl;
    }
  }
}
