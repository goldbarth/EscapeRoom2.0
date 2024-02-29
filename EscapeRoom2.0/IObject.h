#ifndef OBJECT_H
#define OBJECT_H

class IObject
{
protected:
    ~IObject() = default;
    
public:
    virtual void Initialize(const char& object) = 0;
    virtual void SetRandomPosition() = 0;
    
    virtual int GetXPos() const { return xPos; }
    virtual int GetYPos() const { return yPos; }
    
    int xPos = 0;
    int yPos = 0;
};

#endif // !OBJECT_H
