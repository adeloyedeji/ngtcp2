/*
 * ngtcp2
 *
 * Copyright (c) 2022 ngtcp2 contributors
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
#ifndef NGTCP2_OBJ_POOL_H
#define NGTCP2_OBJ_POOL_H

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif /* HAVE_CONFIG_H */

#include <ngtcp2/ngtcp2.h>

typedef struct ngtcp2_obj_pool_entry ngtcp2_obj_pool_entry;

struct ngtcp2_obj_pool_entry {
  ngtcp2_obj_pool_entry *next;
};

typedef struct ngtcp2_obj_pool {
  ngtcp2_obj_pool_entry *head;
} ngtcp2_obj_pool;

void ngtcp2_obj_pool_init(ngtcp2_obj_pool *opl);

void ngtcp2_obj_pool_free(ngtcp2_obj_pool *opl);

void ngtcp2_obj_pool_push(ngtcp2_obj_pool *obj, ngtcp2_obj_pool_entry *ent);

ngtcp2_obj_pool_entry *ngtcp2_obj_pool_pop(ngtcp2_obj_pool *obj);

#endif /* NGTCP2_OBJ_POOL_H */