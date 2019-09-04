//
// Created by valentun on 04.09.19.
//

#include <stdlib.h>
#include <stdio.h>

struct BaseCell {
    int number;
    struct BaseCell *next;
};

typedef struct BaseCell Cell;

typedef Cell *List;

Cell *create_node(int number) {
    Cell *result = malloc(sizeof(Cell));

    result->number = number;
    result->next = NULL;

    return result;
}

void insert_node_beginning(Cell *cell, List *listPtr) {
    List list = *listPtr;

    if (list == NULL) { // list is empty
        *listPtr = cell;
        return;
    }

    cell->next = list;
    *listPtr = cell;
}


void insert_beginning(int number, List *listPtr) {
    Cell *cell = create_node(number);

    insert_node_beginning(cell, listPtr);
}

void insert_node(Cell *cell, Cell *afterWhat, List *listPtr) {
    if (cell->next != NULL) {
        printf("Cannot insert not a single node");
        exit(1);
    }

    if (afterWhat == NULL) { // at the beginning
        insert_node_beginning(cell, listPtr);
    } else {
        Cell *old_next = afterWhat->next;

        cell->next = old_next;
        afterWhat->next = cell;
    }
}

void insert(int number, Cell *afterWhat, List *listPtr) {
    Cell *cell = create_node(number);

    insert_node(cell, afterWhat, listPtr);
}

Cell *find(int number, List list) {
    Cell *current = list;

    while (current != NULL) {
        if (current->number == number) {
            return current;
        }

        current = current->next;
    }

    return NULL;
}


void print_list(List list) {
    Cell *current = list;

    printf("[");

    while (current != NULL) {
        printf("%d", current->number);

        if (current->next != NULL) {
            printf(", ");
        }

        current = current->next;
    }

    printf("]\n");
}

void remove_node(Cell *cell, List *list) {
    Cell *prev = (*list);

    if (prev == NULL) {
        printf("List is empty");
        return;
    }

    while (prev->next != cell) {
        prev = prev->next;

        if (prev->next == NULL) return; // no element found
    }

    prev->next = cell->next;
    cell->next = NULL;
}

int main() {
    List list = NULL;

    insert_beginning(1, &list);
    print_list(list);

    insert(2, find(1, list), &list);
    print_list(list);

    insert(4, find(2, list), &list);
    print_list(list);

    insert(3, find(2, list), &list);
    print_list(list);

    remove_node(find(3, list), &list);
    print_list(list);
}
