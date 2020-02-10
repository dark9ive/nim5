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

### Removing pieces

Players take turns removing piece(s) on the board comply with the following rules:  

 - Player has to remove 1~3 pieces on the board.
 - The pieces been removed in the same round must adjacent to each other.
 - The pieces been removed in the same round must be able to link with a straight line.

For example, in the following situation, the player can remove the pieces "0, 1, 3" in his/her round.  
But removing pieces "0, 4, C" is illegal.(Not adjacent to each other.)  
Removing __"0, 2, 4"__ is also illegal.("0, 2, 4" can't be linked with a straight line.)  
Removing __0, 2, 5__ is also illegal.("5" has been removed.)  

```
Row No.

   1          0
   2         1 2
   3        3 4 X
   4       6 7 8 9
   5      A X C D E
```
### Wining Condition

The player removes the last piece loses the game. In other words, if you forced the other player to remove the last piece, you win the match.

## Compile environment

All of the codes are Compiled and tested in the following enviornment.  
 - Compiler: g++(7.3.0)
 - Operating System: Ubuntu18.04
