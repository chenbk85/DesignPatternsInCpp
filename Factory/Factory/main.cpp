#include <iostream>
#include <string>
#include <array>
#include <vector>
//#include "Game.h"
#include "Factory.h"
//#include "DerivedSite.h"
using namespace std;

int main()
{
    EnchantedFactory enchantedFactory = EnchantedFactory::GetFactory();
    shared_ptr<Maze> maze = Maze::CreateMaze(enchantedFactory);
    maze->ShowRoom(std::cout);
    return 0;
}
