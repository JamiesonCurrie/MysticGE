#include "../inc/MysticGE/Game/GameManager.hpp"

namespace MysticGE {
namespace Game {
	GameManager* GameManager::mGameManager;

	GameManager::GameManager( void ) : 
		mGraphicsManager( 0 ),
		mInputManager( 0 ),
		mTimeCurrentFrame( 0 ),
		mTimeLastFrame( 0 ),
		mTimeSinceLstFrame( 0 ),
		mShutdown( false )
	{}

	GameManager::~GameManager() 
	{
		delete mInputManager;
		delete mGraphicsManager;
	}

	GameManager* GameManager::getSingletonPtr(void) 
	{
		if (!mGameManager) {
			mGameManager = new GameManager();
		}
		
		return mGameManager;
	}
	
	void GameManager::initialise(std::string inGameName) 
	{
		mGraphicsManager = GraphicsManager::getSingletonPtr();
		mGraphicsManager->initialiseWithSettingsDialog(inGameName);
		
		mInputManager = InputManager::getSingletonPtr();
		mInputManager->initialise(mGraphicsManager->getRenderWindow());
		
		return;
	}
	
	void GameManager::run(void)
	{
		while (!mShutdown) 
		{
			mTimeCurrentFrame = mGraphicsManager->getRootNode().getTimer()->getMicroseconds();
			mTimeSinceLastFrame = mTimeCurrentFrame - mTimeLastFrame;
			mTimeLastFrame = mTimeCurrentFrame;
			
			float seconds = mTimeSinceLastFrame / 1000000.0f;
			float fps = 1 / seconds;
			
			std::cout << "Seconds / Frame : " << seconds << endl;
			std::cout << "Frames / Second : " << fps << endl;
			
			mInputManager->capture();
			//mGraphicsManager->render();
		}
		
		return;
	}
	
	void GameManager::requestShutdown(void) 
	{
		mShutdown = true;
	}
}
}