# Syntax Tree

## PROGRAM

``` Program -> [ Variable | Function Decl | Function Defn ]* ```

## Variable

``` Variable -> Type, Name, ( OPERATOR_ASSIGNMENT, Value )? , ( Comma, Name, ( OPERATOR_ASSIGNMENT, Value )? )* ```

## Value

``` Value ->  [ Identifier | String | Number | Inline Expression ] ```

## Inline Expression

``` Inline Expression -> [ Identifier | String | Number ] ( [ OPERATOR ] [ Identifier | String | Number ) + ```

## Function

``` Function -> ( RETURN_TYPE, FUNCTION_NAME, LPAREN, PARAM* , LPAREN, [ SEMICOLON | ( LBRACE, EXPRESSION*, RBRACE ) ] ```
