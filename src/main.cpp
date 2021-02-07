#include <QCoreApplication>
#include "factoryFunction.cpp"
#include"abstractfactory.cpp"
#include "facade.cpp"
#include "TemplateMethod.cpp"
#include "strategy.cpp"
#include "command.cpp"
#include "observer.cpp"
#include "decorator.cpp"
#include "decorator2.cpp"
#include "bridge.cpp"

void testSimpleFactory()
{
    cout << "simple factory test" << endl;
    FruitFactory* factory = new FruitFactory;
    AbstractFruit* fruit = factory->CreateFruit("apple");
    fruit->ShowName();
    delete fruit;
    fruit = factory->CreateFruit("banana");
    fruit->ShowName();
    delete fruit;
    delete factory;
}

void testFactoryFunction()
{
    cout << "factory function test" << endl;
    AbstractFruitFactory* absFactory = nullptr;
    absFactory = new AppleFruitFactory();
    AbstractFruit* fruit = absFactory->CreateFruit();
    fruit->ShowName();
    delete absFactory;

    absFactory = new BananaFruitFactory();
    fruit = absFactory->CreateFruit();
    fruit->ShowName();
    delete fruit;
}

void testAbstractFactory()
{
    cout << "abstract factory test" << endl;
    AbstractFactory* absfactory = nullptr;
    AbstractApple* apple = nullptr;
    AbstractBanana* banana = nullptr;

    absfactory = new ChinaFactory;
    apple = absfactory->CreateApple();
    apple->ShowName();
    banana = absfactory->CreateBanana();
    banana->ShowName();

    delete apple;
    delete banana;
    delete absfactory;
}

void testFacade()
{
    cout << "facade:" << endl;
    KTVMode *pKtv = new KTVMode();
    pKtv->onKTV();
    GameMode *pGame = new GameMode();
    pGame->onGameMode();
}

void testTemplateMethod()
{
    cout << "TemplateMethod:" << endl;
    OnlineShopping* pShopping = new JDOnlineShopping;
    pShopping->shopping();

    pShopping = new TaoBaoOnlineShopping;
    pShopping->shopping();
}

void testStrategy()
{
    cout << "Strategy:" << endl;
    Character *pCharacter = new Character();
    WeaponStrategy* pWeaponStrategy = new KnifeStrategy;
    pCharacter->setWeapon(pWeaponStrategy);
    pCharacter->useWeaponStrategy();

    pWeaponStrategy = new AK47Strategy;
    pCharacter->setWeapon(pWeaponStrategy);
    pCharacter->useWeaponStrategy();
}

void testCommand()
{
    HandleClientProtocol* protocol = new HandleClientProtocol();
     GameServer* server = new GameServer;

    //客户端增加金币的请求
    AbstractCommand * pCommand = new AddMoneyCommand(protocol);
    server->addRequest(pCommand);

    pCommand = new AddDiamondCommand(protocol);
    server->addRequest(pCommand);

    pCommand = new AddEquipmentCommand(protocol);
    server->addRequest(pCommand);

    pCommand = new AddMoneyCommand(protocol);
    server->addRequest(pCommand);

    server->startHandle();
}

void testObserve()
{
    //创建观察者
    AbstractHero* pHeroA = new HeroA();
    AbstractHero* pHeroB = new HeroB();
    AbstractHero* pHeroC = new HeroC();
    //创建观察目标
    AbstractBoss* pBossA = new BOSS();

    pBossA->addHero(pHeroA);
    pBossA->addHero(pHeroB);
    pBossA->addHero(pHeroC);

    cout << "hero c is dead" << endl;
    pBossA->deleteHero(pHeroC);

    cout << "boss a is dead" << endl;
    pBossA->notify();
}

void testDecorator()
{
    AbstractPlayer* player = new PlayerA();
    cout << "player init" << endl;
    player->ShowStatus();
    cout << "-------------"<<endl;
    cout << "player add ak47"<<endl;
    cout << "-------------"<<endl;
    player = new AK47Equipment(player);
    player->ShowStatus();
}

void coffeeBar()
{
    ///coffee shop
    //点一份美式咖啡
    cout << "order long black coffee" << endl;
    Drink* pDrink = new LongBlackCoffee();
    cout << " Drink desc: " << pDrink->getDesc() << endl;
    cout << " Drink price: " << pDrink->cost() << endl;
    //选择牛奶风味
    cout << "add milk flavor" << endl;
    pDrink = new MilkFlavorCoffee(pDrink);
    cout << " Drink desc: " << pDrink->getDesc() << endl;
    cout << " Drink price: " << pDrink->cost() << endl;

    //又添加选择巧克力风味
    cout << "add chocolate flavor" << endl;
    pDrink = new ChocolateFlavorCoffee(pDrink);
    cout << " Drink desc: " << pDrink->getDesc() << endl;
    cout << " Drink price: " << pDrink->cost() << endl;

    //又添加选择牛奶风味
    cout << "add milk flavor" << endl;
    pDrink = new MilkFlavorCoffee(pDrink);
    cout << " Drink desc: " << pDrink->getDesc() << endl;
    cout << " Drink price: " << pDrink->cost() << endl;
    cout << "check out coffee" << endl << endl;

    //点一份意大利咖啡
    cout << "order Espress coffee" << endl;
    Drink* pDrink2 = new EspressoCoffee();
    cout << " Drink desc: " << pDrink2->getDesc() << endl;
    cout << " Drink price: " << pDrink2->cost() << endl;

    //添加了豆浆风味
    cout << "add soy flavor" << endl;
    pDrink2 = new SoyFlavorCoffee(pDrink2);
    cout << " Drink desc: " << pDrink2->getDesc() << endl;
    cout << " Drink price: " << pDrink2->cost() << endl;
    cout << "check out coffee" << endl << endl;
    //结账

}

void testBridge()
{
    //获取手机(样式+品牌)
    //折叠式的小米手机
    Phone* pPhone = new FoldePhone(new XiaomiPhone);
    pPhone->open();
    pPhone->call();
    pPhone->close();
    //折叠式的vivo手机
    pPhone = new FoldePhone(new VivoPhone);
    pPhone->open();
    pPhone->call();
    pPhone->close();

    //旋转式的vivo手机
    pPhone = new RotationPhone(new VivoPhone);
    pPhone->open();
    pPhone->call();
    pPhone->close();
 }

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //cout << "++++++++++++++++++++++++++++++++++++++++++Design Patterns CPP Demo +++++++++++++++++++++++++++++++++++++++" << endl;
    //testSimpleFactory();
    //testFactoryFunction();
    //testAbstractFactory();
    //testFacade();
    //testTemplateMethod();
    //testStrategy();
    //testCommand();
    //testObserve();
    //testDecorator();
    //testBridge();
    coffeeBar();
    return a.exec();
}
