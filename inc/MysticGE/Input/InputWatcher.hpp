#ifndef INPUTWATCHER_HPP
#define INPUTWATCHER_HPP

#include <OISMouse.h>
#include <OISJoyStick.h>
#include <OISKeyboard.h>
#include "InputDeviceListener.hpp"

namespace MysticGE {
namespace Input {
	class InputWatcher : public InputDeviceListener
	{
		public:
			InputWatcher( void );
			virtual ~InputWatcher( void );
			
			void addKeyListener( OIS::KeyListener *keyListener, const std::string& instanceName );
			void addMouseListener( OIS::MouseListener *mouseListener, const std::string& instanceName );
			void addJoyStickListener( OIS::JoyStickListener *joyStickListener, const std::string& instanceName );
			
			void removeKeyListener( const std::string& instanceName );
			void removeMouseListener( const std::string& instanceName );
			void removeJoyStickListener( const std::string& instanceName );
			
			void removeKeyListener( OIS::KeyListener *keyListener );
			void removeMouseListener( OIS::MouseListener *mouseListener );
			void removeJoyStickListener( OIS::JoyStickListener *joyStickListener );
			
			void removeAllListeners( void );
			void removeAllKeyListeners( void );
			void removeAllMouseListeners( void );
			void removeAllJoyStickListeners( void );
			
		private:
			//Keyboard
			bool keyPressed(const OIS::KeyEvent &e);
			bool keyReleased(const OIS::KeyEvent &e);
			
			//Mouse
			bool mouseMoved(const OIS::MouseEvent &e);
			bool mousePressed(const OIS::MouseEvent &e, OIS::MouseButtonID id);
			bool mouseReleased(const OIS::MouseEvent &e, OIS::MouseButtonID id);
			
			//Joystick
			bool povMoved(const OIS::JoyStickEvent &e, int pov);
			bool axisMoved(const OIS::JoyStickEvent &e, int axis);
			bool sliderMoved(const OIS::JoyStickEvent &e, int sliderID);
			bool buttonPressed(const OIS::JoyStickEvent &e, int button);
			bool buttonReleased(const OIS::JoyStickEvent &e, int button);
			
			std::map<std::string, OIS::KeyListener*>		mKeyListeners;
			std::map<std::string, OIS::MouseListener*> 		mMouseListeners;
			std::map<std::string, OIS::JoyStickListener*>	mJoyStickListeners;
	};
}
}

#endif // INPUTWATCHER_HPP
