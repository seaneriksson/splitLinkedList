// Implementation file for the NumberList class
#include <iostream>  // For cout
#include "NumberList.h"
using namespace std;

//append a new node
void NumberList::insertNode(int num)
{
   ListNode *newNode;					// A new node
   ListNode *nodePtr;					// To traverse the list
   ListNode *previousNode = nullptr;	// The previous node

   // Allocate a new node and store num there.
   newNode = new ListNode;
   newNode->value = num;

   // If there are no nodes in the list
   // make newNode the first node
   if (!head)
   {
      head = newNode;
      newNode->next = nullptr;
   }
   else  // Otherwise, insert newNode
   {
      // Position nodePtr at the head of list.
      nodePtr = head;

      // Initialize previousNode to nullptr.
      previousNode = nullptr;

      // Skip all nodes whose value is less than num.
      while (nodePtr != nullptr && nodePtr->value < num)
      {
         previousNode = nodePtr;
         nodePtr = nodePtr->next;
      }

      // If the new node is to be the 1st in the list,
      // insert it before all other nodes.
      if (previousNode == nullptr)
      {
         head = newNode;
         newNode->next = nodePtr;
      }
      else  // Otherwise insert after the previous node.
      {
         previousNode->next = newNode;
         newNode->next = nodePtr;
      }
   }
}


//display the list
void NumberList::printList()
{
   ListNode *nodePtr;  // To move through the list

   // Position nodePtr at the head of the list.
   nodePtr = head;

   // While nodePtr points to a node, traverse
   // the list.
   while (nodePtr)
   {
      // Display the value in this node.
      cout << nodePtr->value << endl;

      // Move to the next node.
      nodePtr = nodePtr->next;
   }
   cout << "" << endl;
}

int NumberList::getLength()
{
    ListNode *nodePtr;  // To move through the list

   // Position nodePtr at the head of the list.
   nodePtr = head;

   // While nodePtr points to a node, traverse
   // the list.
   while (nodePtr)
   {
      // Move to the next node.
      nodePtr = nodePtr->next;

      //update the length of the list
      length++;
   }

}
//delete node
void NumberList::deleteNode(int num)
{
   ListNode *nodePtr;       // To traverse the list
   ListNode *previousNode;  // To point to the previous node

   // If the list is empty, do nothing.
   if (!head)
      return;

   // Determine if the first node is the one.
   if (head->value == num)
   {
      nodePtr = head->next;
      delete head;
      head = nodePtr;
   }
   else
   {
      // Initialize nodePtr to head of list
      nodePtr = head;

      // Skip all nodes whose value member is
      // not equal to num.
      while (nodePtr != nullptr && nodePtr->value != num)
      {
         previousNode = nodePtr;
         nodePtr = nodePtr->next;
      }

      // If nodePtr is not at the end of the list,
      // link the previous node to the node after
      // nodePtr, then delete nodePtr.
      if (nodePtr)
      {
         previousNode->next = nodePtr->next;
         delete nodePtr;
      }
   }
}


void NumberList::splitList(NumberList fullList, int num, NumberList & part1List, NumberList & part2List)
{
   //to keep track in the while loop
   int counter = 0;

   ListNode *nodePtr;  // To move through the list

   // Position nodePtr at the head of the list.
   nodePtr = head;

   // While loop for first part of the split
   while (nodePtr)
   {
     if (counter < num)
      {
        //insert node into first part of the split list
        part1List.insertNode(nodePtr->value);

        // Move to the next node.
        nodePtr = nodePtr->next;

        //increase counter
        counter++;
       }
     else
     {
      break;
     }
   }
   cout << "" << endl;


   cout << "Sub list 1 is: " << endl;
   part1List.printList();
   cout << "" << endl;

   int lengthOfFullList = fullList.getLength();

   //while loop for second part of the split
   while (nodePtr)
   {
     if (counter < lengthOfFullList)
      {
        //insert node into first part of the split list
        part2List.insertNode(nodePtr->value);

        // Move to the next node.
        nodePtr = nodePtr->next;

        //increase counter
        counter++;
       }
     else
     {
      break;
     }
   }

   cout << "Sub list 2 is: " << endl;
   part2List.printList();
}



//destructor
NumberList::~NumberList()
{
   ListNode *nodePtr;   // To traverse the list
   ListNode *nextNode;  // To point to the next node

   // Position nodePtr at the head of the list.
   nodePtr = head;

   // While nodePtr is not at the end of the list...
   while (nodePtr != nullptr)
   {
      // Save a pointer to the next node.
      nextNode = nodePtr->next;

      // Delete the current node.
      delete nodePtr;

      // Position nodePtr at the next node.
      nodePtr = nextNode;
   }

}
