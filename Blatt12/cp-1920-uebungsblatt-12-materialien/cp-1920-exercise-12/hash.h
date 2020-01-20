#ifndef HASH_H
#define HASH_H

typedef void (*hash_remove_func) (void*);

void hash_init (hash_remove_func);
void hash_fini (void);
int hash_insert (unsigned int, void*);
int hash_remove (unsigned int);

#endif
