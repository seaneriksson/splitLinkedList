// Specification file for the NumberList class
#ifndef NUMBERLIST_H
#define NUMBERLIST_H

class NumberList
{
private:
   // Declare a structure for the list
   struct ListNode
   {
      int value;           // The integer value in this node
      ListNode *next;  // To point to the next node
   };

   ListNode *head;            // List head pointer


public:
   // Constructor
   NumberList()
      { head = nullptr;}

   // Destructor
   ~NumberList();

   // Linked list operations
   void insertNode(int);
   int getLength();
   void deleteNode(int);
   void printList();
   void splitList(NumberList fullList, int num, NumberList & part1List, NumberList & part2List);

   //length of list
   int length = 0;

};
#endif
