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
 * 实例：
 * 咖啡点单
 * 单品咖啡：美式咖啡，意大利咖啡
 * 咖啡添加的风味：巧克力风味，牛奶风味 豆浆风味
 *
 *
*/
#include<iostream>
#include<string>
using namespace std;

class Drink
{
public:
    void setDesc(string strDesc)
    {
        m_strDesc = strDesc;
    }
    void setPrice(int price)
    {
        m_price = price;
    }
    int getPrice()
    {
        return m_price;
    }
    string getDesc()
    {
        return m_strDesc;
    }
    ///计算费用抽象函数
    virtual int cost() = 0;
public:
    string m_strDesc;
    int m_price;
};

class Coffee:public Drink
{
public:
    int cost()
    {
        return getPrice();
    }

};

///意大利咖啡
class EspressoCoffee:public Coffee
{
public:
    EspressoCoffee()
    {
        setDesc("Espress Coffee");
        setPrice(50);
    }
};

///美式咖啡
class LongBlackCoffee:public Coffee
{
public:
    LongBlackCoffee()
    {
        setDesc("LongBlack Coffee");
        setPrice(45);
    }
};

///咖啡
class ShortBlackCoffee:public Coffee
{
public:
    ShortBlackCoffee()
    {
        setDesc("ShortBlack Coffee");
        setPrice(45);
    }
};

///咖啡的调味 装饰类
class FlavorCoffee:public Drink
{
public:
    FlavorCoffee(Drink* drink)
    {
        m_drink = drink;
    }
    int cost()
    {
        ///自己的调味的价格 + 单品咖啡的价格
        return getPrice() + m_drink->cost();
    }
private:
    Drink* m_drink;
};


///巧克力 咖啡的调味 装饰类
class ChocolateFlavorCoffee:public FlavorCoffee
{
public:
    ChocolateFlavorCoffee(Drink* drink):FlavorCoffee(drink)
    {
        setPrice(5);
        setDesc("chocolate flavor coffee price: " + std::to_string(getPrice()) + " " + drink->getDesc() );
    }
};

///牛奶 咖啡的调味 装饰类
class MilkFlavorCoffee:public FlavorCoffee
{
public:
    MilkFlavorCoffee(Drink* drink):FlavorCoffee(drink)
    {
        setPrice(6);
        setDesc("milk flavor coffee  price: " + std::to_string(getPrice()) + " " + drink->getDesc() );
    }
};

///豆浆 咖啡的调味 装饰类
class SoyFlavorCoffee:public FlavorCoffee
{
public:
    SoyFlavorCoffee(Drink* drink):FlavorCoffee(drink)
    {
        setPrice(4);
        setDesc("soy flavor coffee  price: " + std::to_string(getPrice()) + " " + drink->getDesc() );
    }
};










