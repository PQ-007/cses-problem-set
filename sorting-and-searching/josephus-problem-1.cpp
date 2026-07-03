#include <iostream>
using namespace std;

struct Node{
  int value;
  Node* next;
};

int main(){
  int n;
  cin >> n;
  Node* head = new Node{1, nullptr};
  Node* tail = head;
  for(int i = 2; i <= n; i++){
    tail->next = new Node{i, nullptr};
    tail = tail->next;  
  }
  tail->next = head; 
  Node* current = head;
  while(current->next != current){
    
    Node* toDelete = current->next;
    cout << toDelete->value << " ";
    current->next = toDelete->next;
    delete toDelete;
    current = current->next;
  }
  cout << current->value;
  delete current;
  return 0;

}

  

