/*小鱼号的代码日志
 * 设计模式
 * 解释器模式
 * 当一个语言需要解释执行，可将该语句中的句子表示为一个抽象语法树，
 * 就可以考虑使用解释器模式，让程序具有良好的扩展性
 * 带来的问题:
 * 解释器模式会引起类膨胀，解释器模式采用递归调用的方法，将会导致
 * 调用非常复杂，效率可能降低
 * 实例：
 *  计算加减乘除
 */

#include<iostream>
#include<map>
#include<stack>
using namespace std;

///抽象类表达式 通过map可以获取变量的值
class Expression
{
public:
    virtual int interpreter(map<char,int> var) = 0;
};

///变量的解释器
class VarExpression :public Expression
{
public:
    VarExpression(char key)
    {
        m_key = key;
    }
    virtual int interpreter(map<char,int> var)
    {
        return var[m_key];
    }
private:
    char m_key;
};

///抽象运算符号解析器 每个运算符号都只和自己左右连个数字有关系
///但左右两个数字有可能也是一个解析的结果，无论何种类型都是expression类的实现类
class SymbolExpression:public Expression
{
public:
    SymbolExpression(Expression* leftExpression,Expression* rightExpression)
    {
        m_leftExpression = leftExpression;
        m_rightExpression = rightExpression;
    }
    ///因为sybmol 是让子类来实现 因此interpreter是一个默认的实现
    int interpreter(map<char, int> var)
    {
        return 0;
    }
protected:
    Expression* m_leftExpression;
    Expression* m_rightExpression;
};

class AddExpression :public SymbolExpression
{
public:
    AddExpression(Expression* leftExpression ,Expression* rightExpression):
     SymbolExpression(leftExpression,rightExpression)
    {

    }
    virtual int interpreter(map<char,int> var)
    {
       return m_leftExpression->interpreter(var) + m_rightExpression->interpreter(var);
    }
};

class SubExpression :public SymbolExpression
{
public:
    SubExpression(Expression* leftExpression ,Expression* rightExpression):
     SymbolExpression(leftExpression,rightExpression)
    {

    }
    virtual int interpreter(map<char,int> var)
    {
       return m_leftExpression->interpreter(var) - m_rightExpression->interpreter(var);
    }
};

class Calculator
{
public:
    Calculator(string expStr)
    {
        stack<Expression*> stack;
        Expression* left = nullptr;
        Expression* right = nullptr;
        for(int i = 0; i < expStr.size(); i++)
        {
            switch (expStr[i])
            {
                case '+':
                    left = stack.top();
                    stack.pop();
                    right = new VarExpression(expStr[++i]);
                    stack.push(new AddExpression(left,right));
                    break;
                case '-':
                    left = stack.top();
                    stack.pop();
                    right = new VarExpression(expStr[++i]);
                    stack.push(new SubExpression(left,right));
                    break;
                default:
                    stack.push(new VarExpression(expStr[i]));
            }
        }
        m_expression = stack.top();
    }
    int run(map<char,int> var)
    {
        return m_expression->interpreter(var);
    }
private:
    Expression* m_expression;
};
