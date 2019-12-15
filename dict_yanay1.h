#ifndef _DICT_H_
#define _DICT_H_
#include "hash.h"

typedef struct _Element_Word* pWord;


//-------------------------------------------part 1 function-------------------------------------------
int HashWord(char* word, int size);

#endif

//-------------------------------------------struct word fucntion
pWord createElementWord(char* word, char* translate);
char* getElementInTranslate(pWord pw);
char* getElementInKey(pWord pw);
char* getElementInWord(pWord pw);
Result setElementTranslate(pWord pw, char* translate);
Result setElementWordAndKey(pWord pw, char* word);
