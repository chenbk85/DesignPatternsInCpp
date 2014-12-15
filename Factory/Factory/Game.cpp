//实现基础组件的方法
#include "Game.h"
#include "Factory.h"

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

unsigned int Room::GetRoomNum()
{
    return static_cast<unsigned int>(this->num);
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

shared_ptr<Maze> Maze::CreateMaze(MazeFactory& factory)
{
    //先产生一个空的迷宫指针
    shared_ptr<Maze> tmp = std::make_shared<Maze>();
    //使用工厂产生特定组件
    //两个不同的房间
    shared_ptr<Room> r1 = std::make_shared<Room>();
    shared_ptr<Room> r2 = std::make_shared<Room>();
    //然后是一个门
    shared_ptr<Door> d = factory.MakeDoor(r1,r2);
    //然后给迷宫加上房间
    tmp->AddRoom(r1);
    tmp->AddRoom(r2);
    //再使用工厂产生四面墙
    r1->SetSite(Direction::North, d);
    r1->SetSite(Direction::East, factory.MakeWall());
    r1->SetSite(Direction::West , factory.MakeWall());
    r1->SetSite(Direction::South , factory.MakeWall());
    r2->SetSite(Direction::South , d);
    r2->SetSite(Direction::East , factory.MakeWall());
    r2->SetSite(Direction::West , factory.MakeWall());
    r2->SetSite(Direction::North , factory.MakeWall());
    //返回建造好的迷宫
    return tmp;
}

void Maze::ShowRoom(std::ostream& out)
{
    for(auto c : this->rooms)
        out << c->GetRoomNum() << "\n";
}

void Maze::AddRoom(shared_ptr<Room> room)
{
    rooms.push_back(room);
}


