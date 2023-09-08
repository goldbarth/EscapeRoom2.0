//
// Created by goldbarth on 07.09.2023.
//

#ifndef ESCAPEROOM2_0_PLAYER_H
#define ESCAPEROOM2_0_PLAYER_H


class Game;
class Room;
class Key;

class Player
{
public:
    bool keyIsCollected;

    Player(Game* game, Room* room, Key* key);

    void DrawStartPos(char player);
    void UpdatePos(int x, int y, char symbol);

    void Move(char player);

    bool HasKey();

    void SetXPos(int pos);
    void SetYPos(int pos);
    int GetXPos();
    int GetYPos();


private:
    int xPos;
    int yPos;

    Game* game;
    Room* room;
    Key* key;

    void GetRandomStartPos();
    void SetPos(char player);
    void DrawNewPos(int x, int y, char symbol);
    void SetCursorPos(int x, int y);

    void RepaintEnvironment(int x, int y);
    void RepaintWall(int x, int y);
    void RepaintExit(int x, int y);
    void PlayBeep();

    bool ThisPosIsKeyPos();
    bool IsNewPosWall(int x, int y);
};


#endif //ESCAPEROOM2_0_PLAYER_H
