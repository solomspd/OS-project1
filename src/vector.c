/*
//
// Created by Yusuf Sherif on 2020-03-03.
//
*/
/*
#include "vector.h"


void vector_init(vec_t* vector) {
vector->t = (TYPE *) calloc(VECTOR_INCREMENT, sizeof(TYPE));
vector->vec_capacity = VECTOR_INCREMENT;
vector->vec_size = 0;
}

void vector_resize(vec_t *vector, unsigned int n) {
    //Shaving off extra elements in case of shrinking
    if(n < vector->vec_capacity)
        for (int i = n; i < vector->vec_capacity; ++i) {
            DESTRUCT(&vector->t[i]);
        }
    //resizing the actual array
    TYPE *temp = (TYPE *) realloc(vector->t, n * sizeof(TYPE));



    //Set vec_size to n in case of shrinking. Else vec_size stays the same.
    if (n < vector->vec_size) {
        vector->vec_size = n;
    }

    //In case of expansion do placement new on all new elements. Otherwise, this loop will be skipped.
/*        for (int i = vector->vec_capacity; i < n; ++i) {
            new (&t[i]) T();
        }*//*


    vector->vec_capacity = n;

    vector->t = temp;

    if (temp == NULL) {
        fprintf(stderr, "vector: Couldn't allocate more memory!");
        abort();
    }

}

TYPE *vector_back(vec_t *vector) {
    if (vector->vec_size == 0) {
        fprintf(stderr, "vector: vector_back() function on vector_empty vector");
        abort();
    }
    return &vector->t[vector->vec_size - 1];
}

TYPE *vector_front(vec_t *vector) {
    if (vector->vec_size == 0) {
        fprintf(stderr, "vector: vector_back() function on vector_empty vector");
        abort();
    }
    return &vector->t[0];
}

bool vector_empty(vec_t *vector) {
    return vector->vec_size == 0;
}

void vector_clear(vec_t *vector) {
*/
/*    for (int i = 0; i < vector->vec_capacity ; ++i) {
        t[i].~T();
        new (&t[i]) T();
    }*//*

    vector->vec_size = 0;
}

void vector_push_back(vec_t *vector, TYPE val) {
    if (vector->vec_size < vector->vec_capacity) {
        vector->t[vector->vec_size++] = val;
    } else {
        vector_resize(vector, vector->vec_capacity + VECTOR_INCREMENT);
        vector->t[vector->vec_size++] = val;
    }
}

unsigned int vector_size(vec_t *vector) {
    return vector->vec_size;
}

void vector_destruct(vec_t* vector) {
*/
/*    for (int i = 0; i < vector->vec_capacity ; ++i) {
        vector->t[i].~T();
    }*//*

free(vector->t);
}*/
