/*设计模式
 *  装饰器模式
 *  又叫包装模式
 * 通过一种对客户端透明的方式
 * 来扩展对象功能，
 * 是继承关系的一种替代
 * 运行时动态地给一个类增加功能
 * 相比生成子类更为灵活
 * (消除重复代码 & 减少子类个数)
 *  继承和组合
 * 主体类在多个方向上的扩展功能
*/

#include<iostream>
using namespace std;

class AbstractPlayer
{
public:
    virtual void ShowStatus() = 0;
public:
    int m_Hp;
    int m_Mp;
};

class  PlayerA:public AbstractPlayer
{
public:
    ///玩家初始状态
    PlayerA()
    {
        m_Hp = 0;
        m_Mp = 0;
    }
    virtual void ShowStatus()
    {
        cout << "hp" << m_Hp << endl;
        cout << "mp" << m_Mp << endl;
    }
};

//玩家增加了某种装备（装饰）
///抽象装备（装饰）
class AbstractEquipment :public AbstractPlayer
{
public:
    AbstractEquipment(AbstractPlayer* pPlayer)
    {
        m_player = pPlayer;
    }
    //不实现
    virtual void ShowStatus()
    {

    }
public:
    AbstractPlayer* m_player;
};

class AK47Equipment : public AbstractEquipment
{
public:
    AK47Equipment(AbstractPlayer* pPlayer) : AbstractEquipment(pPlayer)
    {

    }
    void addAk47Equiepment()
    {
        //添加AK47的加成
        m_Hp = m_player->m_Hp + 30;
        m_Mp = m_player->m_Mp + 30;
        delete m_player;
    }
    virtual void ShowStatus()
    {
        addAk47Equiepment();
        cout << "hp" << m_Hp << endl;
        cout << "mp" << m_Mp << endl;
    }
};
