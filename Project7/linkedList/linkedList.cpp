/* Ahmed Salem
* 910017087
* ahmeds@mail.sfsu.edu
 * Class:Hui Yang 340-01
 * Date:December 10, 2014
 * IDE/Compiler: Netbeans
 * This program is the implementation file of the header file for the LinkedList ADT
 */

#include "linkedList_structNode.h"    // header file
#include <iostream>
#include <string>

using namespace std;

List::List(){
    size = 0;
    head = NULL;
}

List::List(const List& aList){
    size = aList.size;
    if (aList.head == NULL) {
        head = NULL; // original list is empty
        size = 0;
    } 
    else{ // copy first node
        head = new ListNode;
        head->item = aList.head->item;

        // copy rest of list
        ListNode *newPtr = head;// newPtr points to last node in new list
        // origPtr points to nodes in original list
        for (ListNode *origPtr = aList.head->next; origPtr != NULL; origPtr = origPtr->next){
            newPtr->next = new ListNode;
            newPtr = newPtr->next;
            newPtr->item = origPtr->item;
        } // end for

        newPtr->next = NULL;
    } // end if
} // end copy constructor

List List::operator=(const List& rhs) {
    //if size > 0 then we delete each node one by one
    if (size > 0){
        ListNode *curr = head;
        while (curr != NULL) {
            head = curr->next;
            delete curr;
            curr = head;
        }
    }
    //size is set to new size
    size = rhs.size;
    if (size <= 0)
        head = NULL;
    else {
        //Copy first item of list
        head = new ListNode;
        head->item = rhs.head->item;

        // copy rest of list
        ListNode *newPtr = head; // newPtr points to last node in new list
        // origPtr points to nodes in original list
        for (ListNode *origPtr = rhs.head->next; origPtr != NULL; origPtr = origPtr->next) {
            newPtr->next = new ListNode;
            newPtr = newPtr->next;
            newPtr->item = origPtr->item;
        }
        //Make sure lastnode->next = NULL
        newPtr->next = NULL;
    }
    //return copy
    return (*this);
}

List::~List() {
    //while (!isEmpty())
    //  remove(1);
    ListNode *curr = head;
    while (curr != NULL) {
        head = curr->next;
        delete curr;
        curr = head;
    }

} // end destructor

bool List::isEmpty() const {
    return size == 0;
} // end isEmpty

int List::getLength() const {
    return size;
} // end getLength

List::ListNode *List::find(int index) const {
    if ((index < 1) || (index > getLength()))
        return NULL;
    else{
        //count from the beginning of the list.
        ListNode *cur = head;
        for (int skip = 1; skip < index; ++skip)
            cur = cur->next;
        return cur;
    } // end if

} // end find

void List::retrieve(int index, ListItemType& dataItem) const throw (ListIndexOutOfRangeException) {
    if ((index < 1) || (index > getLength()))
        throw ListIndexOutOfRangeException("ListIndexOutOfRangeException: retrieve index out of range");
    else{ 
        // get pointer to node, then data in node
        ListNode *cur = find(index);
        dataItem = cur->item;
    } // end if
} // end retrieve

void List::insert(int index, const ListItemType& newItem)
throw (ListIndexOutOfRangeException, ListException) {
    int newLength = getLength() + 1;

    if ((index < 1) || (index > newLength))
        throw ListIndexOutOfRangeException(
            "ListIndexOutOfRangeException: insert index out of range");
    else { // try to create new node and place newItem in it
        try {
            ListNode *newPtr = new ListNode;
            size = newLength;
            newPtr->item = newItem;

            // attach new node to list
            if (index == 1) { // insert new node at beginning of list
                newPtr->next = head;
                head = newPtr;
            } else {
                ListNode *prev = find(index - 1);
                // insert new node after node
                // to which prev points
                newPtr->next = prev->next;
                prev->next = newPtr;
            } // end if
        }// end try
        catch (bad_alloc e) {
            throw ListException(
                    "ListException: memory allocation failed on insert");
        } // end catch
    } // end if
} // end insert

void List::remove(int index) throw (ListIndexOutOfRangeException) {
    ListNode *cur;

    if ((index < 1) || (index > getLength()))
        throw ListIndexOutOfRangeException(
            "ListIndexOutOfRangeException: remove index out of range");
    else {
        --size;
        if (index == 1) { // delete the first node from the list
            cur = head; // save pointer to node
            head = head->next;
        }
        else {
            ListNode *prev = find(index - 1);
            // delete the node after the node to which prev points
            cur = prev->next; // save pointer to node
            prev->next = cur->next;
        } // end if

        // return node to system
        cur->next = NULL;
        delete cur;
        cur = NULL;
    } // end if
} // end remove

void List::reverseList(List &aList){
    //Make a variable size to know the index
    int check = size;  List tempList;
    //for loop gets value in new order
    for (int i= 1; i <= check; i++){
        int index = 1;;
        ListNode *curr = head;
        ListNode *next = curr->next;
        //checks to see where the end is
        while (next != NULL) {
            curr = next;
            index++;
            next = curr->next;
        }
        //insert new order to original list
        tempList.insert(i, curr->item);
        aList.remove(index);
    } aList = tempList;
}

ostream & operator<<(ostream& outS, const List& aList) {
    //Create ListItemType to know what we're printing out
    ListItemType item;
    //Go through the whole list and outS << all value in it
    for(int i = 1; i <= aList.getLength(); i++){
        aList.retrieve(i, item);
        outS <<item << " ";
    }
    //Return whole list
    return outS;
}
