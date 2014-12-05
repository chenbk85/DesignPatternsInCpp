#include "DerivedSite.h"
void MirrorWall::Enter()
{
    std::cout << "被反射" << std::endl;
}

void ReboundWall::Enter()
{
    std::cout << "被反弹" << std::endl;
}

bool EnchantedDoor::check() const
{
    std::string fuck;
    std::cin >> fuck;
    return !fuck.compare(this->spell);
}

void EnchantedDoor::SetSpell(string const & s)
{
    this->spell = s;
}

void EnchantedDoor::Enter()
{
    if(check())
        std::cout << "进入" << std::endl;
    else
        std::cout << "咒语无效" << std::endl;
}

void NotOpenDoor::Enter()
{
    std::cout << "无法打开！" << std::endl;
}