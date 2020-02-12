// This program demonstrates a simple append
// operation on a linked list.
#include <iostream>
#include "NumberList.h"
using namespace std;

int main()
{
   // Create NumberList objects.
   NumberList fullList;
   NumberList part1List;
   NumberList part2List;

   // Append some values to the original list.
   fullList.insertNode(1);
   fullList.insertNode(2);
   fullList.insertNode(3);
   fullList.insertNode(4);
   fullList.insertNode(5);

   //print the full list
   cout << "The original list is: " << endl;
   fullList.printList();
   fullList.getLength();

   //call the split function at point 2
   fullList.splitList(fullList, 2, part1List, part2List);

   return 0;
}
