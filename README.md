# Escape Room 2.0 - C++

A Windows console escape game built as a C++ learning project, revisiting the idea from my [C# version](https://github.com/goldbarth/EscapeRoom).
Choose the room size, collect the key, and reach the unlocked exit.
Menus and instructions are in English.

## Gameplay

- Choose a room width from 25 to 35 and a height from 12 to 25.
- The player and key are placed randomly inside the room, with an exit on the right wall.
- Use the arrow keys to collect the key and open the exit.
- Reach the exit to trigger sound effects, an ending message, and the outro menu.
- Navigate the title, rules, and exit-confirmation screens from the console.

The game uses character graphics and console colors in a single rectangular room.
The objective is to collect the key and leave; there are no additional puzzles or levels.

## Build and run

The repository includes a Visual Studio solution configured for the MSVC `v143` toolset and the Windows 10 SDK.
Use Windows with Visual Studio 2022 and the **Desktop development with C++** workload, including those build components.

```sh
git clone https://github.com/goldbarth/EscapeRoom2.0.git
```

1. Open `EscapeRoom2.0.sln` in Visual Studio.
2. Select the `Debug` configuration and `x64` platform.
3. Build the solution.
4. Run without debugging with Ctrl+F5.

Use a console large enough for the menus and room, with ANSI color support.
The project uses `Windows.h`, `conio.h`, Win32 cursor functions, `Beep`, and `cls`; it needs platform changes before it can run natively on Linux or macOS.

## Controls

| Context | Key | Action |
| --- | --- | --- |
| Menus | Up / Down | Change the selected option |
| Menus | Enter | Confirm the selected option |
| Room setup | Integers, then Enter | Enter width and height |
| In game | Arrow keys | Move the player |
| Quit confirmation | `y` / `n`, then Enter | Confirm / cancel |

The player is `@` and the key is `$`.
Collecting the key opens the exit automatically.
The rules and outro screens offer a return to the main menu or an application exit.

## Code structure

Source files are in `EscapeRoom2.0/`.

| Files | Responsibility |
| --- | --- |
| `main.cpp` | Entry point and cursor visibility |
| `Application.h`, `Application.cpp` | Application states and dispatch between menus and gameplay |
| `Menu.h`, `Menu.cpp` | Menu selection, rules, banners, and exit confirmation |
| `Game.h`, `Game.cpp` | Room setup, game loop, key/exit checks, and win sequence |
| `Room.h`, `Room.cpp` | Room storage and rendering |
| `Player.h`, `Player.cpp` | Input, movement, wall checks, and key collection |
| `Key.h`, `Key.cpp`, `Exit.h`, `Exit.cpp` | Object placement and drawing |
| `IObject.h` | Shared object interface and coordinates |
| `cwtr.h`, `cwtr.cpp` | Console output, colors, cursor positioning, and clearing |
| `Defines.h` | Input codes, menu layout values, and room-size bounds |

## Project status

This is a learning project with an implemented gameplay loop and Windows-specific console code.
The repository has no automated test suite or portable build setup such as CMake.
Room dimensions are validated before play, but console layout still depends on the available window size.

## Related projects

| Repository | Language | Scope |
| --- | --- | --- |
| [EscapeRoom](https://github.com/goldbarth/EscapeRoom) | C# | Original console game with German menus |
| [EscapeRoom2.0](https://github.com/goldbarth/EscapeRoom2.0) | C++ | Windows console reimplementation with English menus |
| [EscapeRoom3.0](https://github.com/goldbarth/EscapeRoom3.0) | Rust | Early menu prototype; gameplay is not implemented |

## Reference

The cursor-visibility helper in `cwtr.cpp` credits [this Stack Overflow answer](https://stackoverflow.com/questions/18028808/remove-blinking-underscore-on-console-cmd-prompt).
