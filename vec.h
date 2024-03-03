#ifndef VEC_H
#define VEC_H

#include <stdlib.h>

#define vec *
#define vector_init(t, length) ((t*)_vector_init(sizeof(t), (length)))
#define vector_resize(v, length) (_vector_resize((void**)(v), (length)))

void *_vector_init(size_t element, size_t length);
size_t vector_length(void *vector);
int _vector_resize(void **vector, int new_length);
void vector_free(void *vector);

#endif
