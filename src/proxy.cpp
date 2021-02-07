/*设计模式
 *  代理模式
 *  提供一种代理来控制对其他对象的访问
*/
#include<iostream>
using namespace std;

class AbstractCommonInterface
{
    virtual void run() = 0;
};

class MySystem :public AbstractCommonInterface
{
public:
    virtual void run()
    {
        cout << "system run" << endl;
    }
};

//必须要有权限验证，不是所有人都能来启动系统，需要提供用户名和密码

class MySystemProxy :public AbstractCommonInterface
{
    MySystemProxy(string userName,string password)
    {
        mUserName = userName;
        mPassword = password;
        pSystem = new MySystem;
    }
    virtual void run()
    {
        cout << "proxy run" << endl;
        if(checkUserNameAndPassword())
            pSystem->run();
        else
            cout << "system check error" << endl;
    }
    ~MySystemProxy()
    {
       if(pSystem != nullptr)
           delete pSystem;
    }
    bool checkUserNameAndPassword()
    {
        return true;
    }
public:
    MySystem *pSystem;
    string mUserName;
    string mPassword;
};
