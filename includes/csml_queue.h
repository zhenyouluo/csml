// The MIT License (MIT)
// 
// Copyright (c) 2014 Jeremy Letang (letang.jeremy@gmail.com)
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef CSML_QUEUE_H
#define CSML_QUEUE_H

#define impl_queue(type_name, T)\
\
struct item_queue_##type_name##_t {\
    T                                   item;\
    struct item_queue_##type_name##_t   *next;\
}item_queue_##type_name##_t;\
\
typedef struct queue_##type_name##_t {\
    T               *(*front)(struct queue_##type_name##_t *self);\
    T               *(*back)(struct queue_##type_name##_t *self);\
    void            (*pop)(struct queue_##type_name##_t *self);\
    bool            (*push)(struct queue_##type_name##_t *self, T item);\
    bool            (*is_empty)(struct queue_##type_name##_t *self);\
    unsigned int    (*len)(struct queue_##type_name##_t *self);\
    bool            (*free)(struct queue_##type_name##_t *self);\
    struct item_queue_##type_name##_t   *front_item;\
    struct item_queue_##type_name##_t   *back_item;\
    int                                 size;\
} queue_##type_name##_t;\
\
void            queue_##type_name##_t_initialize(struct queue_##type_name##_t *self, bool type);\
bool            queue_##type_name##_t_push(struct queue_##type_name##_t *self, T item);\
unsigned int    queue_##type_name##_t_len(struct queue_##type_name##_t *self);\
bool            queue_##type_name##_t_delete_heap(struct queue_##type_name##_t *self);\
bool            queue_##type_name##_t_delete_stacked(struct queue_##type_name##_t *self);\
void            queue_##type_name##_t_delete_in(struct queue_##type_name##_t *self);\
T               *queue_##type_name##_t_front(struct queue_##type_name##_t *self);\
T               *queue_##type_name##_t_back(struct queue_##type_name##_t *self);\
bool            queue_##type_name##_t_is_empty(struct queue_##type_name##_t *self);\
void            queue_##type_name##_t_pop(struct queue_##type_name##_t *self);\
\
queue_##type_name##_t *new_queue_##type_name##_t() {\
    queue_##type_name##_t *self = malloc(sizeof(queue_##type_name##_t));\
    printf("create\n");\
    if (self != 0) {\
        queue_##type_name##_t_initialize(self, true);\
    }\
    return self;\
}\
\
queue_##type_name##_t stacked_queue_##type_name##_t() {\
    queue_##type_name##_t self;\
    queue_##type_name##_t_initialize(&self, false);\
    return self;\
}\
\
void queue_##type_name##_t_initialize(struct queue_##type_name##_t *self, bool type) {\
    self->size = 0;\
    self->front_item = 0;\
    self->back_item = 0;\
    self->len = queue_##type_name##_t_len;\
    self->push = queue_##type_name##_t_push;\
    self->front = queue_##type_name##_t_front;\
    self->back = queue_##type_name##_t_back;\
    self->is_empty = queue_##type_name##_t_is_empty;\
    self->pop = queue_##type_name##_t_pop;\
    if (type) {\
        self->free = queue_##type_name##_t_delete_heap;\
    } else {\
        self->free = queue_##type_name##_t_delete_stacked;\
    }\
}\
\
void queue_##type_name##_t_delete_in(struct queue_##type_name##_t *self) {\
    \
}\
\
bool queue_##type_name##_t_delete_heap(struct queue_##type_name##_t *self) {\
    queue_##type_name##_t_delete_in(self);\
    return true;\
}\
\
bool queue_##type_name##_t_delete_stacked(struct queue_##type_name##_t *self) {\
    queue_##type_name##_t_delete_in(self);\
    return false;\
}\
\
bool queue_##type_name##_t_push(struct queue_##type_name##_t *self, T item) {\
   \
}\
\
T *queue_##type_name##_t_front(struct queue_##type_name##_t *self) {\
    return &self->front_item->item;\
}\
\
T *queue_##type_name##_t_back(struct queue_##type_name##_t *self) {\
    return &self->back_item->item;\
}\
\
void queue_##type_name##_t_pop(struct queue_##type_name##_t *self) {\
    \
}\
\
bool queue_##type_name##_t_is_empty(struct queue_##type_name##_t *self) {\
    return self->size == 0;\
}\
\
unsigned int queue_##type_name##_t_len(struct queue_##type_name##_t *self) {\
    return self->size;\
}

#define Queue(type_name) queue_##type_name##_t

#endif // CSML_QUEUE_H
