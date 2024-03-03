#include "vec.h"
#include <stdlib.h>

struct vector_header {
  size_t element;
  size_t length;
  size_t capacity;
};

void *_vector_init(size_t element, size_t length) {
  struct vector_header *vector = (struct vector_header*)malloc(sizeof(struct vector_header) + element * length);
  if (!vector) {
    return NULL;
  }
  vector->length = length;
  vector->capacity = length;
  vector->element = element;
  return vector + 1;
}
size_t vector_length(void *vector) {
  return ((struct vector_header*)vector - 1)->length;
}
int _vector_resize(void **vector, int new_length) {
  struct vector_header *_vector = (struct vector_header*)*vector - 1;
  if (new_length > _vector->capacity) {
    while (new_length > _vector->capacity) {
      _vector->capacity *= 2;
    }
    struct vector_header *new_vector = (struct vector_header*)realloc(_vector, sizeof(struct vector_header) + _vector->element * _vector->capacity);
    if (!new_vector) {
      return 0;
    }
    _vector = new_vector;
    *vector = new_vector + 1;
  }
  _vector->length = new_length;
  return 1;
}

void vector_free(void *vector) {
  free((struct vector_header*)vector - 1);
}

