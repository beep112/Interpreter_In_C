#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct {
    char *input; 
    int position;
    int readPosition;
    char ch;
} lexer_t;

// this takes a string input and returns input for the lexer
lexer_t *init_lexer(char *input);
void free_lexer(lexer_t *l);
void read_char(lexer_t *l);
// returns a string
char *read_identifier(lexer_t *l);
