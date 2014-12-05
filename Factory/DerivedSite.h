/*定义继承自Room、Door以及Wall的迷宫组件类
定义各自的独特性质
 */
#pragma once

#include <string>
#include "Game.h"
using std::string;

//定义一个镜面墙壁
class MirrorWall : public Wall
{
    MirrorWall()
            : Wall(){}
    ~MirrorWall() = default;
    virtual void Enter() final;
};

//一个可以反弹的墙壁
class ReboundWall : public Wall
{
    ReboundWall()
            :Wall(){ }
    ~ReboundWall() = default;
    virtual void Enter() final;
};
//定义一个施法的门
//需要咒语才可以打开
class EnchantedDoor : public Door
{
public:
    EnchantedDoor(shared_ptr<Room> lhs,shared_ptr<Room> rhs,const string& s)
            :Door(lhs,rhs),spell(s){ }
    ~EnchantedDoor() = default;
    //重写进入方法
    virtual void Enter() final;
    //设置咒语
    void SetSpell(const string&);
private:
    //定义一个用于检查咒语的方法
    bool check() const;
    //一个简单咒语
    string spell;
};

//一个打不开的门
class NotOpenDoor : public Door
{
public:
    NotOpenDoor(shared_ptr<Room> lhs,shared_ptr<Room> rhs)
        : Door(lhs,rhs) { }
    ~NotOpenDoor() = default;
    virtual void Enter() final;
};