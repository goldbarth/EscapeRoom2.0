//
// Created by goldbarth on 07.09.2023.
//

#ifndef ESCAPEROOM2_0_EXIT_H
#define ESCAPEROOM2_0_EXIT_H


#include "IObject.h"

class Room;

class Exit : public IObject
{
public:
    Exit(Room& room);
    
    void Initialize(const char& object) override;
    void DrawExit(const bool& open) const;

private:
    std::unique_ptr<Room> pRoom;
    
    void SetRandomPosition() override;
};

#endif //ESCAPEROOM2_0_EXIT_H
