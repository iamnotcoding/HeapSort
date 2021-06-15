#include <stdio.h>

#include "HeapSort.h"

static inline void Swap(HData *x, HData *y)
{
   HData temp;

   temp = *x;
   *x = *y;
   *y = temp;
}

static inline size_t GetLeftChildIndex(size_t i)
{
   if (i == 0)
      return 1;
   else
      return i * 2;
}

static inline size_t GetRightChildIndex(size_t i)
{
   if (i == 0)
      return 2;
   else
      return i * 2 + 1;
}


void Heapify(HData *list, size_t i, size_t n)
{
   /* this function does downheap
   i = root of the sub tree or entire tree
   n = array(heap) size
   */

   while (i < n)
   {
      if (GetRightChildIndex(i) < n && list[i] <= list[GetRightChildIndex(i)] && list[GetRightChildIndex(i)] >= list[GetLeftChildIndex(i)])
      { /* if i's right child node index is not out-of-range 
         and if i's right child's value is less then or equal to i's value
          and right child node's value is grater than equal left child node's*/

         Swap(&list[i], &list[GetRightChildIndex(i)]); //swap i and i's right child
         
         i = GetRightChildIndex(i);                    //set i to i's right child
      }
      else if (GetLeftChildIndex(i) < n && list[i] <= list[GetLeftChildIndex(i)] && list[GetLeftChildIndex(i)] >= list[GetRightChildIndex(i)])
      { /* if i's left child node index is not out-of-range 
         and if i's left child's value is less then or equal to i's value and 
         left child node's value is less then or equal to right child node's*/

         Swap(&list[i], &list[GetLeftChildIndex(i)]); //swap i and i's left child
        
         i = GetLeftChildIndex(i);                    // set i to i's left child
      }
      else      // if i is bottem node of the treee
         break; // exit
   }
}

void HeapSort(HData *list, size_t n)
{
   if (n == 0)
      return; // there's nothing needs to be done
   else
   {
      for (size_t i = n / 2; i > 0; --i) // (n / 2) - 1 is parent of bottem node (not a leef nodes' parent)
         Heapify(list, i - 1, n); // do heapify

      for (size_t i = n; i > 1; --i)
      {
         Swap(&list[0], &list[i - 1]); //swap root node(bigest value) and last node

         Heapify(list, 0, i - 1); // contract heap size to i - 1 to not get sorted node effected
      }
   }
}
