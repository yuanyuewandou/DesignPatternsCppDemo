/*设计模式
 *  观察者模式用于建立对象与对象之间的依赖关系
 * 一个对象发生改变时将自动通知其他对象
 * 其他对象将相应做出反应
 * 在观察者模式中，发生改变的对象称为观察目标
 * 而被通知的对象成为观察者
 * 例子:
 * 几个英雄打boss
 * boss死了通知英雄停止攻击
*/

#include<iostream>
#include<list>
using namespace std;

//抽象的英雄  观察者
class AbstractHero
{
public:
    virtual void Update() = 0;
};

class HeroA :public AbstractHero
{
public:
    HeroA()
    {
        cout << "heroA a attract boss" << endl;
    }
    virtual void Update()
    {
         cout << "heroA stand by" << endl;
    }
};


class HeroB :public AbstractHero
{
public:
    HeroB()
    {
        cout << "hero B a attract boss" << endl;
    }
    virtual void Update()
    {
         cout << "heroB stand by" << endl;
    }
};


class HeroC :public AbstractHero
{
public:
    HeroC()
    {
        cout << "hero C a attract boss" << endl;
    }
    virtual void Update()
    {
         cout << "hero C stand by" << endl;
    }
};

//boss 观察目标抽象
class AbstractBoss
{
public:
    virtual void addHero(AbstractHero*) = 0; //添加观察者
    virtual void deleteHero(AbstractHero*) = 0; //删除观察者
    virtual void notify() = 0;//通知所有观察者
};

//boss 具体的观察目标
class BOSS :public AbstractBoss
{
public:
    virtual void addHero(AbstractHero* hero)
    {
        m_pHeroList.push_back(hero);
    }
    virtual void deleteHero(AbstractHero*hero)
    {
        m_pHeroList.remove(hero);
    }
    virtual void notify()
    {
        for(list<AbstractHero*>::iterator it = m_pHeroList.begin();
            it != m_pHeroList.end();it++)
        {
            (*it)->Update();
        }
    }
private:
    list<AbstractHero*> m_pHeroList;
};





