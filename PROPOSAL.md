# Proposal: PacMan
Haozhe Dong & Arman Popli

## Synopsis
###Elements
A Pacman character that travels around the map and eats white dots, eventually eating all the dots to win the game

Multiple Ghosts chasing the Pacman on the map, player gonna fail the game after a ghost touches the Pacman.

###Goal
Player needs to move the Pacman to evade all of the Ghosts, eat all the white dots, and eventually eat all the whites dot to beat the level.

###Gameplay
Pacman starts at the middle left of the map. The player can press WASD key to move the ghost, creating all the ghosts and dots he must eat. A new ghost is moving towards the Pacman. The player needs to avoid all of the Ghosts, eat all of the dots to win the game. If the player is eaten by the Ghost before he or she completes the game, the game will immediately quite.

## Functional requirements

To create a map and adding white dots to the map that players can move the Pacman to eat those dots.

A Pacman is placed in the right middle of the map.

The Pacman’s x and y coordinate follows the WASD key push, while its x and y coordinate are fixed.

The red ghost will start to move towards the player.

The blue ghost will move in horizontal direction.

When the ghost is touching the Pacman, the player lost the game and the game will immediately quite.

After eating all the white dots. The player won the game.

## Open questions

How much will the Ghosts speed up such that the game becomes appropriately difficult yet not impossible?

How are the maps going to change? Will the path change? Will the placement of the goal dot change? Will they be randomly changed? Will there be a discrete number of levels or will the game be infinite?

What are the dimensions and velocities that will optimize gameplay?

