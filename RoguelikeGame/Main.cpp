#include "Game.h"
#include "StandartInclude.h"

//using namespace std;
//
//namespace rs
//{
//	class TestObj
//	{
//	public:
//		static int lastId;
//		int id;
//	public:
//		TestObj();
//		~TestObj();
//		TestObj(const TestObj& src);
//	};
//
//	int TestObj::lastId = 0;
//	TestObj::TestObj() : id(lastId)
//	{
//		lastId++;
//		std::cout << "TestObj №" << id << " вызвал конструктор" << std::endl;
//	}
//	TestObj::~TestObj()
//	{
//		std::cout << "TestObj №" << id << " вызвал деструктор" << std::endl;
//	}
//	TestObj::TestObj(const TestObj& src)
//	{
//		std::cout << "TestObj №" << id << " вызвал конструктор копирования;\t src.id = " << src.id << std::endl;
//	}
//}


int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(0));
	GameData::init();
	GameConfig::init();
	Game game;
	game.start();

	//system("pause");
	return 0;
}