#ifndef _ARRAYLIST_H
#define _ARRAYLIST_H

typedef struct _arraylist ArrayList;

extern ArrayList *arraylist_create();
extern void arraylist_set_data(ArrayList *, void **);
extern void arraylist_add(ArrayList *, void *);
extern void *arraylist_get(ArrayList *, int);
extern void arraylist_remove(ArrayList *, int);
extern void arraylist_clear(ArrayList *);
extern void arraylist_deallocate(ArrayList *);
//added for test by gejo
#endif /* _ARRAYLIST_H */
