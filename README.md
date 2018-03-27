# lem-in
Move ants from start room to the end room with condition of one ant in a room at a time in a shortest way.
The map, passed to a programm should have:
1. a number of ants;
2. ##start && ##end command (doesn't matter in what order)
3. after each of these command the name of a room and its coordinates separated by a space
4. all around the map there can be a comment, which should start with #.
In all other cases it would be an error

Usage: ./lem-in < maps/map_test2
or you can create your oun map (programm reads from the standard input). To finish writing a map and start executing you need 
to write a command ##break.

An example of maps can be found in maps/ folder.
