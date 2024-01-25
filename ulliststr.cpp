#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

//added
using namespace std;
#include <iostream>

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
/**
   * Adds a new value to the back of the list
   *   - MUST RUN in O(1)
   */
void ULListStr::push_back(const std::string& val){
  Item* curr = tail_;
  if (curr == nullptr){
    Item* temp = new Item();
    temp->next = nullptr;
    temp->prev = nullptr;
    temp->first = 0;
    temp->last = 1;
    temp->val[0] = val;
    head_ = temp;
    tail_ = temp;
    size_++;
  } else {
    if (curr->last < ARRSIZE){
      curr->last = curr->last + 1;
      curr->val[curr->last - 1] = val;
      size_++;
    } else {
      Item* temp = new Item();
      temp->first = 0;
      temp->last = 1;
      temp->next = nullptr;
      temp->prev = curr;
      curr->next = temp;
      tail_ = temp;
      temp->val[0] = val;
      size_++;
    }
  }
}
  
  /**
   * Adds a new value to the front of the list.
   * If there is room before the 'first' value in
   * the head node add it there, otherwise, 
   * allocate a new head node.
   *   - MUST RUN in O(1)
   */
void ULListStr::push_front(const std::string& val){
  Item* curr = head_;

  if (curr == nullptr){
    Item* temp = new Item();
    temp->next = nullptr;
    temp->prev = nullptr;
    temp->first = ARRSIZE - 1;
    temp->last = ARRSIZE;
    temp->val[temp->last-1] = val;
    head_ = temp;
    tail_ = temp;
    size_++;
  } else {
    if (curr->first > 0){
      curr->first = curr->first - 1;
      curr->val[curr->first] = val;
      size_++;
    } else {
      Item* temp = new Item();
      temp->first = ARRSIZE - 1;
      temp->last = ARRSIZE;
      temp->next = curr;
      temp->prev = nullptr;
      curr->prev = temp;
      head_ = temp;
      temp->val[ARRSIZE-1] = val;
      size_++;
    }
  }

}

 /**
   * Removes a value from the back of the list
   *   - MUST RUN in O(1)
   */
void ULListStr::pop_back(){
  if (tail_ != nullptr){
    //if there is only one element left
    if (tail_->last - tail_->first == 1){
      if (head_ == tail_){
        head_ = nullptr;
      }
      
      Item* temp = tail_;
      tail_ = temp->prev;
      delete temp;
      if (tail_ != nullptr){
        tail_->next = nullptr;
      }
      
      size_--;
    } else {
      tail_->last = tail_->last - 1;
      size_--;
    }
  }
}

  /**
   * Removes a value from the front of the list
   *   - MUST RUN in O(1)
   */
void ULListStr::pop_front(){
  if (head_ != nullptr){
    if (head_->last - head_->first == 1){
      //it is the only element in the linked list
      if (head_ == tail_){
        tail_ = nullptr;
      }

      Item* temp = head_;
      head_ = temp->next;
      if (head_!=nullptr){
        head_->prev = nullptr;
      }
      delete temp;
      
      size_--;
    } else {
      head_->first = head_->first + 1;
      size_--;
    }
  }
}
  
  /**
   * Returns a const reference to the back element
   *   - MUST RUN in O(1)
   */
std::string const & ULListStr::back() const{
  return tail_->val[tail_->last - 1];
}

  /**
   * Returns a const reference to the front element
   *   - MUST RUN in O(1)
   */
std::string const & ULListStr::front() const{
  return head_->val[head_->first];
}
  
/** 
   * Returns a pointer to the item at index, loc,
   *  if loc is valid and NULL otherwise
   *   - MUST RUN in O(n) 
   */
std::string* ULListStr::getValAtLoc(size_t loc) const{

  size_t begin = head_->first;
  size_t realIndex = loc + begin;
  size_t numNodes = realIndex / ARRSIZE;


  Item* curr = head_;
  for (size_t i = 0; i < numNodes; i++){
    if (curr->next!=nullptr){
      curr = curr->next;
    }
  }

  size_t ind = realIndex - (numNodes * ARRSIZE);

  return &(curr->val[ind]);
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
