#include <iostream>
using namespace std;

struct Node{
  int value;
  Node* next;
  
  Node(int val, Node* nxt) : value(val), next(nxt) {}
};


int main(){
  int k, n;
  cin >> n >> k;
  Node *head = new Node(1, nullptr);
  Node *tail = head;
  for (int i = 2; i <= n; i++){
    tail->next = new Node(i, nullptr);
    tail = tail->next;
  }
  tail->next = head;
  Node *current = head;
  while(current != current->next){
    for(int i = 0; i < k-1; i++){
      current = current->next;
    }
    Node *deleteNode = current->next;
    cout << deleteNode->value << " ";
    current->next = deleteNode->next;
    
    delete deleteNode;
    current = current->next;
    
  }
  cout << current->value;
  delete current;
  return 0;
}