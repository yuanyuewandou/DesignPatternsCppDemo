/*设计模式
 * 抽象工厂方法模式
 */

#include<iostream>
using namespace std;

//抽象的苹果
class AbstractApple
{
public:
    virtual void ShowName() = 0;
};
//中国苹果
class ChinaApple :public AbstractApple
{
public:
    virtual void ShowName()
    {
        cout << "china apple!" << endl;
    }
};

//美国苹果
class USAApple :public AbstractApple
{
public:
    virtual void ShowName()
    {
        cout << "USA apple！" << endl;
    }
};

//日本苹果
class JapanApple :public AbstractApple
{
public:
    virtual void ShowName()
    {
        cout << "Japan apple！" << endl;
    }
};

//抽象的香蕉
class AbstractBanana
{
public:
    virtual void ShowName() = 0;
};

//中国香蕉
class ChinaBanana :public AbstractBanana
{
public:
    virtual void ShowName()
    {
        cout << "china Banana" << endl;
    }
};

//美国香蕉
class USABanana :public AbstractBanana
{
public:
    virtual void ShowName()
    {
        cout << "USA Banana" << endl;
    }
};

//日本香蕉
class JapanBanana :public AbstractBanana
{
public:
    virtual void ShowName()
    {
        cout << "Japan Banana" << endl;
    }
};

//抽象工厂 针对产品族
class AbstractFactory
{
public:
    virtual AbstractApple* CreateApple() = 0;
    virtual AbstractBanana* CreateBanana() = 0;
};

class ChinaFactory: public AbstractFactory
{
public:
    virtual AbstractApple* CreateApple()
    {
        return new ChinaApple;
    }
    virtual AbstractBanana* CreateBanana()
    {
        return new ChinaBanana;
    }
};

class USAFactory: public AbstractFactory
{
public:
    virtual AbstractApple* CreateApple()
    {
        return new USAApple;
    }
    virtual AbstractBanana* CreateBanana()
    {
        return new USABanana;
    }
};

class JapanFactory: public AbstractFactory
{
public:
    virtual AbstractApple* CreateApple()
    {
        return new JapanApple;
    }
    virtual AbstractBanana* CreateBanana()
    {
        return new JapanBanana;
    }
};




