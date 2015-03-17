#include "../../inc/MysticGE/Game/GameManager.hpp"

#include "TestListener.hpp"

int main(int argv, char** argc)
{
	GameManager* game = GameManager::getSingletonPtr();
	game->initialise('INPUT TEST');
	
	TestListener tester = new TestListener();
	
	game->run();
	
	delete tester;
	delete game;
	
	return 0;
}