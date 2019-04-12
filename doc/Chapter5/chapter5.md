# Chapter 5

## Comprehensive quiz

### Q1

Implement a game of hi-lo. First, your program should pick a random integer between 1 and 100. The user is given 7 tries to guess the number.

If the user does not guess the correct number, the program should tell them whether they guessed too high or too low. If the user guesses the right number, the program should tell them they won. If they run out of guesses, the program should tell them they lost, and what the correct number is. At the end of the game, the user should be asked if they want to play again. If the user doesn’t enter ‘y’ or ‘n’, ask them again.

Here’s what your output should look like:

```
Let's play a game.  I'm thinking of a number.  You have 7 tries to guess what it is.
Guess #1: 64
Your guess is too high.
Guess #2: 32
Your guess is too low.
Guess #3: 54
Your guess is too high.
Guess #4: 51
Correct! You win!
Would you like to play again (y/n)? y
Let's play a game.  I'm thinking of a number.  You have 7 tries to guess what it is.
Guess #1: 64
Your guess is too high.
Guess #2: 32
Your guess is too low.
Guess #3: 54
Your guess is too high.
Guess #4: 51
Your guess is too high.
Guess #5: 36
Your guess is too low.
Guess #6: 45
Your guess is too low.
Guess #7: 48
Your guess is too low.
Sorry, you lose.  The correct number was 49.
Would you like to play again (y/n)? q
Would you like to play again (y/n)? f
Would you like to play again (y/n)? n
Thank you for playing.
```

Hits:

- Use the Mersenne Twister algorithm for generating random number. (googling "std::uniform_int_distribution")
- Write a function that allows the user to play a single game of hi-lo.
- Write a function that asks the user if they want to play again and handles the looping logic for an incorrect input.

Note: You have to implement error handling for the user’s guess. Handle invalid input (e.g. ‘x’) or valid input with extraneous characters (e.g. “43x”) when the user is guessing a number.

- Write a separate function to handle the user inputting their guess (along with the associated error handling).
