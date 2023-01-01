# Meeting Notes
In this file, you are required to take notes for your weekly meetings. 
In each meeting, you are required to discuss:

1. What each member has done during the week?
2. Are there challenges or problems? Discuss the possible solutions
3. Plan for the next week for everyone
4. Deviations and changes to the project plan, if any


# Meeting dd.mm.2021 HH::MM

**Participants**: 
1. Member 1
2. Member 2
3. Member 3
4. Member 4 

## Summary of works
1. Member 1 
   
   Implementing the class XX. Tested the class XX. 
   Results are in `tests/<class-xx-tests>`. Resolved the identified problems.

2. Member 2

   Same as above

3. ...

## Challenges

1. The integration of UI with the monsters requires an abstract interface.
2. ...

## Actions
1. Member 1 is going to look into defining an abstract interface for monsters 
   to enable easy UI integration.
2. Member 2 is going to work with Member 1 to use abstract interface in derived 
   monster classes.
3. Member 2 is going to test the interface.
4. Member 3 is going to use ...

> Please reflect these action decisions in your git commit messages so that 
> your group members and advisor can follow the progress.

## Project status 
Short summary of current project status. 

### TODOs
1. Member 1: Write an action.
2. ...

# Meeting 11.11.2022 14::00

**Participants**: 
1. Veeti Jaakkola
2. Kun Ren
3. Olavi Kiuru

## Summary of works
Everyone worked together to finish the plan.

## Actions
1. Veeti and Kun will work on making a working game screen
2. Olavi will work on a basic tower class.

## Project status 
Project plan finished. Next step is to start familiarising with the SFML library.

# Meeting 18.11.2022 14::00

**Participants**: 
1. Veeti Jaakkola
2. Kun Ren
(Olavi away at a conference.)

# Meeting 25.11.2022 16::00

**Participants**: 
1. Veeti Jaakkola
2. Kun Ren
3. Olavi Kiuru

## Summary of works
Kun has made a first version of an enemy class and fixed some issues with the game and level classes. Olavi has made two more tower classes (bomb tower and slow tower) and a projectile class that includes bullets and bombs.

## Actions
1. Kun will look into how to get the enemies moving along the path.
2. Olavi will look into placing towers with the mouse.

## Project status 
We are able to draw to the screen enemies, towers and projectiles. We are also able to update their positions.

# Meeting 02.12.2022 14::00

**Participants**: 
1. Kun Ren
2. Olavi Kiuru
(Veeti away at military service.)

## Summary of works
Kun has gotten the enemies to follow the path. Olavi has made it possible to place towers by clicking. We also moved most of the game logic to the level class.

## Actions
1. Kun will look into deleting enemies after they hit 0 HP. The player should also receive money when an enemy dies.
2. Olavi will look into making the bomb projectile hit many enemies.

## Project status 
The enemies now move correctly and the towers can shoot them. The UI still needs to be updated to include money, lives and instructions on how to place towers. We are close to a fully functioning first level. Adding other levels after that should not be too difficult.

# Meeting 09.12.2022 14::00

**Participants**: 
1. Kun Ren
2. Veeti Jaakkola
3. Olavi Kiuru

## Summary of works
Kun has made multiple different enemy types. Kun has also added waves and different maps. Olavi has added the range attribute to towers. Veeti has made some sprites for the GUI. Olavi and Veeti worked together to add a level select screen, upgradable tower and a functioning GUI.

## Actions
1. The deadline is in two days. Next everyone will work together to make sure the Git has all the necessary files in the correct format and place.

## Project status 
We have a functioning game. Only thing left is to write the documentation and any other files still missing from the Git.
