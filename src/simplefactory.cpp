/*设计模式
 * 简单工厂模式
 * 不想创建对象(避开new)
 * 传入参数，让工厂知道应该创建类型的对象
 *优点：
 * 1 客户端和具体类解耦
 * 2 不用考虑如何创建复杂的对象
 * 缺点：
 * 1简单工厂模式，创建新的对象需要修改源代码
 *  不符合开闭原则
 * 2 创建各种对象，职责过重，不符合单一职责原则
 * 场景：
 *  适合负责创建对象比较少
 *
*/
#include<iostream>
using namespace std;
//抽象水果
class AbstractFruit
{
  public:
    virtual void ShowName() = 0;
};
//苹果
class Apple :public AbstractFruit
{
public:
    virtual void ShowName()
    {
        cout << "i am apple" << endl;
    }
};

//香蕉
class Banana :public AbstractFruit
{
public:
    virtual void ShowName()
    {
        cout << "i am banana" << endl;;
    }
};

//水果工厂
class FruitFactory
{
    public:
    static AbstractFruit* CreateFruit(string strFruitName)
    {
        if(strFruitName == "apple")
        {
            return new Apple;
        }
        else if(strFruitName == "banana")
        {
            return new Banana;
        }
        else
        {
            return nullptr;
        }
    }
};


