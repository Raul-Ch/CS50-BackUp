// Declares a dictionary's functionality

// This file, clang will only compile it once.

// si lo siguiente no está definido".
#ifndef DICTIONARY_H
// A preprocessor directive that is used to define macros in a C program.
#define DICTIONARY_H

#include <stdbool.h>

// Maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45

// Prototypes
bool check(const char *word);
unsigned int hash(const char *word);
bool load(const char *dictionary);
unsigned int size(void);
bool unload(void);

#endif // DICTIONARY_H
// Cada directiva #if de un archivo de código fuente debe coincidir con
// una directiva #endif de cierre.