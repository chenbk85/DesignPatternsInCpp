/*定义游戏基本组件部分
包括墙壁、门、房间
 */
#pragma once
#include <memory>
#include <vector>
#include <map>
#include <iostream>

using std::shared_ptr;
//定义四个方向枚举
enum Direction
{ North,South,East,West };

//定义游戏组件基类
class MapSite
{
public:
    virtual void Enter() = 0;
    virtual ~MapSite() = default;
};

//房间类
class Room : public MapSite
{
public:
    //拷贝控制部分
    Room()
    {
        num = Room::getnum();
    }
    virtual ~Room() = default;
    //不允许拷贝赋值
    Room(const Room&) = delete;
    Room& operator=(const Room&) = delete;

    //获取该方向的组件（墙壁或门）
    shared_ptr<MapSite> GetSite(Direction) const;
    //设置该方向的组件
    void SetSite(Direction,shared_ptr<MapSite>);
    //实现Enter方法
    virtual void Enter() override;
private:
    //用于产生新的房间号
    static int getnum();
    //房间号
    int num;
    //用于存储房间四面的墙或者门
    std::array<shared_ptr<MapSite>,4> sites;
};

//墙壁类
class Wall : public  MapSite
{
public:
    //默认构造
    Wall() = default;
    //默认析构
    virtual ~Wall() = default;
    //默认赋值等
    Wall(const Wall&) = default;
    //重写Enter
    virtual void Enter() override;
};

//门类
class Door : public MapSite
{
public:
    //使用两个房间构造
    Door(shared_ptr<Room> l,shared_ptr<Room> r)
            :isopen(false),lhs(l),rhs(r){ }
    //析构
    virtual ~Door() = default;
    //返回另一个房间
    shared_ptr<Room> GetOther(shared_ptr<Room>&) const;
    //重写Enter
    virtual void Enter() override;
private:
    //判断是否打开
    bool isopen;
    //门的两侧
    shared_ptr<Room> lhs;
    shared_ptr<Room> rhs;
};

//整个迷宫类
//用来产生迷宫
class Maze
{
public:
    Maze() = default;
    //使用一个工厂产生迷宫的各个房间
    void CreateMaze();
    //显示所有房间信息
    void ShowRoom(std::ostream&);
private:
    //保存所有房间指针
    std::vector<shared_ptr<Room>> rooms;
};
