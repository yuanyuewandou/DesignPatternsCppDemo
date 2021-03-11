/* 小鱼号的代码日志
 * 设计模式
 * 职责链模式
 * 使用多个对象都有机会处理请求
 * 从而避免请求的发送和接受之间的耦合关系
 * 将这个对象连成一条链，并沿着这条链传递该请求
 * 知道有一个对象处理它为止
 * 实例：
 * 学校采购金额审批流程
 *  < 3000 系主任审批
 *  3000 - 5000 学院主任审批
 *  5000 - 30000 副校长审批
 *  30000 - 30000000 校长审批
 *  > 30000000 都没办法审批
 */

#include<iostream>
#include<string>
using namespace std;

///请求类
class PurchaseRequeset
{
public:
    PurchaseRequeset(int price)
    {
        m_price = price;
    }
    int getPrice()
    {
        return m_price;
    }
private:
    int m_price; //审批金额
};

///请求的处理者
class Approver
{
public:
    Approver(string name)
    {
        m_name = name;
    }
    void setNextApprover(Approver* nextApprover)
    {
        m_nextApprover = nextApprover;
    }
    ///处理请求
    virtual void processRequest(PurchaseRequeset req)
    {
        cout << "can not process Requese" << endl;
    }
protected:
    Approver* m_nextApprover; ///下一个处理者
    string m_name;
};

///系主任 级别的处理者
class DepartmentApprover : public Approver
{
public:
    DepartmentApprover(string name) :
        Approver(name)
    {

    }
    void processRequest(PurchaseRequeset req)
    {
         int price = req.getPrice();
        if(price < 3000)
        {
            cout << "name:" << m_name << " process request $:" << price << endl;
        }
        else
        {
            cout << "name:" << m_name << " can not process request" << endl;
            m_nextApprover->processRequest(req);
        }
    }
};

///学院主任 级别的处理者
class CollegeApprover : public Approver
{
public:
    CollegeApprover(string name) :
        Approver(name)
    {

    }
    void processRequest(PurchaseRequeset req)
    {
        int price = req.getPrice();
        if(price > 3000 && price < 5000)
        {
            cout << "name:" << m_name << " process request $:" << price << endl;
        }
        else
        {
            cout << "name:" << m_name << " can not process request" << endl;
            m_nextApprover->processRequest(req);
        }
    }
};

///副校长 级别的处理者
class ViceSchoolMasterApprover : public Approver
{
public:
    ViceSchoolMasterApprover(string name) :
        Approver(name)
    {

    }
    void processRequest(PurchaseRequeset req)
    {
        int price = req.getPrice();
        if(price > 5000 && price < 30000)
        {
            cout << "name:" << m_name << " process request $:" << price << endl;
        }
        else
        {
            cout << "name:" << m_name << " can not process request" << endl;
            m_nextApprover->processRequest(req);
        }
    }
};

///校长 级别的处理者
class SchoolMasterApprover : public Approver
{
public:
    SchoolMasterApprover(string name) :
        Approver(name)
    {

    }
    void processRequest(PurchaseRequeset req)
    {
        int price = req.getPrice();
        if(price > 30000 && price < 30000000)
        {
            cout << "name:" << m_name << " process request $:" << price << endl;
        }
        else
        {
            cout << "name:" << m_name << " can not process request" << endl;
            m_nextApprover->processRequest(req);
        }
    }
};
