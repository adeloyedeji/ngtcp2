/*
 * ngtcp2
 *
 * Copyright (c) 2017 ngtcp2 contributors
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
#ifndef NGTCP2_MACRO_H
#define NGTCP2_MACRO_H

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif /* HAVE_CONFIG_H */

#include <stddef.h>

#include <ngtcp2/ngtcp2.h>

#define ngtcp2_min(A, B) ((A) < (B) ? (A) : (B))
#define ngtcp2_max(A, B) ((A) > (B) ? (A) : (B))

#define ngtcp2_struct_of(ptr, type, member)                                    \
  ((type *)(void *)((char *)(ptr)-offsetof(type, member)))

/* ngtcp2_list_insert inserts |T| before |*PD|.  The contract is that
   this is singly linked list, and the next element is pointed by next
   field of the previous element.  |PD| must be a pointer to the
   pointer to the next field of the previous element of |*PD|: if C is
   the previous element of |PD|, PD = &C->next. */
#define ngtcp2_list_insert(T, PD)                                              \
  do {                                                                         \
    (T)->next = *(PD);                                                         \
    *(PD) = (T);                                                               \
  } while (0)

/* ngtcp2_list_remove removes |*PT| from singly linked list.  The
   contract is the same as ngtcp2_list_insert.  |PT| must be a pointer
   to the pointer to the next field of the previous element of |*PT|.
   Please be aware that |*PT|->next is not modified by this macro. */
#define ngtcp2_list_remove(PT)                                                 \
  do {                                                                         \
    *(PT) = (*(PT))->next;                                                     \
  } while (0)

#endif /* NGTCP2_MACRO_H */
