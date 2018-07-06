#pragma once

struct _S_GAMEOBJECT;

void CreateObject(_S_GAMEOBJECT **ppObj, const char *pName, int nHp);
void dumpObject(_S_GAMEOBJECT *pObj);