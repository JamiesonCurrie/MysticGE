#ifndef INPUTDEVICEMANAGER_HPP
#define INPUTDEVICEMANAGER_HPP

#include <OISInputManager.h>
#include <OISMouse.h>
#include <OISJoyStick.h>
#include <OISKeyboard.h>

#include <OgreRenderWindow.h>

namespace MysticGE {
namespace Input {
	class InputDeviceManager
	{
		public:
			~InputDeviceManager( void );
			static InputDeviceManager* getSingletonPtr( void );
			
			void initialise( const Ogre::RenderWindow& renderWindow );
			void capture( void );
			
			void setKeyboardEventListener(const OIS::KeyListener*& listener);
			void setMouseEventListener(const OIS::MouseListener*& listener);
			void setJoyStickEventListener(const OIS::JoyStickListener*& listener);
			
			OIS::Mouse*    getMouse( void );
			OIS::Keyboard* getKeyboard( void );
			OIS::JoyStick* getJoyStick( unsigned int index );
			
			void setMouseWindowExtents( unsigned int width, unsigned int height );
			int getNumberOfJoySticks( void );

		private:
			InputDeviceManager( void );
			InputDeviceManager( const InputDeviceManager& ) {}
			InputDeviceManager & operator = ( const InputManager& );
			
			static InputDeviceManager*  mInputDeviceManager;
						
			OIS::InputManager*	        mInputSystem;
			OIS::Mouse*			        mMouse;
			OIS::Keyboard*		        mKeyboard;
			std::vector<OIS::JoyStick*>	mJoySticks;
	};
}
}

#endif // INPUTDEVICEMANAGER_HPP
