#include "lexer.h"
#include "token.h"

void text_next_token(void) {
  char *input = "=+(){},;";

  token_t tests[9] = {{ASSIGN, "="}, {PLUS, "+"},      {LPAREN, "("},
                      {RPAREN, ")"}, {LBRACE, "{"},    {RBRACE, "}"},
                      {COMMA, ","},  {SEMICOLON, ";"}, {EOF_E, "\0"}};
  int testLen = 9;

  lexer_t *l = init_lexer(input);
  for (int i = 0; i < testLen; i++) {
    token_t tt = tests[i];
    token_t *tok = next_token(l);
    if (tok.type != tt.type) {
      fprintf(strerr, "tests[%d] - tokentype wrong. expected = %s, got = %s\n",
              tests[i]->literal, tok->literal);
    }
  }
}

int main(void) { return 0; }
