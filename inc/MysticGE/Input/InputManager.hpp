#ifndef INPUTMANAGER_HPP
#define INPUTMANAGER_HPP

#include <OgreRenderWindow.h>


#include "InputDeviceManager.hpp"
#include "InputWatcher.hpp"

namespace MysticGE {
namespace Input {
	class InputManager
	{
		public:
			virtual ~InputManager(void);
			
			void initialise( Ogre::RenderWindow *renderWindow );
			void capture( void );
			
			//InputWatcher Accesors
			void addKeyListener( OIS::KeyListener *keyListener, const std::string& instanceName );
			void addMouseListener( OIS::MouseListener *mouseListener, const std::string& instanceName );
			void addJoyStickListener( OIS::JoyStickListener *joyStickListener, const std::string& instanceName );
			
			void removeKeyListener( const std::string& instanceName );
			void removeKeyListener( OIS::KeyListener *keyListener );
			void removeMouseListener( const std::string& instanceName );
			void removeMouseListener( OIS::MouseListener *mouseListener );
			void removeJoyStickListener( const std::string& instanceName );
			void removeJoyStickListener( OIS::JoyStickListener *joyStickListener );
			
			void removeAllListeners( void );
			void removeAllKeyListeners( void );
			void removeAllMouseListeners( void );
			void removeAllJoyStickListeners( void );
			
			static InputManager* getSingletonPtr( void ) ;

		private:
			InputManager( void );
			InputManager( const InputManager& ) {}
			InputManager & operator = ( const InputManager& );
			
			InputDeviceManager	*mInputDeviceManager;
			InputWatcher		mInputWatcher;
			
			static InputManager *mInputManager;
	};
}
}

#endif // INPUTMANAGER_HPP

