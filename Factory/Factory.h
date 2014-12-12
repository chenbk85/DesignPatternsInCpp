/*定义迷宫抽象工厂
* 以及几个具体工厂类*/

#include "Game.h"
#include "DerivedSite.h"
using std::shared_ptr;

//定义迷宫工厂基类
//直接设为单例
class MazeFactory
{
public:
    MazeFactory() = default;
    //产生不同墙和门的虚拟工厂方法
    virtual  shared_ptr<Wall> MakeWall() const;
    virtual  shared_ptr<Door> MakeDoor(shared_ptr<Room> l,shared_ptr<Room> r) const;
};

//定义具体的迷宫工厂1
//使用镜面墙壁和需要咒语的门
class EnchantedFactory : public MazeFactory
{
public:
    //产生自己的单例
    static EnchantedFactory& GetFactory();
    //重写产生门和墙的方法
    virtual shared_ptr<Wall> MakeWall() const override;
    virtual shared_ptr<Door> MakeDoor(shared_ptr<Room> l, shared_ptr<Room> r) const override;

private:
    EnchantedFactory() = default;
};

//具体工厂2
//使用反弹墙和无法打开的门
//（那估计这迷宫没啥用了。。。）
class UselessmazeFactory : public MazeFactory
{
public:
    //产生单例
    static UselessmazeFactory& GetFactory();
    //重写方法
    virtual shared_ptr<Wall> MakeWall() const override;
    virtual shared_ptr<Door> MakeDoor(shared_ptr<Room> l,shared_ptr<Room> r) const override;

private:
    UselessmazeFactory() = default;
};