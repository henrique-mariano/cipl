{CONSTANT_INTEGER} {
    if(DEBUG_LEX == 1) print_token("Constant integer");
    num_col += yyleng;
    return CONSTANT_INTEGER_TOKEN;
}

{CONSTANT_REAL} {
    if(DEBUG_LEX == 1) print_token("Constant real");
    num_col += yyleng;
    return CONSTANT_REAL_TOKEN;
}

{STRING} {
    if(DEBUG_LEX == 1) print_token("String");
    num_col += yyleng;
    return STRING_TOKEN;
}

{OP_BINARY_ARITHMETIC} {
    if(DEBUG_LEX == 1) print_token("Arithmetic operation");
    num_col += yyleng;
    switch(yytext[0]){
        case '+':
        case '-':
            return ADD_MIN_TOKEN;
        case '*':
        case '/':
            return MUL_DIV_TOKEN;
    }
}

{OP_LOGIC} {
    if(DEBUG_LEX == 1) print_token("Logic operation");
    num_col += yyleng;
    switch(yytext[0]){
        case '!':
            return NEQUAL_TOKEN;
        case '|':
            return OR_TOKEN;
        case '&':
            return AND_TOKEN;
    }
}

{OP_BINARY_RELATIONAL} {
    if(DEBUG_LEX == 1) print_token("Relational operation");
    num_col += yyleng;
    return OP_BINARY_RELATIONAL_TOKEN;
}

{OP_UNARY_LIST} {
    if(DEBUG_LEX == 1) print_token("Unary operation list");
    num_col += yyleng;
    return OP_UNARY_LIST_TOKEN;
}

{OP_BINARY_LIST} {
    if(DEBUG_LEX == 1) print_token("Binary operation list");
    num_col += yyleng;
    return OP_BINARY_LIST_TOKEN
}

{COMMAND_FLOW_CONTROL} {
    if(DEBUG_LEX == 1) print_token("Flow control command");
    num_col += yyleng;
}

{COMMAND_INPUT_OUTPUT} {
    if(DEBUG_LEX == 1) print_token("IN/OUT operation");
    num_col += yyleng;
}

{ID} {
    if(DEBUG_LEX == 1) print_token("ID");
    num_col += yyleng;
}

{BRACKET} {
    switch(yytext[0]){
        case '[':
        case ']':
            if(DEBUG_LEX == 1) print_token("Square bracket");
            num_col += yyleng;
            break;
        case '{':
        case '}':
            if(DEBUG_LEX == 1) print_token("Curly bracket");
            num_col += yyleng;
            break;
        case '(':
        case ')':
            if(DEBUG_LEX == 1) print_token("Parenthesis");
            num_col += yyleng;
            break;
    }
}

{COMMA} {
    switch(yytext[0]){
        case ',':
            if(DEBUG_LEX == 1) print_token("Comma");
            num_col += yyleng;
            break;
        case ';':
            if(DEBUG_LEX == 1) print_token("Semicolon");
            num_col += yyleng;
            break;
    }
}