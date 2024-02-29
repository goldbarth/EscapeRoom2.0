//
// Created by goldbarth on 07.09.2023.
//

#ifndef ESCAPEROOM2_0_PLAYER_H
#define ESCAPEROOM2_0_PLAYER_H

#include "Game.h"
#include "IObject.h"
#include "Key.h"

class Game;
class Room;
class Key;

class Player : public IObject
{
public:
    Player(Game& game, Room& room, Key& key);
    virtual ~Player() = default;
    
    void Initialize(const char& object) override;
    
    void UpdatePos(const int& x, const int& y, const char& symbol) const;
    void Move(const char& player);

    bool HasKey();
    
    void SetKeyIsCollected(const bool& value) { keyIsCollected = value; }

private:
    std::unique_ptr<Game> pGame;
    std::unique_ptr<Room> pRoom;
    std::unique_ptr<Key> pKey;

    static void PlayStopSound();
    
    void SetPos(const char& symbol) const;
    void SetRandomPosition() override;

    bool IsThisPosKeyPos() const;
    bool IsNotAtRightWall(const int& x, const int& y) const;
    static bool IsNewPosWall(const int& x, const int& y);
    
    bool keyIsCollected;
};

#endif //ESCAPEROOM2_0_PLAYER_H
