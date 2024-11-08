# Snake Game in C++

This is a simple Snake game implemented in C++ for the console. The player controls the snake to collect targets (represented by `O`) to increase the score. The game ends if the snake hits the walls or itself.

## How to Play

- Use the **W**, **A**, **S**, and **D** keys to control the snake's movement:
  - **W** - Move Up
  - **A** - Move Left
  - **S** - Move Down
  - **D** - Move Right
- Collect the target (O) to grow the snake and increase your score.
- Avoid hitting the walls or the snake's own tail, or the game will end.
- Press **0** to quit the game at any time.

## Features

- Real-time control of the snake using keyboard input.
- Snake grows longer each time a target is collected.
- Score tracking.
- Simple ASCII graphics to display the game in the console.

## Requirements

- A C++ compiler that supports standard libraries (e.g., GCC, MSVC).
- Windows OS (The game uses `<conio.h>` and `<windows.h>` headers, which are Windows-specific).

## How to Compile and Run

1. Clone the repository:
   ```bash
   git clone https://github.com/username/snake-game.git
   cd snake-game
