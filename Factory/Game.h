#include <memory>
using std::shared_ptr;
//定义四个方向枚举
enum Direction
{ North,South,East,West };

//定义游戏组件基类
class MapSite
{
public:
    virtual void Enter() = 0;
};

//房间类
class Room : public MapSite
{
public:
    //使用房间号构造
    Room(int no)
        :num(no){ }
    //获取该方向的组件（墙壁或门）
    shared_ptr<MapSite> GetSite(Direction) const;
    //设置该方向的组件
    void SetSite(Direction);
private:
    //房间号
    int num;
};