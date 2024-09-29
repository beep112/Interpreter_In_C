#include "token.h"
#include "lexer.h"

token_t *next_token(lexer_t *lexer) {
  token_t *token = NULL;
  switch (lexer->ch) {
  case '=':
    token = init_token(ASSIGN, &lexer->ch);
    break;
  case ';':
    token = init_token(SEMICOLON, &lexer->ch);
    break;
  case '(':
    token = init_token(LPAREN, &lexer->ch);
    break;
  case ')':
    token = init_token(RPAREN, &lexer->ch);
    break;
  case ',':
    token = init_token(COMMA, &lexer->ch);
    break;
  case '+':
    token = init_token(PLUS, &lexer->ch);
    break;
  case '{':
    token = init_token(LBRACE, &lexer->ch);
    break;
  case '}':
    token = init_token(RBRACE, &lexer->ch);
    break;
  case '\0':
    token = init_token(EOF_E, "");
    break;
  default:
    token = init_token(ILLEGAL, "");
  }

  read_char(lexer);
  return token;
}

token_t *init_token(tokentype sym, char *lit) {
  token_t *token = malloc(sizeof(token_t));
  token->type = sym;
  token->literal = lit;

  return token;
}

void free_token(token_t *token) { free(token); }
