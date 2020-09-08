# submarinesGame
Realizing a submarine game aimed at discovering all of the opponent's submarines, a player who revealed all of the opponent's submarines won.

The game board is 10x10 where one side is identified by letters and a second side is identified by numbers.

Submarines should be placed vertically or horizontally, not diagonally.

● Do not overlap the submarines (i.e., one will be placed on top of the other).

● Do not attach the submarines to each other, not even diagonally.

● The game is played in turns - when each turn the player tries to hit the submarine by scoring a coordinate for example: A3

If he hits the cube is marked as damaged and the player receives an appropriate message.

● If the entire submarine is damaged, the player receives a suitable message.

● In case all of the opponent's submarines are hit the second player wins.

The program receives a boot file - the file will fill the board with submarines according to the file.

The program receives a configuration file that will give a simulation of the game moves.

The Main function gets the file names as a parameter from which you will need to read the game moves of both players and update the game board accordingly.

The program checks every move to see if it is correct and only then will it execute it, if not - return an error message.

The program maintains a record of all the moves made.

This project focuses on modular programming, dynamic assignments, structures.
