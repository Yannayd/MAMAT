#define _CRT_SECURE_NO_WARNINGS

#define MAX_LENGTH 25
#define NUM_OF_ALPHABET 26
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"
#include "dict.h"
struct _Element_Word
{
	char* word;
	char* translate;
	char* key;//key and word the same?
};

//---------------------------------------------hash passed functions------------------------------------------//
int HashWord(void* word, int size)//are there invalid args?
{
	char* word_cast = (char*)(word);
	if (size <= 0 || word_cast == NULL)return -1;
	return ((int)(((word_cast[0] - 'a') * 26 + strlen(word_cast)) % size));
}

Result PrintEntry(void* pw)
{
	if (pw == NULL) return FAIL;
	pWord pw1 = (pWord)(pw);
	//if (pw = NULL) return FAIL;
	if (pw1 == NULL || pw1->word == NULL || pw1->translate == NULL) return FAIL;
	printf("%s : %s\n", pw1->word, pw1->translate);
	return SUCCESS;
}

CompResult CompareWords(void* word1, void* word2)
{
	if (word1 == NULL || word2 == NULL)return DIFFERENT;
	char* word1_cast = (char*)(word1);
	char* word2_cast = (char*)(word2);
	if (strcmp(word1_cast, word2_cast) == 0) return SAME;
	return DIFFERENT;
}

void* GetEntryKey(void* pw)
{
	if (pw == NULL) return NULL;
	pWord pw_cast = (pWord)(pw);
	return pw_cast->key;
}

void DestroyEntry(void* pw)
{
	if (pw == NULL) return;
	pWord pw_cast = (pWord)(pw);
	free(pw_cast->key);
	free(pw_cast->translate);
	free(pw_cast);
}
//---------------------------------------------struct word function------------------------------------------//

pWord createElementWord(char* word, char* translate)
{
	if (word == NULL || translate == NULL) return NULL;
	pWord pw = (pWord)malloc(sizeof(struct _Element_Word));
	if (pw == NULL)
	{
		printf("Error Allocation Memory\n");
		return NULL;
	}
	char* word_ = (char*)calloc(sizeof(char) * MAX_LENGTH, sizeof(char));
	if (word_ == NULL)
	{
		free(pw);
		printf("Error Allocation Memory\n");
		return NULL;
	}
	char* translate_ = (char*)calloc(sizeof(char) * MAX_LENGTH, sizeof(char));
	if (translate_ == NULL)
	{
		free(pw);
		free(word_);
		printf("Error Allocation Memory\n");
		return NULL;
	}
	strcpy(word_, word);
	strcpy(translate_, translate);
	pw->word = word_;
	pw->translate = translate_;
	pw->key = word_;
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

//----------------------------------------------------

pHash CreateDictionary()
{
	pHash ph;
	ph = HashCreate(MAX_LENGTH * NUM_OF_ALPHABET, HashWord, PrintEntry, CompareWords, GetEntryKey, DestroyEntry);
	if (ph == NULL)return NULL;
	return ph;
}

Result AddTranslation(pHash ph, char* word, char* translation)//can it return a value?
{

	pWord pw = createElementWord(word, translation);
	if (pw == NULL)return FAIL;
	if (HashAdd(ph, pw) == FAIL)return FAIL;
	return SUCCESS;
}

Result Translate(pHash ph, char* word)
{
	if (ph == NULL || word == NULL)return FAIL;
	pWord p_elem = (pWord)HashFind(ph, word);
	if (p_elem == NULL)return FAIL;
	printf("Translation: %s : %s\n", p_elem->key, p_elem->translate);
	return SUCCESS;
}

Result DeleteTranslation(pHash ph, char* word)
{
	if (HashRemove(ph, word) == FAIL)return FAIL;
	return SUCCESS;
}

Result PrintDictionary(pHash ph)
{
	if (ph == NULL)return FAIL;
	printf("Dictionary Contents\n");
	HashPrint(ph);
	return SUCCESS;
}
