#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
void ULListStr::push_back(const std::string& val){
  if(tail_==NULL){ //if absolutely nothing
    Item* myItem = new Item; //allocates a new node
    head_=myItem;
    tail_=myItem; //assigns pointers
    myItem->val[0]=val;
    myItem->last++;
    size_++;
  }
  else if(tail_->last == 10){ //if we need to allocate a new node
    Item* nextItem = new Item;
    tail_->next=nextItem;
    nextItem->prev=tail_;
    nextItem->next=NULL;
    tail_=nextItem; //adjusts pointers 
    nextItem->val[0]=val;
    nextItem->last++;
    size_++;
  }
  else{ //normal case where we have space
    tail_->val[tail_->last]=val;
    tail_->last++;
    size_++;
  }
}

void ULListStr::push_front(const std::string& val){
  if(head_==NULL){ //if absolutely nothing
    Item* myItem = new Item;
    head_=myItem;
    tail_=myItem;
    myItem->val[0]=val;
    myItem->last++;
    size_++;
  }
  else if(head_->first == 0){ //if we need to allocate a new node
    Item* prevItem = new Item;
    head_->prev=prevItem;
    prevItem->prev=NULL;
    prevItem->next=head_;
    head_=prevItem;
    prevItem->val[9]=val;
    prevItem->last=10;
    prevItem->first=9;
    size_++;
  }
  else{ //normal case where we have space
    head_->val[head_->first-1]=val;
    head_->first--;
    size_++;
  }
}

void ULListStr::pop_back(){
  if(size_==0){ //nothing in the list
    return;
  }
  else if(head_==tail_){ //there's only one node in the list
    if(size_==1){ //there's only one last element in the node
      delete tail_;
      size_--;
      head_=NULL;
      tail_=NULL;
    }
    else{ //there're many elements in the node
      tail_->last--;
      size_--;
    }
  }
  else{ //there're many nodes
    if(tail_->last==1){ //there's only one element in the node
      size_--;
      tail_=tail_->prev;
      delete tail_->next;
      tail_->next=NULL;
    }
    else{ //there're many elements in the node
      tail_->last--;
      size_--;
    }
  }
}

void ULListStr::pop_front(){ //similar as pop_back
  if(size_==0){
    return;
  }
  else if(head_==tail_){
    if(size_==1){
      delete head_;
      size_--;
      head_=NULL;
      tail_=NULL;
    }
    else{
      head_->first++;
      size_--;
    }
  }
  else{
    if(head_->first==9){
      size_--;
      head_=head_->next;
      delete head_->prev;
      head_->prev=NULL;
    }
    else{
      head_->first++;
      size_--;
    }
  }
}

std::string const & ULListStr::back() const{
  return tail_->val[tail_->last-1];
}

std::string const & ULListStr::front() const{
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const{
  if(loc>=size_){
    return NULL;
  }
  else{
    Item* tempP = head_; //node tracer
    std::string* tempS = head_->val + head_->first; //element tracer
    size_t idx = head_->first;
    size_t count = 0;
    while(count<loc){
      if(idx==9){ //if we need to step over to the next node
        tempP=tempP->next; //node adapter
        idx=0;
        tempS=tempP->val; //element adapter
        count++;
      }
      else{ //if we're in the same node
        idx++;
        tempS++;
        count++;
      }
    }
    return tempS;
  }
}


void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
