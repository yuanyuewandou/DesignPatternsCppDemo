/*小鱼号的代码日志
 * 设计模式
 * 享元模式
 * 运用共享技术有效地支持大量细粒度的对象
 * 为了解决重复对象的内存浪费的问题
 * 享元模式提出了两个要求：
 * 细粒度和共享对象
 * 内部状态：共享出来的信息，存储在
 *         享元对象内部且不会随环境改变
 * 外部状态：对象依赖的一个标记，随环境改变
 *          不可共享的状态
 * 实例：一个网站，内容一样
 * 需要以公众号，博客，新闻的形式发布
 *
 */

#include<iostream>
#include<map>
using namespace std;
enum class EN_WEB_TYPE
{
    WECHAT_WEB,
    NEWS_WEB,
    BLOG_WEB
};

class WebUser
{
public:
    WebUser(string userName)
    {
        m_userName = userName;
    }
    string getUserName()
    {
        return m_userName;
    }
private:
    string m_userName;
};

class WebSite
{
public:
    virtual void use(WebUser* user) = 0;
};

class ConcreteWebSite :public WebSite
{
public:
    ConcreteWebSite(EN_WEB_TYPE type)
    {
        m_type = type;
    }
    void use(WebUser* user)
    {
        cout << " web use " << user->getUserName() <<  " and web type = " << (int)m_type << endl;
    }
private:
    EN_WEB_TYPE m_type;
};

class WebSiteFactory
{
public:
    WebSite* getWebSiteCategory(EN_WEB_TYPE type)
    {
        WebSite* pWeb = nullptr;
        auto it = m_map.find(type);
        if(it != m_map.end())
        {
            pWeb = (*it).second;
        }
        else
        {
            pWeb = new ConcreteWebSite(type);
            m_map[type] = pWeb;
        }
        return pWeb;
    }
    int getCount()
    {
        return m_map.size();
    }
private:
    map<EN_WEB_TYPE,WebSite*> m_map;
};





