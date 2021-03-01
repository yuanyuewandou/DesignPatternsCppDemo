/* 小鱼号的代码日志
 * 设计模式
 * 访问者模式
 * 我是歌手打分体系
 * 打分者：青年人 中年人
 * 打分体系：成功 失败
 * 打分体系升级版：成功 失败 待定
 * 如果一个系统有比较稳定的数据结构
 * 又有经常变化的功能需求
 * 那么访问者模式是比较合适的
 */

#include<iostream>
#include<list>
using namespace std;

class YoungMan;
class MiddleMan;
//打分体系
class gradeSys
{
public:
    virtual void getYoungManResult(YoungMan* yMan) = 0;
    virtual void getMiddleManResult(MiddleMan* MMan) = 0;
};

//成功的打分
class SuccessGradeSys :public gradeSys
{
public:
    void getYoungManResult(YoungMan* yMan)
    {
        cout << "YoungMan Score Success" << endl;
    }

    void getMiddleManResult(MiddleMan* MMan)
    {
        cout << "MiddleMan Score Success"<< endl;
    }
};

//失败的打分
class FailGradeSys :public gradeSys
{
public:
    void getYoungManResult(YoungMan* yMan)
    {
        cout << "YoungMan Score Fail" << endl;
    }

    void getMiddleManResult(MiddleMan* MMan)
    {
        cout << "MiddleMan Score Fail"<< endl;
    }
};

class Person
{
public:
    //visitor
    virtual void accept(gradeSys* grade) = 0;
};

///这里使用了双分派 在客户端中将具体状态作为参数传递给man(第一次分派）
///man调用了作为参数的具体方法中的一个，同时将自己（this)作为参数传入（第二次分派）
///妙 啊
class YoungMan : public Person
{
public:
    void accept(gradeSys* grade)
    {
        grade->getYoungManResult(this);
    }
};

class MiddleMan : public Person
{
public:
    void accept(gradeSys* grade)
    {
        grade->getMiddleManResult(this);
    }
};

///我是歌手节目组
class IAmSinger
{
public:
    //添加观众
    void attach(Person* p)
    {
        persons.push_back(p);
    }
    //观众有事离开了不参与投票打分
//    void detach(Person p)
//    {

//    }
    ///现实打分情况
    void display(gradeSys* grade)
    {
        for(auto p :persons)
        {
            p->accept(grade);
        }
    }
private:
    list<Person*> persons;
};


///打分体系升级 需要 有 待定状态
//待定的打分
class WaitGradeSys :public gradeSys
{
public:
    void getYoungManResult(YoungMan* yMan)
    {
        cout << "YoungMan Score Wait" << endl;
    }

    void getMiddleManResult(MiddleMan* MMan)
    {
        cout << "MiddleMan Score Wait"<< endl;
    }
};






