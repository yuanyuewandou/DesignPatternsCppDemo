/* 小鱼号的代码日志
 * 设计模式
 * 状态模式
 * 解决对象在多种状态转换时，需要对外输出不同的行为的问题。
 * 状态和行为时一一对应的
 * 当一个对象内在状态改变时，允许改变其行为.
 * 这个对象看起来像是改变了其类
 * 现实实例：
 * 抽奖的几种状态
 * 不能抽奖状态（需要先扣积分）
 * 可以抽奖（扣除了积分）
 * 领取奖品
 * 奖品领完了（活动结束）
 */

#include<iostream>
#include<list>
#include<map>
#include<stdlib.h>
#include "stateactivity.h"
using namespace std;

class Activity;
///抽奖状态抽象类
class State
{
public:
    State(Activity* act)
    {
        m_act = act;
    }
public:
    //扣除积分
    virtual void dedcutMoney() = 0;
    //是否抽中奖品
    virtual bool raffle() = 0;
    //发放奖品
    virtual void dispensePrize() = 0;
protected:
    Activity* m_act;
};


///不能抽奖的状态
class NoRaffleState : public State
{
public:
     NoRaffleState(Activity* act):State(act)
     {

     }
public:
    //扣除积分 将状态设置成可抽奖状态
    void dedcutMoney()
    {
        cout << "dedcut 50 and can raffle" << endl;
        m_act->setState(m_act->getCanRaffleState());
    }
    //是否抽中奖品 当前状态不能抽奖
    bool raffle()
    {
        cout << "can not raffle please dedcut first" << endl;
    }
    //发放奖品 前状态发放奖品
    void dispensePrize()
    {
        cout << "can not dispecse prize" << endl;
    }
};

///可以抽奖的状态
class CanRaffleState : public State
{
public:
     CanRaffleState(Activity* act):State(act)
     {

     }
public:
    //扣除积分
    void dedcutMoney()
    {
        cout << "dedcut 50 already" << endl;
    }

    //是否抽中奖品
    bool raffle()
    {
        cout << "hold on raffle" << endl;
        int a = rand() % 10;
        if(a %2 == 0)
        {
            m_act->setState(m_act->getDispenseRaffleState());
            cout << "congratulate" << endl;
            return true;
        }
        else
        {
            m_act->setState(m_act->getNoRaffleState());
            cout << "sorry" << endl;
            return false;
        }
    }

    //发放奖品
    void dispensePrize()
    {
        cout << "can not dispecse prize" << endl;
    }
};

///发放奖品的状态
class DispenseRaffleState : public State
{
public:
     DispenseRaffleState(Activity* act):State(act)
     {

     }
public:
    //扣除积分
    void dedcutMoney()
    {
        cout << "dedcut 50 already" << endl;
    }

    //是否抽中奖品
    bool raffle()
    {
        cout << "raffle already" << endl;
        return false;
    }

    //发放奖品
    void dispensePrize()
    {
        if(m_act->getPrizeCount() > 0)
        {
            m_act->setState(m_act->getNoRaffleState());
            cout << "take your prize" << endl;
        }
        else
        {
            m_act->setState(m_act->getRaffleOutState());
            cout << "sorry the prize is out" << endl;
        }
    }
};

///奖品发完了的状态 活动已经结束
class RaffleOutState : public State
{
public:
     RaffleOutState(Activity* act):State(act)
     {

     }
public:
    //扣除积分
    void dedcutMoney()
    {
        cout << "sorry prize already out activirt is over" << endl;
    }

    //是否抽中奖品
    bool raffle()
    {
        cout << "sorry prize already out activirt is over" << endl;
        return false;
    }

    //发放奖品
    void dispensePrize()
    {
        cout << "sorry prize already out activirt is over" << endl;
    }
};




