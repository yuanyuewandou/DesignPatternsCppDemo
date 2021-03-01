/* 小鱼号的代码日志
 * 设计模式
 * 模板方法
 * 现实例子：
 * 打豆浆的步骤
 *  1 选原料，2加配料，3浸泡，4打磨
 * 原味豆浆 什么都不加
 * 红豆豆浆 需要加红豆
 * 花生豆浆 需要加花生
 * ...
 * 加了不同的配料浸泡时间可能不同。。
*/

#include<iostream>
using namespace std;

//抽象的豆浆
class AbsSoyaMilk
{
public:
    //制作豆浆
    void make()
    {
        select();
        add();
        soak();
        beat();
    }
protected:
    virtual void add() = 0; //2加配料
    virtual void soak() = 0; //3 浸泡
private:
    //1选原料
    void select()
    {
        cout << "select perfect soybeab" << endl;
    }
    //4打豆浆
    void beat()
    {
         cout << "start beat soyamilk" << endl;
    }
};

//原味豆浆
class OriginalSoyaMilk : public AbsSoyaMilk
{
    void add()
    {
        cout << "add nothing " << endl;
    }
    void soak()
    {
        cout << "soak 1 hour " << endl;
    }
};

//红豆豆浆
class RedBeansSoyaMilk : public AbsSoyaMilk
{
    void add()
    {
        cout << "add read beans " << endl;
    }
    void soak()
    {
        cout << "soak 1.5 hour " << endl;
    }
};

//花生豆浆
class PeanutSoyaMilk : public AbsSoyaMilk
{
    void add()
    {
        cout << "add Peanut " << endl;
    }
    void soak()
    {
        cout << "soak 1.8 hour " << endl;
    }
};







