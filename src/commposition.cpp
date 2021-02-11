/*小鱼号的代码日志
 * C++设计模式
 *  组合模式
 *  创建了对象组的树形结构
 *  将对象组合成树状结构以表示
 *  整体-部分的层次关系
 *  要解决的问题：
 *  当我们要处理的对象可以是
 *  生成一颗树形结构，而我们
 * 要对树上的节点和叶子节点进行操作时
 * 它能够提供一致的方式，而不同考虑
 * 它时节点还是叶子
*/
#include<iostream>
#include<string>
#include<list>
using namespace std;
///组织单位
class OrganizationComponent
{
public:
    OrganizationComponent(string strName,string strDesc)
    {
        m_strName = strName;
        m_strDesc = strDesc;
    }
    virtual string showInfo() = 0;
    virtual void add(OrganizationComponent* component)
    {
    }

    virtual void remove(OrganizationComponent* component)
    {
    }
protected:
    void setName(const string& strName)
    {
        m_strName = strName;
    }
    string getName() const
    {
        return m_strName;
    }
    void setDesc(const string&  strDesc)
    {
        m_strDesc = strDesc;
    }
    string getDesc() const
    {
        return m_strDesc;
    }
private:
    string m_strName;
    string m_strDesc;
};

///组织单位 - 大学
class University :public OrganizationComponent
{
public:
    University(string strName,string strDesc)
            :OrganizationComponent(strName,strDesc)
    {

    }
    virtual void add(OrganizationComponent* component)
    {
        m_comList.push_back(component);
    }
    virtual void remove(OrganizationComponent* component)
    {
        m_comList.remove(component );
    }
    virtual string showInfo()
    {
        cout << "university name: " << getName() << " desc: " << getDesc() << endl;
        for(auto it = m_comList.begin();it!=m_comList.end();it++)
        {
            (*it)->showInfo();
        }

    }
private:
    list<OrganizationComponent*> m_comList;
};

///组织单位 - 学院
class College :public OrganizationComponent
{
public:
    College(string strName,string strDesc)
            :OrganizationComponent(strName,strDesc)
    {

    }
    virtual void add(OrganizationComponent* component)
    {
        m_comList.push_back(component);
    }
    virtual void remove(OrganizationComponent* component)
    {
        m_comList.remove(component );
    }
    virtual string showInfo()
    {
        cout << "College name: " << getName() << " desc: " << getDesc() << endl;
        for(auto it = m_comList.begin();it!=m_comList.end();it++)
        {
            (*it)->showInfo();
        }

    }
private:
    list<OrganizationComponent*> m_comList;
};

///组织单位 - 系 最小单位
class Department :public OrganizationComponent
{
public:
    Department(string strName,string strDesc)
            :OrganizationComponent(strName,strDesc)
    {

    }
    virtual string showInfo()
    {
        cout << "Department name: " << getName() << " desc: " << getDesc() << endl;
    }
};




