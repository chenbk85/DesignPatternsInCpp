#include <iostream>
#include <string>
#include <array>
#include <vector>

using namespace std;
int main()
{
    //我操哦哦及解决
    vector<char> v;
    for(int i = 0;i < 10;i++)
        v.push_back(i);
    for(char c : v)
        cout << c << endl;
    return 0;
}
