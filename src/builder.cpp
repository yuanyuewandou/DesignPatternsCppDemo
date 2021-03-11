/* 小鱼号的代码日志
 * 设计模式
 * 建造者模式
 * 使用者不必知道产品内部组成的细节
 * 将产品本身与产品的创建过程解耦，
 * 使得相同的创建过程可以创建不同的产品对象
 * 增加新的具体建造者无须修改原有类库的代码
 * 盖房子问题
 */

#include<iostream>
#include<list>
using namespace std;


class House
{
public:
    void setBasic(string str)
    {
        m_strBasic = str;
        cout << str << endl;
    }
    void setWall(string str)
    {
        m_strWall = str;
        cout << str << endl;
    }
    void setRoofed(string str)
    {
        m_strRoofed = str;
        cout << str << endl;
    }
private:
    string m_strBasic;
    string m_strWall;
    string m_strRoofed;
};

class HouseBuilder
{
public:
    HouseBuilder()
    {
        m_house = new House;
    }
    //修建地基
    virtual void buildBasic() = 0;
    //修建墙
    virtual void buildWall() = 0;
    //修建房顶
    virtual void buildRoofed() = 0;
    //返回盖好的房子
    House* getHouse()
    {
        cout << "house is builded" << endl;
        return m_house;
    }
protected:
    House* m_house;
};

///具体盖房子的流程交给指挥者
class HouseDirector
{
public:
    void setBuilder(HouseBuilder* builder)
    {
        m_houseBuilder = builder;
    }
    House* builderHouse()
    {
        m_houseBuilder->buildBasic();
        m_houseBuilder->buildWall();
        m_houseBuilder->buildRoofed();
        return m_houseBuilder->getHouse();
    }
private:
    HouseBuilder* m_houseBuilder;
};

///普通房子
class CommonHouseBuilder : public HouseBuilder
{
    void buildBasic()
    {
        m_house->setBasic("common build basic 5m");
    }
    //修建墙
    void buildWall()
    {
        m_house->setWall("common build wall 5m");
    }
    //修建房顶
    void buildRoofed()
    {
        m_house->setRoofed("common build roof 5m");
    }
};

///高楼
class HighHouseBuilder : public HouseBuilder
{
    void buildBasic()
    {
        m_house->setBasic("high build basic 100m");
    }
    //修建墙
    void buildWall()
    {
         m_house->setBasic("high build wall 100m");
    }
    //修建房顶
    void buildRoofed()
    {
        m_house->setRoofed("high build roof 100m");
    }
};
