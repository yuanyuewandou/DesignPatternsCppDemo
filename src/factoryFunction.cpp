/*设计模式
 * 工厂方法模式
 * 解决了简单工厂不符合开闭原则的缺点
 * 缺点：
 *  1 类的个数越来越多，增加维护成本
 * 使用场景：
 *    客户端不知道它所需要的对象的类
 *    抽象工厂通过其子类来创建哪个对象
 */

#include<iostream>
using namespace std;
#include "simplefactory.cpp"
//抽象水果工厂
class AbstractFruitFactory
{
    public:
        virtual AbstractFruit* CreateFruit() = 0;
};

//具体的苹果工厂
class AppleFruitFactory :public AbstractFruitFactory
{
    public:
        virtual AbstractFruit* CreateFruit()
        {
           return new Apple();
        }
};

//具体的香蕉工厂
class BananaFruitFactory :public AbstractFruitFactory
{
    public:
        virtual AbstractFruit* CreateFruit()
        {
           return new Banana();
        }
};

