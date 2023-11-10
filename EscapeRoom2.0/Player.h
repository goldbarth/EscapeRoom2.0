//
// Created by goldbarth on 07.09.2023.
//

#ifndef ESCAPEROOM2_0_PLAYER_H
#define ESCAPEROOM2_0_PLAYER_H

#include "Game.h"
#include "Exit.h"
#include "Key.h"

class Game;
class Room;
class Key;

class Player
{
public:
    explicit Player(Game& game, Room& room, Key& key);

    void Initialize(const char& player);
    void UpdatePos(const int& x, const int& y, const char& symbol) const;
    void Move(const char& player);

    bool HasKey();

    int GetXPos() const { return xPos; }
    int GetYPos() const { return yPos; }

    void SetKeyIsCollected(const bool& value) { keyIsCollected = value; }

private:
    std::unique_ptr<Game> game;
    std::unique_ptr<Room> room;
    std::unique_ptr<Key> key;

    bool keyIsCollected;

    int xPos;
    int yPos;

    constexpr static int UP = 72;
    constexpr static int DOWN = 80;
    constexpr static int LEFT = 75;
    constexpr static int RIGHT = 77;

    static void PlayStopSound();
    static bool IsNewPosWall(const int& x, const int& y);

    void GetRandomStartPos();
    void SetPos(const char& symbol) const;

    bool IsThisPosKeyPos() const;
    bool IsNotAtRightWall(const int& x, const int& y) const;
};

#endif //ESCAPEROOM2_0_PLAYER_H
