#ifndef DATA_H
#define DATA_H

typedef struct data data;

data* data_new_string (char const*);
data* data_new_blob (char const*, unsigned int);
data* data_ref (data*);
void data_unref (data*);
char* data_as_string (data const*);
unsigned int data_hash (data const*);
int data_cmp (data const*, data const*);

#endif
