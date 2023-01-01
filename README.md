# Tower Defence Game

This is a simple implementation of a classic tower defence game. It was done as a part of the course "Object-orientd programming with C++" at Aalto University. In the game, the player can build different types of towers to defend themselves against incoming waves of enemies. If an enemy makes it to the end, the game is lost. The player can choose between five different levels of increasing difficulty. The game is built with C++ using the SFML library. The project tries to follow the Google C++ Style for coding.

# Group
- Ren Kun
- Veeti Jaakkola
- Olavi Kiuru
- Our fourth member had to drop the course at the start of the project and did not contribute to the project in any meaningful way. 

# Compiling instructions

When using VS Code, open the folder that includes the CMakeLists.txt. This should prompt you to choose a compiler. Choose the g++ compiler. Afterwards, the program should configure itself. If this does not happen or you need to reconfigure the program, click on the terminal tab on the top toolbar and choose Run Task… and then CMake: configure. To build the file, again choose Run Task… but choose CMake: build instead. This will create a build/ folder that includes the executable MyGame. The program requires the SFML library to function, though you should not need to download the SFML library to your own computer as CMake fetches the required files from a GitHub repository. You can also use the commands cmake . and make. If you just want to play the game the already compiled executable of the game can be found in the doc/ folder.

# How to play
The software is launched by executing the executable MyGame that can be found in the /build folder after first building the software with CMake. When the software is launched, the player is presented with an opening screen where they can choose between five different levels. Clicking on a level tile launches that level. In the levels the player can buy towers by first clicking the wanted tower icon on the right side of the screen and then clicking anywhere on the map. If the player clicks on an already placed tower the tower will be upgraded. When the player is ready they can click the start wave button to start the spawning of enemies. At any point the player can also click the back button to go back to the level select screen. If any enemies reach the end of the level, the game is lost. The player wins when all enemies have been killed.
