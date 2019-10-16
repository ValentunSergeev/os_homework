//
// Created by valentun on 16.10.19.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIT sizeof(long long int) * 8 - 1
#define FRAMES_COUNT 10

typedef struct {
    long long int counter;
    int current_bit;

    int id;

    char referenced;
} Page;

Page * new_page(int id) {
    Page * page = (Page *) malloc(sizeof(Page));

    page->counter = 0;
    page->referenced = 1;
    page->current_bit = 0;
    page->id = id;

    return page;
}

void updatePageCounter(Page * page) {
    long long int current_counter = page->counter;

    current_counter = current_counter >> 1;

    current_counter^= (-page->referenced ^ current_counter) & (1UL << page->current_bit);

    page->counter = current_counter;

    if (page->current_bit < MAX_BIT) {
        page->current_bit++;
    }
}

Page * findPage(Page ** arr, int id) {
    for (int i = 0; i < FRAMES_COUNT && arr[i] != NULL; ++i) {
        if (arr[i]->id == id) {
            return arr[i];
        }
    }

    return NULL;
}

int page_to_remove_position(Page ** pages) {
    int position = 0;
    long long int min = pages[0]->counter;

    for (int i = 1; i < FRAMES_COUNT; ++i) {
        if (pages[i]->counter < min) {
            min = pages[i]->counter;

            position = i;
        }
    }

    return position;
}

int main() {
    Page ** pages = calloc(FRAMES_COUNT, sizeof(Page *));

    int next_page_id;
    int total_pages = 0;
    int hit = 0;
    int miss = 0;

    while (scanf("%d ", &next_page_id) == 1) {
        Page * referenced_page = findPage(pages, next_page_id);

        if (referenced_page != NULL) {
            referenced_page->referenced = 1;

            hit++;
        } else {
            int index_to_insert = 0;

            if (total_pages == FRAMES_COUNT) {
                int to_remove = page_to_remove_position(pages);

                free(pages[to_remove]);

                index_to_insert = to_remove;

            } else {
                index_to_insert = total_pages;

                total_pages++;
            }

            pages[index_to_insert] = new_page(next_page_id);

            miss++;
        }


        for (int i = 0; i < FRAMES_COUNT && pages[i] != NULL; ++i) {
            updatePageCounter(pages[i]);
        }
    }

    printf("Hit/Miss: %f", hit * 1.0 / miss);
}
