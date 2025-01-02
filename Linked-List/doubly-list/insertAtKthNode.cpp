// https://www.geeksforgeeks.org/problems/insert-a-node-in-doubly-linked-list/1

#include <bits/stdc++.h>
using namespace std;

struct Node{
  int data;
  struct Node *next;
  struct Node *prev;

    Node(int x) {
        data = x;
        next = prev = NULL;
    }
}; 

Node *addNode(Node *head, int k, int data) {
    Node *newNode = new Node(data);
    
    if (!head) return newNode;

    Node *temp = head;
    int count = 0;

    while (temp && count < k) {
        temp = temp->next;
        count++;
    }

    // If `k` is greater than the length of the list, do nothing and return head
    if (!temp) return head;

    // Insert the new node after the kth node
    newNode->prev = temp;
    newNode->next = temp->next;

    // Update the next node's prev pointer, if it exists
    if (temp->next) {
        temp->next->prev = newNode;
    }

    // Update the kth node's next pointer
    temp->next = newNode;

    return head;
}