/* 小鱼号的代码日志
 * 设计模式
 * 备忘录模式
 * 在不破坏封装性的前提下
 * 捕获一个对象的内部状态
 * 并在该对象之外保存这个状态
 * 这样以后可将对象恢复到原先保存的状态
 */

#include<iostream>
#include<list>
#include<map>
#include<vector>
using namespace std;

///备忘录对象 保存一些信息
class Memento
{
public:
    Memento(string state)
    {
        m_state = state;
    }
    string getState()
    {
        return m_state;
    }
private:
    string m_state;
};

///原始的对象 一些状态信息需要保存
class Originator
{
public:
    string getState()
    {
        cout << "current state" << m_state << endl;
        return m_state;
    }
    void setState(string strState)
    {
        cout << "changed state" << strState << endl;
        m_state = strState;
    }
    //保存状态对象 返回memento
    Memento* saveState()
    {
        return new Memento(m_state);
    }
    //通过备忘录恢复到原来的状态 从Memento获取
    void getSatetFromMemento(Memento* mem)
    {
        m_state = mem->getState();
        cout << "restore state" << m_state << endl;
    }
private:
    string m_state;
};

///负责保存多个多种备忘录对象
class Caretaker
{
public:
    void add(Memento* mem)
    {
        m_vMem.push_back(mem);
    }

    Memento* get(unsigned int index)
    {
        if(index < m_vMem.size())
            return m_vMem[index];
        else
            return nullptr;
    }
private:
    vector<Memento*> m_vMem;
};
