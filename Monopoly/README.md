# Monopoly
This project is a simple undertaking by Chris Browne to create a computerised version of the popular board game Monopoly.

# Architecture
## Server
The server is automatically started and well integrated into the client.  In fact, the client must be chosen at compile-time,
since it is compiled into a single executable.  I've chosen to keep it this way to simplify things for users of binary distributions
of the game.  The server manages the board, the players' wealth and ownership and the randomised events (dice rolls, chance/community chest, etc.)

## Client
The client is responsible for displaying the game to the user (the Display class/module) and extracting input from the user (the Input class/module).
Its simple design lends itself to extension and replacement, but initially I only plan to work on a text-based front-end for simplicity's sake.
I may eventually develop an SDL frontend, pending developer interest.

# Legal bullshit
Dear Hasbro,

I recognise that I may be infringing on any number of copyright and trademark thingies, but I'm not a lawyer and neither am I
setting out to deliberately steal money from you.  Should this project ever make any money in the future, I shall probably hire
a lawyer in order to sort out any issues that arise.  Since I greatly enjoy playing the board game Monopoly, I would hate for
my project to in any way detriment the success of the -opoly franchise or Hasbro games themselves.

Thanks,

Chris