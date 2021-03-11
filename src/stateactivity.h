#ifndef STATEACTIVITY_H
#define STATEACTIVITY_H

class State;
class Activity
{
public:
    Activity(int count);
public:
    //扣除积分
    void dedcutMoney();
    //是否抽中奖品
    bool raffle();
    //发放奖品
    void dispensePrize();
    State* getNoRaffleState();
    State* getCanRaffleState();
    State* getDispenseRaffleState();
    State* getRaffleOutState();
    State* setState(State* state);
    int getPrizeCount();
private:
    int m_prizeCount;
    State* m_currentState;
    State* m_noRaffleState;
    State* m_canRaffleState;
    State* m_dispenseRaffleState;
    State* m_raffleOutState;
};
#endif // STATEACTIVITY_H
