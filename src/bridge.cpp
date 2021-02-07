/*小鱼号的代码日志
 * c++ 设计模式
 *桥接模式
 * 将实现与抽象放在两个不同的类层次中
 * 使两个层次可以独立改变
 * 基于最小设计原则
 * 通过封装，聚合以及继承让不同的类承担
 * 不同的职责。主要特点是把抽象和行为实现
 * 分离开来
 * 保持各个部分的独立性以及应对他们功能的扩展
 */
#include<iostream>
using namespace std;

//行为实现的抽象类
class PhoneBrand
{
public:
    virtual void open() = 0;
    virtual void close() = 0;
    virtual void call() = 0;
};

class XiaomiPhone:public PhoneBrand
{
    virtual void open()
    {
        cout << "xiaomi phone open" << endl;
    }
    virtual void close()
    {
        cout << "xiaomi phone close" << endl;
    }
    virtual void call()
    {
        cout << "xiaomi phone call" << endl;
    }
};

class VivoPhone:public PhoneBrand
{
    virtual void open()
    {
        cout << "Vivo phone open" << endl;
    }
    virtual void close()
    {
        cout << "Vivo phone close" << endl;
    }
    virtual void call()
    {
        cout << "Vivo phone call" << endl;
    }
};

///桥接类
class Phone
{
public:
    Phone(PhoneBrand* brand)
    {
        m_brand = brand;
    }
private:
    PhoneBrand* m_brand;
public:
    void open() ///桥接 不同手机品牌的接口
    {
        m_brand->open();
    }
    void close()
    {
        m_brand->close();
    }
    void call()
    {
        m_brand->call();
    }
};

///抽象的定义
///折叠式的手机
class FoldePhone :public Phone
{
public:
    FoldePhone(PhoneBrand* brand)
        :Phone(brand)
    {
        cout << "FoldePhone " << endl;
    }
};

///旋转式的手机
class RotationPhone :public Phone
{
public:
    RotationPhone(PhoneBrand* brand)
        :Phone(brand)
    {
        cout << "RotationPhone " << endl;
    }
};








