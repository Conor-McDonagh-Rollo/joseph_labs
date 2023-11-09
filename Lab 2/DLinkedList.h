/* DLinkedList.h --- 
 * 
 * Filename: DLinkedList.h
 * Description: 
 * Author: Joseph
 * Maintainer: 
 * Created: Wed Oct  4 18:44:47 2023 (+0100)
 * Last-Updated: Wed Oct  4 20:39:12 2023 (+0100)
 *           By: Joseph
 *     Update #: 7
 * 
 * Commentary: 
 * 
 * 
 * 
 * 
 * 
 */

/* This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or (at
 * your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with GNU Emacs.  If not, see <http://www.gnu.org/licenses/>.
 */

/* Code: */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @struct node_t
 * Struct representing a Node in a doubly linked list.
 */
struct node_t {
    struct node_t* previous; ///< Pointer to the previous node in the list.
    struct node_t* next;     ///< Pointer to the next node in the list.
    int data;                ///< Data stored in the node.
};

/**
 * @struct DLList_t
 * Struct representing a doubly linked list data type.
 */
struct DLList_t {
    struct node_t* first;    ///< Pointer to the first node in the list.
    struct node_t* current;  ///< Pointer to the current node in the list.
    int size;                ///< Number of elements in the list.
};

#define DLList struct DLList_t

/**
 * @brief Creates a new doubly linked list.
 *
 * @return Pointer to the new doubly linked list.
 */
DLList* createDLList();

/**
 * @brief Returns the number of items in the list.
 *
 * @param theList A pointer to the DLList struct.
 * @return The number of elements in the DLList.
 */
int size(DLList* theList);

/**
 * @brief Adds an item to the front of the list.
 *
 * @param theList A pointer to the DLList struct.
 * @param newData The data item to be added (an integer).
 * @return The number of elements in the DLList after the addition.
 */
int push(DLList* theList, int newData);

/**
 * @brief Removes an item from the front of the list.
 *
 * @param theList A pointer to the DLList struct.
 * @return The data item removed from the front of the list (an integer).
 */
int pop(DLList* theList);

/**
 * @brief Returns the data at the current position in the list.
 *
 * @param theList A pointer to the DLList struct.
 * @return The data at the current position (an integer).
 */
int getCurrent(DLList* theList);

/**
 * @brief Moves the current pointer to the start of the list.
 *
 * @param theList A pointer to the DLList struct.
 */
void first(DLList* theList);

/**
 * @brief Moves the current pointer to the next element in the list.
 *
 * @param theList A pointer to the DLList struct.
 */
void next(DLList* theList);

/**
 * @brief Checks if the current pointer is at the end of the list.
 *
 * @param theList A pointer to the DLList struct.
 * @return True if the current pointer is at the end, otherwise false.
 */
bool atEnd(DLList* theList);

/**
 * @brief Deletes the current element from the list.
 *
 * @param theList A pointer to the DLList struct.
 * @return The number of elements remaining in the list after deletion.
 */
int deleteCurrent(DLList* theList);

/**
 * @brief Inserts data after the current element in the list.
 *
 * @param theList A pointer to the DLList struct.
 * @param newData The data to be inserted (an integer).
 */
void insertAfter(DLList* theList, int newData);

/**
 * @brief Inserts data before the current element in the list.
 *
 * @param theList A pointer to the DLList struct.
 * @param newData The data to be inserted (an integer).
 */
void insertBefore(DLList* theList, int newData);

/**
 * @brief Prints the entire list.
 *
 * @param theList A pointer to the DLList struct.
 */
void printList(DLList* theList);

/**
 * @brief Frees the memory used by the doubly linked list.
 *
 * @param theList A pointer to the DLList struct.
 */
void freeDLList(DLList* theList);




// List constructor.
DLList* createDLList() {
    DLList* newList = (DLList*)malloc(sizeof(DLList));
    if (newList) {
        newList->first = NULL;
        newList->current = NULL;
        newList->size = 0;
    }
    return newList;
}

// Returns the number of items in the list
int size(DLList* theList) {
    return theList->size;
}

// Adds an item to the front of the list
int push(DLList* theList, int newData) {
    struct node_t* newNode = (struct node_t*)malloc(sizeof(struct node_t));
    if (!newNode) {
        return -1; // Memory allocation error
    }
    newNode->data = newData;
    newNode->previous = NULL;
    newNode->next = theList->first;

    if (theList->first != NULL) {
        theList->first->previous = newNode;
    }

    theList->first = newNode;

    if (theList->size == 0) {
        theList->current = theList->first;
    }

    theList->size++;

    return theList->size;
}

// Removes an item from the front of the list
int pop(DLList* theList) {
    if (theList == NULL || theList->first == NULL) {
        return -1; // List is empty
    }

    struct node_t* removedNode = theList->first;
    int data = removedNode->data;
    
    theList->first = removedNode->next;
    if (theList->first) {
        theList->first->previous = NULL;
    }

    if (theList->current == removedNode) {
        theList->current = theList->first;
    }
    
    free(removedNode);
    theList->size--;

    return data;
}

// Returns the data at the current position
int getCurrent(DLList* theList) {
    if (theList->current) {
        return theList->current->data;
    }
    return -1; // Current is not set or list is empty
}

// Moves current to the start of the list
void first(DLList* theList) {
    theList->current = theList->first;
}

// Moves current to the next element of the list
void next(DLList* theList) {
    if (theList->current) {
        theList->current = theList->current->next;
    }
}

// Returns true if current is at the end, otherwise false
bool atEnd(DLList* theList) {
    return !theList->current || !theList->current->next;
}

// Deletes the current element
int deleteCurrent(DLList* theList) {
    if (theList == NULL || theList->current == NULL) {
        return -1; // Current is not set or list is empty
    }

    struct node_t* currentNode = theList->current;
    int data = currentNode->data;

    if (currentNode->previous) {
        currentNode->previous->next = currentNode->next;
    } else {
        theList->first = currentNode->next; // Current node is the first node
    }

    if (currentNode->next) {
        currentNode->next->previous = currentNode->previous;
    }

    struct node_t* nextNode = currentNode->next;
    free(currentNode);

    // Update current to next node, or to first if no next node exists
    theList->current = nextNode ? nextNode : theList->first;
    theList->size--;

    return data;
}

// Inserts data after the current element
void insertAfter(DLList* theList, int newData) {
    if (!theList->current) {
        return; // Current is not set
    }

    struct node_t* newNode = (struct node_t*)malloc(sizeof(struct node_t));
    if (!newNode) {
        return; // Memory allocation error
    }

    newNode->data = newData;
    newNode->previous = theList->current;
    newNode->next = theList->current->next;

    if (theList->current->next) {
        theList->current->next->previous = newNode;
    }

    theList->current->next = newNode;
    theList->size++;
}

// Inserts data before the current element
void insertBefore(DLList* theList, int newData) {
    if (!theList->current) {
        return; // Current is not set
    }

    struct node_t* newNode = (struct node_t*)malloc(sizeof(struct node_t));
    if (!newNode) {
        return; // Memory allocation error
    }

    newNode->data = newData;
    newNode->previous = theList->current->previous;
    newNode->next = theList->current;

    if (theList->current->previous) {
        theList->current->previous->next = newNode;
    } else {
        theList->first = newNode;
    }

    theList->current->previous = newNode;
    theList->size++;
}

// Prints the entire list
void printList(DLList* theList) {
    struct node_t* currentNode = theList->first;

    while (currentNode) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }

    printf("\n");
}

// Deletes list
void freeDLList(DLList* theList) {
    if (theList == NULL) {
        return; // NULL list passed
    }

    struct node_t* currentNode = theList->first;
    struct node_t* nextNode;

    while (currentNode) {
        nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;
    }

    free(theList);
}
  
/* DLinkedList.h ends here */
