/* 小鱼号的代码日志
 * 设计模式
 * 中介者模式
 * 多个类相互耦合形成网状结构
 * 中介者模式将网状结构分解为星型结构进行解耦
 * 减少类间依赖，降低耦合
 * 中介者承担了较多的责任，中介者出了问题，
 * 整个系统就会有问题
 * 具体场景：
 * 智能家居开启麦克风之后 自动打开电视关灯
 */

#include<iostream>
#include<list>
#include<map>
using namespace std;

class Colleague;

class Mediator
{
public:
    virtual void reg(string name,Colleague* coll) = 0;
    virtual void getMsg(int stateChanged,string name) = 0;
    virtual void sendMsg() = 0;
};

///抽象的同事类
class Colleague
{
public:
    Colleague(Mediator* mediator,string name)
    {
        m_mediator = mediator;
        m_name = name;
        ///创建对象时 将自己放入到具体的中介者管理
        mediator->reg(name,this);
    }
    virtual ~Colleague()
    {

    }
    Mediator* getMediator()
    {
        return m_mediator;
    }
protected:
    Mediator* m_mediator;
    string m_name;
};

///具体的同事类 智能电视
class SmartTV : public Colleague
{
public:
    SmartTV(Mediator* mediator,string name):
        Colleague(mediator,name)
    {
    }
    void OpenTV()
    {
        cout << "open smart tv" << endl;
    }
    void CloseTV()
    {
        cout << "close smart tv" << endl;
    }
};

///具体的同事类 智能灯
class SmartLight : public Colleague
{
public:
    SmartLight(Mediator* mediator,string name):
        Colleague(mediator,name)
    {
    }
    void OpenLight()
    {
        cout << "open Smart Light" << endl;
    }
    void CloseLight()
    {
        cout << "close Smart Light" << endl;
    }
};

///具体的同事类 智能麦克风
class SmartMic : public Colleague
{
public:
    SmartMic(Mediator* mediator,string name):
        Colleague(mediator,name)
    {

    }
    void OpenMic()
    {
        cout << "open Smart Mic" << endl;
        getMediator()->getMsg(1,m_name);
    }
    void CloseMic()
    {
        cout << "close Smart Mic" << endl;
    }
};


///具体的智能家居中介
class SmartHouseMediator :public Mediator
{
protected:
    virtual void reg(string name,Colleague* coll)
    {
        m_colleagueMap.insert(make_pair(name,coll));
    }

    ///中介者模式的核心 中介者协调各个具体的同事对象完成 需求
    virtual void getMsg(int stateChanged,string name)
    {
        ///接收不同的同事的消息按照需求完成对其他同事的操作
        //例如：麦克风开启之后 TV打开 光灯
        if(name == "SmartMic")
        {
            if(stateChanged == 1) //mic open
            {
                dynamic_cast<SmartTV*>(m_colleagueMap["SmartTV"])->OpenTV();
                dynamic_cast<SmartLight*>(m_colleagueMap["SmartLight"])->CloseLight();
            }
        }
    }
    virtual void sendMsg()
    {

    }
private:
    ///中介所管理的同事集合（各种智能家电）
    map<string,Colleague*> m_colleagueMap;
};

///后续购置其他智能家电。。。
