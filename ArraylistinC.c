#include <stdlib.h>
#include <assert.h>
#include "ArrayList.h"

struct _arraylist {
    size_t size;
    size_t data_size;
    void ** data;
};

struct _arraylist *arraylist_create() {
    /* Allocate Memory */
    struct _arraylist *list = malloc(sizeof(struct _arraylist));
    assert(list != NULL);
    list->size = 0;
    list->data_size = 0;
    list->data = calloc(2, sizeof(void *));
    assert(list->data != NULL);
    list->data[0] = NULL;
    return list;
}

void arraylist_set_data(struct _arraylist *list, void ** data) {
    arraylist_clear(list);
    list->data = data;
    for(int i = 0; ( list->data[i] != NULL ); ++i) {
        list->data_size += sizeof(*list->data[i]);
        ++list->size;
    }
}

void arraylist_add(struct _arraylist *list, void *elem) {
    list->data_size += sizeof(*elem);
    void ** new_data = realloc(list->data, (list->size + 1) * (list->data_size));
    assert(new_data != NULL);
    new_data[list->size] = elem;
    new_data[list->size + 1] = NULL;
    arraylist_set_data(list, new_data);
    ++list->size;
}

void *arraylist_get(struct _arraylist *list, int index) {
    return list->data[index];
}

void arraylist_remove(struct _arraylist *list, int index) {
    list->data_size -= sizeof( *arraylist_get( list, index ) );
    for ( int i = index; list->data[i + 1] != NULL; ++i )
        list->data[i] = list->data[i + 1];
    list->data[list->size] = NULL;
    void ** new_data = realloc(list->data, list->size * list->data_size);
    assert(new_data != NULL);
    arraylist_set_data(list, new_data);
    --list->size;
}

void arraylist_clear(struct _arraylist *list) {
    /* free(list->data); */ /* Problem here */
    list->size = 0;
    list->data_size = 0;
    list->data = NULL;
}

void arraylist_deallocate(struct _arraylist *list) {
    arraylist_clear(list);
    free(list);
}
