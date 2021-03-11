/* 小鱼号的代码日志
 * 设计模式
 * 原型模式
 * 用原型实例指定创建对象的种类，并且
 * 通过拷贝这些原型，创建新的对象
 * 一个对象在创建另外一个可定制的对象
 * 无需知道创建的细节
 * 克隆羊
 */

#include<iostream>
#include<list>
using namespace std;

class Animal
{
public:
    Animal(string name,int age)
    {
        m_name = name;
        m_age = age;
    }
    Animal(const Animal& animal)
    {
        m_name = animal.m_name;
        m_age = animal.m_age;
    }
    void showInfo()
    {
        cout << "name:" << m_name << " age:" << m_age << endl;
    }
    virtual Animal* clone() = 0;
protected:
    string m_name;
    int m_age;
};

class Sheep:public Animal
{
public:
    Sheep(string name,int age) :Animal(name,age)
    {
    }
    Sheep(const Sheep& animal) :Animal(animal)
    {
    }
    Animal* clone()
    {
        return new Sheep(*this);
    }
};
