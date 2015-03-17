#ifndef GAMEMANAGER_HPP
#define GAMEMANAGER_HPP

#include "../Graphics/GraphicsManager.hpp"
#include "../Input/InputManager.hpp"

namespace MysticGE {
namespace Game {
	class GameManager 
	{
		public:
			~GameManager(void);
			static GameManager* getSingletonPtr(void);
			
			void initialise(void);
			void run(void);
			
			void requestShutdown(void);
			
		private:
			GameManager( void );
			GameManager( const GameManager& ) {}
			GameManager & operator = ( const GameManager& );
			
			static GameManager *mGameManager;
			
			GraphicsManager *mGraphicsManager;
			InputManager	*mInputManager;
			
			unsigned int long mTimeLastFrame;
			unsigned int long mTimeCurrentFrame;
			unsigned int long mTimeSinceLastFrame;
			
			bool mShutdown;
	};
}
}

#endif