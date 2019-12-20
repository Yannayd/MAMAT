#define _CRT_SECURE_NO_WARNINGS

#ifndef _DICT_H_
#define _DICT_H_

#include "hash.h"

typedef struct _Element_Word* pWord;//are you sure this is okey?


/*-------------------------------------------part 1 functions------------------------------------------*/
int HashWord(void* word, int size);
Result PrintEntry(void* pw);
void* GetEntryKey(void* pw);
CompResult CompareWords(void* word1, void* word2);
void DestroyEntry(void* pw);

/*------------------------------------------part 2 functions-------------------------------------------*/
pHash CreateDictionary();
Result AddTranslation(pHash ph, char* word, char* translation);
Result Translate(pHash ph, char* word);
Result DeleteTranslation(pHash ph, char* word);
Result PrintDictionary(pHash ph);

//-------------------------------------------struct word fucntion
pWord createElementWord(char* word, char* translate);
char* getElementInTranslate(pWord pw);
char* getElementInKey(pWord pw);
char* getElementInWord(pWord pw);
Result setElementTranslate(pWord pw, char* translate);
Result setElementWordAndKey(pWord pw, char* word);


#endif
