//
// Created by goldbarth on 07.09.2023.
//

#ifndef ESCAPEROOM2_0_ROOM_H
#define ESCAPEROOM2_0_ROOM_H

#include <vector>

class Room
{
public:
    explicit Room() = default;
    ~Room() = default;

    int GetWidth() const { return width;}
    int GetHeight() const { return height;}

    void Initialize(const int& roomWidth, const int& roomHeight);

private:
    void SetRoomSize(const int& roomWidth, const int& roomHeight);
    void DrawRoom() const;

    std::vector<std::vector<int>> room;
    
    int width = 0;
    int height = 0;
};

#endif //ESCAPEROOM2_0_ROOM_H
