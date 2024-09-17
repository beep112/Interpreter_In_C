#pragma once
#include "lexer.h"
#include <stdio.h>
#include <string.h>


typedef enum {
    ILLEGAL, 
    EOF_E,
    IDENT,
    INT,
    ASSIGN,
    PLUS,
    COMMA,
    SEMICOLON,
    LPAREN,
    RPAREN,
    LBRACE,
    RBRACE,
    FUNCTION,
    LET,
    DEFAULT,
} tokentype;

typedef struct {
    tokentype type;
    char *literal;
} token_t;

token_t *next_token(lexer_t *lexer);
token_t *init_token(tokentype sym, char *literal);
void free_token(token_t *token);
