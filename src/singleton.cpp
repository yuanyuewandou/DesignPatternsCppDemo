/*设计模式
 *  保证系统中有一个对象
 *  实现步骤
 *  1 构造函数私有化
 *  2 增加静态私有的当前类的指针变量
 *  3 提供静态对外接口，可以让用户获得单例对象
 * 懒汉式 多线程不安全
 * 饿汉式
*/
#include<iostream>
using namespace std;

///懒汉式 调用时才创建
class LazySingleton
{
private:
    LazySingleton()
    {
        cout << "Lazy signleton" << endl;
    }
    static LazySingleton* getInstance()
    {
        if(pSingleton == nullptr)
        {
            pSingleton = new LazySingleton();
        }
        return pSingleton;
    }
private:
    static LazySingleton* pSingleton;
};

LazySingleton* LazySingleton::pSingleton = nullptr;


///饿汉式 静态创建
class HungrySingleton
{
private:
    HungrySingleton()
    {
        cout << "Hungry Signleton" << endl;
    }
    static HungrySingleton* getInstance()
    {
        return pSingleton;
    }
    class Garbo
    {
        ~Garbo()
        {
            if(pSingleton != nullptr)
                delete pSingleton;
        }
    };
private:
    static HungrySingleton* pSingleton;
    static Garbo garbo;
};

HungrySingleton* HungrySingleton::pSingleton = new HungrySingleton();


