# Monopoly
This project is a simple undertaking by Chris Browne to create a computerised version of the popular board game Monopoly.

# Architecture
## Game class
The Game class represents pretty well all of the ''output'' side of things, which means it needs replacing if you want to develop,
say, an SDL version or a curses version.   
## Agents
Agents are the abstraction of the input side of things.  There are currently two agent classes available for use, HumanAgent and
ComputerAgent.  In theory, in the future, more agents could be implemented (JoystickAgent vs KeyboardAgent, EasyAgent vs HardAgent
and so on).  The Agent.h file contains an abstract base class upon which to base all of your Agent classes.

## Debug levels
### 0
Only crash-inducing errors will be reported
### 1
All errors will be reported, including those we can recover from
### 2
All errors and warnings will be reported, including warnings that only affect the performance of the game
### 3
Extra debugging information about mouse location and key presses will be output to the console

# Legal bullshit
Dear Hasbro,

I recognise that I may be infringing on any number of copyright and trademark thingies, but I'm not a lawyer and neither am I
setting out to deliberately steal money from you.  Should this project ever make any money in the future, I shall probably hire
a lawyer in order to sort out any issues that arise.  Since I greatly enjoy playing the board game Monopoly, I would hate for
my project to in any way detriment the success of the -opoly franchise or Hasbro games themselves.

Thanks,

Chris