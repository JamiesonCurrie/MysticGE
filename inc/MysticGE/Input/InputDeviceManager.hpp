#ifndef INPUTDEVICEMANAGER_HPP
#define INPUTDEVICEMANAGER_HPP


#include <OgreRenderWindow.h>

#include <OISInputManager.h>
#include <OISMouse.h>
#include <OISJoyStick.h>
#include <OISKeyboard.h>

#include "InputDeviceListener.hpp"

namespace MysticGE {
namespace Input {
	class InputDeviceManager
	{
		public:
			virtual ~InputDeviceManager( void );
			
			void initialise( Ogre::RenderWindow *renderWindow );
			void capture( void );
			
			void setMouseWindowExtents( unsigned int width, unsigned int height );
			void setEventCallbackWatcher( InputDeviceListener *listener );
			
			OIS::Mouse* getMouse( void );
			OIS::Keyboard* getKeyboard( void );
			OIS::JoyStick* getJoyStick( unsigned int index );
			int getNumberOfJoySticks( void );
			
			/*
			bool anyButton(void) const;
			bool isButtonDown(OIS::MouseButtonID inButtonID);
			bool anyKey(void) const;
			bool isKeyPressed(OIS::KeyCode inKey) const;
			bool isKeyDown(OIS::KeyCode inKey) const;

			bool isButtonDown(int inJoystickIndex, int inButton) const;
			bool isPovDown(int inJoystickIndex, int inAxis, int inPov) const;
			bool isSliderDown(int inJoystickIndex, int inPov) const;
			int getAxisValue(int inJoystickIndex, int inAxis) const;
			*/
			
			static InputDeviceManager* getSingletonPtr( void );

		private:
			InputDeviceManager( void );
			InputDeviceManager( const InputDeviceManager& ) {}
			InputDeviceManager & operator = ( const InputManager& );
						
			OIS::InputManager	        *mInputSystem;
			OIS::Mouse			        *mMouse;
			OIS::Keyboard		        *mKeyboard;
			std::vector<OIS::JoyStick*>	mJoySticks;

			static InputDeviceManager *mInputDeviceManager;
	};
}
}

#endif // INPUTDEVICEMANAGER_HPP
