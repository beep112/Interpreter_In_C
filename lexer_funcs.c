#include "lexer.h"
#include "token.h"

// allocates the memory for one lexer type
lexer_t *init(char *input) {
  if (input != NULL) {
    lexer_t *l = malloc(sizeof(lexer_t));
    l->input = input;
    l->position = 0;
    l->readPosition = 0;
    l->ch = input[0];
    read_char(l);
    return l;
  }

  return NULL;
}

void free_lexer(lexer_t *l) { free(l); }

void read_char(lexer_t *l) {
  if (l->readPosition >= strlen(l->input)) {
    l->ch = 0;
  } else {
    l->ch = l->input[l->readPosition];
  }
  l->position = l->readPosition;
  l->readPosition++;
}
