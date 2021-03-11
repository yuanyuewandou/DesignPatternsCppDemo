#include "state.cpp"
///含所有的状态对象
///各个状态子类也含有Activity对象

Activity::Activity(int count)
{
    m_prizeCount = count;
    m_noRaffleState = new NoRaffleState(this);
    m_canRaffleState = new CanRaffleState(this);
    m_dispenseRaffleState = new DispenseRaffleState(this);
    m_raffleOutState = new RaffleOutState(this);
    m_currentState = getNoRaffleState();
}

void Activity::dedcutMoney()
{
    m_currentState->dedcutMoney();
}

//是否抽中奖品
bool Activity::raffle()
{
    if(m_currentState->raffle())
    {
        m_currentState->dispensePrize();
    }
}

//发放奖品
void Activity::dispensePrize()
{
    m_currentState->dispensePrize();
}

State* Activity::getNoRaffleState()
{
    return m_noRaffleState;
}

State* Activity::getCanRaffleState()
{
    return m_canRaffleState;
}

State* Activity::getDispenseRaffleState()
{
    return m_dispenseRaffleState;
}

State* Activity::getRaffleOutState()
{
    return m_raffleOutState;
}

State* Activity::setState(State* state)
{
    m_currentState = state;
}

int Activity::getPrizeCount()
{
    cout << "current prize count:" << m_prizeCount << endl;
    return m_prizeCount--;
}
