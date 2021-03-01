/* 小鱼号的代码日志
 * 设计模式
 * 迭代器模式
 * 大学院系信息展示
 */

#include<iostream>
#include<list>
#include<vector>
#include<array>
using namespace std;

class Department
{
public:
    Department(string strName)
    {
        m_strName = strName;
    }
    string getName()
    {
        return m_strName;
    }
    void setName(string strName)
    {
        m_strName = strName;
    }
private:
    string m_strName;
};

class Iterator
{
public:
    virtual bool hasNext() = 0;
    virtual Department* next() = 0;
    virtual void remove() = 0;
};

//计算机学院迭代器
class ComputerCollegeIterator :public Iterator
{
public:
    ComputerCollegeIterator(vector<Department*> vDepartment)
    {
        m_pos = 0;
        m_vDepartment = vDepartment;
    }
public:
    bool hasNext()
    {
        if(m_pos >= m_vDepartment.size())
        {
            return false;
        }
        return true;
    }
    Department* next()
    {
        return m_vDepartment[m_pos++];
    }
    void remove()
    {

    }
private:
    int m_pos;
    //计算机学院是按照vector存放系
    vector<Department*> m_vDepartment;
};

//信息工程学院迭代器
class InfoCollegeIterator :public Iterator
{
public:
    InfoCollegeIterator(array<Department*,5> ADepartment)
    {
        m_pos = 0;
        m_ADepartment = ADepartment;
    }
public:
    bool hasNext()
    {
        if(m_pos >= m_ADepartment.size())
        {
            return false;
        }
        return true;
    }
    Department* next()
    {
        return m_ADepartment[m_pos++];
    }
    void remove()
    {

    }
private:
    int m_pos;
    //计算机学院是按照array存放系
    array<Department*,5> m_ADepartment;
};

class College
{
public:
    College(string name)
    {
        m_name = name;
    }
    string getName()
    {
        return m_name;
    }
    virtual void addDepartment(string name) = 0;
    virtual Iterator* creatorIterator() = 0;
protected:
    string m_name;
};

class ComputerCollege : public College
{
public:
    ComputerCollege(string name) :College(name)
    {
        addDepartment("Soft Department");
        addDepartment("Net Department");
        addDepartment("BigData Department");
    }
    void addDepartment(string name)
    {
        Department* part = new Department(name);
        m_vDepartment.push_back(part);
    }
    Iterator* creatorIterator()
    {
        return new ComputerCollegeIterator(m_vDepartment);
    }
private:
    vector<Department*> m_vDepartment;
};

class InfoCollege : public College
{
public:
    InfoCollege(string name):College(name)
    {
        m_index = 0;
        addDepartment("Info Department1");
        addDepartment("Info Department2");
        addDepartment("Info Department3");
        addDepartment("Info Department4");
        addDepartment("Info Department5");
    }
    void addDepartment(string name)
    {
        Department* part = new Department(name);
        m_ADepartment[m_index++] = part;
    }
    Iterator* creatorIterator()
    {
        return new InfoCollegeIterator(m_ADepartment);
    }
private:
    array<Department*,5> m_ADepartment;
    int m_index;
};

