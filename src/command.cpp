/*设计模式
 *命令模式
 * 将一个请求封装一个对象
 * 从而让我们可用不同的请求
 * 对客户进行参数化
 * 命令模式可以将请求发送者和接收者完全解耦
 *
 */
#include<iostream>
#include<queue>
using namespace std;

//协议处理类
class HandleClientProtocol
{
 public:
    void AddMoney() //给玩家增加金钱
    {
        cout << "player add money" << endl;
    }

    void AddDiamond() //给玩家增加钻石
    {
        cout << "player add diamond" << endl;
    }

    void AddEquipment() //给玩家增加装备
    {
        cout << "player add Equipment" << endl;
    }

    void AddLevel() //给玩家升级
    {
        cout << "player add level" << endl;
    }
};

//协议命令接口
class AbstractCommand
{
public:
    virtual void handle() = 0;
};

//处理增加金币的请求
class AddMoneyCommand:public AbstractCommand
{
public:
    AddMoneyCommand(HandleClientProtocol* protocol)
    {
        m_pProtocol = protocol;
    }
    void handle()
    {
        m_pProtocol->AddMoney();
    }
public:
    HandleClientProtocol* m_pProtocol;
};

//处理增加钻石的请求
class AddDiamondCommand:public AbstractCommand
{
public:
    AddDiamondCommand(HandleClientProtocol* protocol)
    {
        m_pProtocol = protocol;
    }
    void handle()
    {
        m_pProtocol->AddDiamond();
    }
public:
    HandleClientProtocol* m_pProtocol;
};

//处理增加装备的请求
class AddEquipmentCommand:public AbstractCommand
{
public:
    AddEquipmentCommand(HandleClientProtocol* protocol)
    {
        m_pProtocol = protocol;
    }
    void handle()
    {
        m_pProtocol->AddEquipment();
    }
public:
    HandleClientProtocol* m_pProtocol;
};

//处理升级的请求
class AddLevelCommand:public AbstractCommand
{
public:
    AddLevelCommand(HandleClientProtocol* protocol)
    {
        m_pProtocol = protocol;
    }
    void handle()
    {
        m_pProtocol->AddLevel();
    }
public:
    HandleClientProtocol* m_pProtocol;
};


class GameServer
{
public:
    void addRequest(AbstractCommand* command)
    {
        m_qCommand.push(command);
    }

    void startHandle()
    {
        while(!m_qCommand.empty())
        {
            AbstractCommand* command = m_qCommand.front();
            command->handle();
            m_qCommand.pop();
        }
    }
public:
    queue<AbstractCommand*> m_qCommand;
};


