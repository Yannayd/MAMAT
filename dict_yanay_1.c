#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"
#include "dict.h"

struct _Element_Word
{
	char* word;
	char* translate;
	char* key;
};

//---------------------------------------------hash passed functions------------------------------------------//
int HashWord(char* word, int size)
{
	return ((int)(((word[0] - 'a') * 26 + strlen(word)) % size));
}

void PrintEntry(pWord pw)
{
	if (pw == NULL || pw->word == NULL || pw->translate == NULL) return;
	printf("%s = %s\n", pw->word, pw->translate);
}

Result CompareWords(char* word1, char* word2)
{
	if (strcmp(word1, word2) == 0) return SUCCESS;
	return FAIL;
}

char* getEntryKey(pWord pw)
{
	if (pw == NULL) return NULL;
	return pw->key;
}

Result DestroyEntry(pWord pw)
{
	if (pw == NULL) return FAIL;
	free(pw->translate); //????
	free(pw->word);
	free(pw->key);
	free(pw); 
}
//---------------------------------------------struct word function------------------------------------------//

pWord createElementWord(char* word, char* translate)
{
	if (word == NULL || translate == NULL) return NULL;
	pWord pw;
	if ((pw = (pWord)malloc(sizeof(struct _Element_Word))) == NULL) return NULL;
	pw->word = word;
	pw->translate = translate;
	pw->key = word;
	return pw;
}

Result setElementWordAndKey(pWord pw, char* word)
{
	if (pw == NULL || word == NULL) return FAIL;
	pw->word = word;
	pw->key = word;
	return SUCCESS;
}

Result setElementTranslate(pWord pw, char* translate)
{
	if (pw == NULL || translate == NULL) return FAIL;
	pw->translate = translate;
	return SUCCESS;
}

char* getElementInWord(pWord pw)
{
	if (pw == NULL) return NULL;
	return pw->word;
}
char* getElementInKey(pWord pw)
{
	if (pw == NULL) return NULL;
	return pw->key;
}
char* getElementInTranslate(pWord pw)
{
	if (pw == NULL) return NULL;
	return pw->translate;
}
