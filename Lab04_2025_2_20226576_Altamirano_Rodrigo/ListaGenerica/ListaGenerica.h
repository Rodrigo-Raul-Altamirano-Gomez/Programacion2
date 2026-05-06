//
// Created by hrodic on 27/04/2026.
//

#ifndef LISTAGENERICA_LISTAGENERICA_H
#define LISTAGENERICA_LISTAGENERICA_H

#include "list.h"

void new_list(list&);
void push_front(list&,void*,void* (*)(void*));
void push_back(list&,void*,void* (*)(void*));
void* begin(list);
void* end();
void* next(void*);
void* getValue(void*);
void foreach(list,void (*)(void*));
bool findIf(list,bool (*)(void*,void*),void*);

#endif //LISTAGENERICA_LISTAGENERICA_H
