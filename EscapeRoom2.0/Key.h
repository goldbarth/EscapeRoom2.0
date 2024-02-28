//
// Created by goldbarth on 07.09.2023.
//

#ifndef ESCAPEROOM2_0_KEY_H
#define ESCAPEROOM2_0_KEY_H


#include <memory>
#include "IObject.h"
#include "Room.h"

class Room;

class Key : public IObject
{
public:
    explicit Key(Room& room);

    void Initialize(const char& object) override;

private:
    std::unique_ptr<Room> pRoom;

    void SetRandomPosition() override;
    void DrawKey(const char& key) const;
};

#endif //ESCAPEROOM2_0_KEY_H
