#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node* prev;
    Node(int _data):data(_data) , next(nullptr) , prev(nullptr){}
};

class LinkedList
{
public:
    LinkedList():head(nullptr) , tail(nullptr){}
    void push_front(int data)
    {
        if(head == nullptr and tail == nullptr) head = new Node(data) , tail = head;
        else{
            head->prev = new Node(data);
            head->prev->next = head;
            head = head->prev;
        }
    }
  
    void push_back(int data)
    {
        if(head == nullptr and tail == nullptr) head = new Node(data) , tail = head;
        else{
            tail->next = new Node(data);
            tail->next->prev = tail;
            tail = tail->next;
        }
    }
  
    void pop_front()
    {
        if(head != nullptr){
            if(head->next != nullptr){
                head = head->next;
                head->prev = nullptr;
            }
            else head = nullptr;
        }
    }
  
    void pop_back()
    {
        if(tail != nullptr){
            if(tail->prev != nullptr){
                tail = tail->prev;
                tail->next = nullptr;
            }
            else tail = nullptr;
        }
    }
  
    void printList()
    {
        Node *cur = head;
        while(cur != nullptr){
            cout << cur->data << ' ';
            cur = cur->next;
        }
    }
private:
// Hint: maintain head and tail node pointing to begin and end of the list 
    Node *head , *tail;
};
 
int main()
{
/* Hint: Read input from STDIN and perform the corresponding operation.*/
    int t; cin >> t;
    LinkedList list;
    while(t--){
        int opt ; cin >> opt;
        if(opt == 0){//push back
            int x; cin >> x;
            list.push_back(x);
        }
        if(opt == 1){//push front
            int x; cin >> x;
            list.push_front(x);
        }
        if(opt == 2){//pop back
            list.pop_back();
        }
        if(opt == 3){//pop front
            list.pop_front();
        }
    }
  	list.printList();
    return 0;
}