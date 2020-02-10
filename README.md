# nim5

## intro

A simple C++ code of the nim game and AI.  
You can either play with the other player local or play with my AI.

## Game rules

You can find the basic rules of nim [here](https://en.wikipedia.org/wiki/Nim).  
In this project, there are 5 rows of pieces, and the ___N___-th row contains ___N___ pieces.  
So the gameboard is as follows:

```
Row No.

   1          *
   2         * *
   3        * * *
   4       * * * *
   5      * * * * *
```

### Removing piece

Players take turns removing piece(s) on the board comply with the following rules:  

 - Player has to remove 1~3 pieces on the board.
 - The pieces been removed in the same round must adjacent to each other.
 - The pieces been removed in the same round must be able to link with a straight line.

## Compile environment

All of the codes are Compiled and tested in the following enviornment.  
 - Compiler: g++(7.3.0)
 - Operating System: Ubuntu18.04
