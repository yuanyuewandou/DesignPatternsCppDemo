/*设计模式
 * 模板方法
 * 定义一个操作中算法的框架
 * 而将一些步骤延迟到子类中。
 * 使得子类可以在不改变一个算法的结构
 * 即可重定义该算法的某些特定步骤。
 * 现实中的例子
 * 网购的方法分为
 * 下单，付款，发货，收货。
 * 缺点:
 * 需要每一个基本方法的不同实现提供一个子类
 * 如果父类中可变的基本方法太多，将会导致类的个数
 * 增加，系统更加庞大，设计也更加抽象
 */
#include<iostream>
using namespace std;

class OnlineShopping
{
public:
    virtual void Order() = 0;
    virtual void Pay() = 0;
    virtual void SendGoods() = 0;
    virtual void RecvGoods() = 0;
    void shopping()
    {
        Order();
        Pay();
        SendGoods();
        RecvGoods();
    }
};

class JDOnlineShopping :public OnlineShopping
{
public:
    void Order()
    {
        cout << "jd order" << endl;
    }
    void Pay()
    {
        cout << "wechat pay" << endl;
    }
    void SendGoods()
    {
        cout << "jd logistics send googs" << endl;
    }
    void RecvGoods()
    {
        cout << "recv goods from jd logistics" << endl;
    }
};

class TaoBaoOnlineShopping :public OnlineShopping
{
public:
    void Order()
    {
        cout << "tmall order" << endl;
    }
    void Pay()
    {
        cout << "zhifubao pay" << endl;
    }
    void SendGoods()
    {
        cout << "cainiao logistics send googs" << endl;
    }
    void RecvGoods()
    {
        cout << "recv goods from cainiao logistics" << endl;
    }
};
