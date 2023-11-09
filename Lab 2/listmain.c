/* listmain.c --- 
 * 
 * Filename: listmain.c
 * Description: 
 * Author: Joseph
 * Maintainer: 
 * Created: Wed Oct  4 20:32:33 2023 (+0100)
 * Last-Updated: Wed Oct  4 20:40:43 2023 (+0100)
 *           By: Joseph
 *     Update #: 4
 * 
 */

/* Commentary: 
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

#include <stdio.h>
#include "DLinkedList.h" // Include your doubly linked list header
#include "minunit.h"     // Include the minunit test library

// Test case for createDLList
static char* test_createDLList() {
    DLList* list = createDLList();
    mu_assert("error: createDLList failed", list != NULL);
    mu_assert("error: createDLList size is not zero", size(list) == 0);
    freeDLList(list);
    return NULL;
}

// Test case for push and size
static char* test_push_and_size() {
    DLList* list = createDLList();
    push(list, 1);
    push(list, 2);
    push(list, 3);
    mu_assert("error: push and size test failed", size(list) == 3);
    freeDLList(list);
    return NULL;
}

// Test case for pop
static char* test_pop() {
    DLList* list = createDLList();
    push(list, 1);
    push(list, 2);
    push(list, 3);
    mu_assert("error: pop test failed", pop(list) == 3);
    mu_assert("error: pop and size test failed", size(list) == 2);
    freeDLList(list);
    return NULL;
}

// Test case for getCurrent, first, and next
static char* test_getCurrent_first_next() {
    DLList* list = createDLList();
    push(list, 1);
    push(list, 2);
    push(list, 3);
    
    first(list);
    mu_assert("error: getCurrent, first, and next test failed", getCurrent(list) == 1);
    
    next(list);
    mu_assert("error: getCurrent, first, and next test failed", getCurrent(list) == 2);
    
    next(list);
    mu_assert("error: getCurrent, first, and next test failed", getCurrent(list) == 3);
    
    next(list);
    mu_assert("error: getCurrent, first, and next test failed", getCurrent(list) == -1); // Should be at end
    freeDLList(list);
    return NULL;
}

// Test case for atEnd
static char* test_atEnd() {
    DLList* list = createDLList();
    push(list, 1);
    push(list, 2);
    
    first(list);
    mu_assert("error: atEnd test failed", atEnd(list) == false);
    
    next(list);
    mu_assert("error: atEnd test failed", atEnd(list) == true);
    freeDLList(list);
    return NULL;
}

// Test case for deleteCurrent
static char* test_deleteCurrent() {
    DLList* list = createDLList();
    push(list, 1);
    push(list, 2);
    push(list, 3);
    
    first(list);
    deleteCurrent(list);
    mu_assert("error: deleteCurrent test failed", size(list) == 2);
    mu_assert("error: deleteCurrent test failed", getCurrent(list) == 2);
    
    next(list);
    deleteCurrent(list);
    mu_assert("error: deleteCurrent test failed", size(list) == 1);
    mu_assert("error: deleteCurrent test failed", getCurrent(list) == -1); // Should be at end
    freeDLList(list);
    return NULL;
}

// Test case for insertAfter and insertBefore
static char* test_insertAfter_insertBefore() {
    DLList* list = createDLList();
    push(list, 1);
    push(list, 3);
    
    first(list);
    insertAfter(list, 2);
    mu_assert("error: insertAfter test failed", size(list) == 3);
    mu_assert("error: insertAfter test failed", getCurrent(list) == 2);
    
    next(list);
    insertBefore(list, 0);
    mu_assert("error: insertBefore test failed", size(list) == 4);
    mu_assert("error: insertBefore test failed", getCurrent(list) == 2);
    
    freeDLList(list);
    return NULL;
}

int main(int argc, char *argv[]) {
    char* result = NULL;
    result = test_createDLList();
    if (result != NULL) {
        printf("%s\n", result);
        return 1;
    }
    result = test_push_and_size();
    if (result != NULL) {
        printf("%s\n", result);
        return 1;
    }
    result = test_pop();
    if (result != NULL) {
        printf("%s\n", result);
        return 1;
    }
    result = test_getCurrent_first_next();
    if (result != NULL) {
        printf("%s\n", result);
        return 1;
    }
    result = test_atEnd();
    if (result != NULL) {
        printf("%s\n", result);
        return 1;
    }
    result = test_deleteCurrent();
    if (result != NULL) {
        printf("%s\n", result);
        return 1;
    }
    result = test_insertAfter_insertBefore();
    if (result != NULL) {
        printf("%s\n", result);
        return 1;
    }
    
    printf("All tests passed!\n");
    return 0;
}


/* listmain.c ends here */
