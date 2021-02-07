/*设计模式
 * 策略模式
 * 定义了一些列算法，将每一个算法封装起来
 * 而且是他们可以相互替换。
 * 策略模式让算法独立于使用它的
 * 客户而独立变化
 * 现实中的例子：
 * 吃鸡游戏中的人物
 * 初始武器策略是拳
 * 捡到一把枪武器策略就是枪
 * 捡到一把刀武器策略就是刀
*/
#include<iostream>
using namespace std;

//武器策略
class WeaponStrategy
{
public:
    virtual void UseWeapon() = 0;
};

//匕首策略
class KnifeStrategy : public WeaponStrategy
{
public:
    void UseWeapon()
    {
        cout << "use knife"<< endl;
    }
};

//AK47策略
class AK47Strategy : public WeaponStrategy
{
public:
    void UseWeapon()
    {
        cout << "use AK 47"<< endl;
    }
};

class Character
{
public:
    void setWeapon(WeaponStrategy* weapon)
    {
        m_pWeaponStrategy   = weapon;
    }
    void useWeaponStrategy()
    {
        m_pWeaponStrategy->UseWeapon();
    }
public:
    WeaponStrategy* m_pWeaponStrategy;
};


