#include "lexer.h"
#include "token.h"

// allocates the memory for one lexer type
lexer_t *init(char *input) {
  lexer_t *l = malloc(sizeof(lexer_t));
  l->input = input;
  l->position = -1;
  l->readPosition = -1;
  l->ch = '\0';
  read_char(l);

  return l;
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
