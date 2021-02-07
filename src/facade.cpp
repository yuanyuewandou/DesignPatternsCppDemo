/*设计模式
 *外观模式
 *  根据迪米特法则，如果两个类不必彼此直接通信，
 *  那么这两个类就不应该发生直接的相互关系。
 *  就是将复杂的子类系统抽象到同一个的接口进行管理
 *  外界只需要通过此接口与子类系统进行交互
 *  而不必要直接与复杂的子类系统进行交互
 *  现实生活例子
 *  开启KTV模式
 * 需要打开电视，音箱，麦克风，关闭游戏机
 * 开启游戏模式
 * 需要打开电视，游戏机，关闭麦克风，音箱
 */
#include<iostream>
using namespace std;

class TV
{
  public:
    void On()
    {
        cout << "tv open" << endl;
    }
    void Off()
    {
        cout << "tv close" << endl;
    }
};

class Audio
{
  public:
    void On()
    {
        cout << "Audio open" << endl;
    }
    void Off()
    {
        cout << "Audio close" << endl;
    }
};

class Mic
{
  public:
    void On()
    {
        cout << "Mic open" << endl;
    }
    void Off()
    {
        cout << "Mic close" << endl;
    }
};

class Game
{
  public:
    void On()
    {
        cout << "Game open" << endl;
    }
    void Off()
    {
        cout << "Game close" << endl;
    }
};

class KTVMode
{
public:
    KTVMode()
    {
        cout << "open ktv mode" << endl;
        pTV = new TV();
        pAudio = new Audio();
        pGame = new Game();
        pMic = new Mic();
    }
    ~KTVMode()
    {
          delete pTV;
        delete pAudio;
        delete pGame;
        delete pMic;
    }
    void onKTV()
    {
        pTV->On();
        pAudio->On();
        pMic->On();
        pGame->Off();
    }
    void ofKTV()
    {
        pTV->Off();
        pAudio->Off();
        pMic->Off();
        pGame->Off();
    }
public:
    TV* pTV;
    Audio* pAudio;
    Game* pGame;
    Mic* pMic;
};

class GameMode
{
public:
    GameMode()
    {
        pTV = new TV();
        pAudio = new Audio();
        pGame = new Game();
        pMic = new Mic();
    }
    ~GameMode()
    {
        delete pTV;
        delete pAudio;
        delete pGame;
        delete pMic;
    }
    void onGameMode()
    {
        pTV->On();
        pAudio->Off();
        pMic->Off();
        pGame->On();
    }
    void offGameMode()
    {
        pTV->Off();
        pAudio->Off();
        pMic->Off();
        pGame->Off();
    }
public:
    TV* pTV;
    Audio* pAudio;
    Game* pGame;
    Mic* pMic;
};

