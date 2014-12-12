#include "Factory.h"

shared_ptr<Door> MazeFactory::MakeDoor(shared_ptr<Room> l,shared_ptr<Room> r) const
{
    return std::make_shared<Door>(l,r);
}

shared_ptr<Wall> MazeFactory::MakeWall() const
{
    return std::make_shared<Wall>();
}

shared_ptr<Door> EnchantedFactory::MakeDoor(shared_ptr<Room> l, shared_ptr<Room> r) const
{
    return std::make_shared<EnchantedDoor>(l,r,"fuck!");
}

shared_ptr<Wall> EnchantedFactory::MakeWall() const
{
    return std::make_shared<MirrorWall>();
}

shared_ptr<Door> UselessmazeFactory::MakeDoor(shared_ptr<Room> l, shared_ptr<Room> r) const
{
    return std::make_shared<NotOpenDoor>(l,r);
}

shared_ptr<Wall> UselessmazeFactory::MakeWall() const
{
    return std::make_shared<ReboundWall>();
}

EnchantedFactory& EnchantedFactory::GetFactory()
{
    static EnchantedFactory enchantedFactory;
    return enchantedFactory;
}

UselessmazeFactory& UselessmazeFactory::GetFactory()
{
    static UselessmazeFactory uselessmazeFactory;
    return uselessmazeFactory;
}