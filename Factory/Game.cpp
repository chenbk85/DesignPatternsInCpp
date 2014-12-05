//实现基础组件的方法
#include "Game.h"

int Room::getnum()
{
    static int num = 0;
    return ++num;
}

shared_ptr<MapSite> Room::GetSite(Direction d) const
{
    return sites.at(d);
}

void Room::SetSite(Direction d,  shared_ptr<MapSite> s)
{
    sites.at(d) = s;
}

void Room::Enter()
{
    std::cout << "进入房间：" + num << std::endl;
}
void Wall::Enter()
{
    std::cout << "碰壁！" << std::endl;
}

void Door::Enter()
{
    if(isopen)
        std::cout << "进入一扇门" << std::endl;
    else
        std::cout << "打开一扇门" << std::endl;
}

shared_ptr<Room> Door::GetOther(shared_ptr<Room>& other) const
{
    if(this->lhs == other)
        return this->rhs;
    else if(this->rhs == other)
        return this->lhs;
    else
        return nullptr;
}






