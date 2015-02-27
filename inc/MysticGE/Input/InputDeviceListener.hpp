#ifndef INPUTDEVICELISTENER_HPP
#define INPUTDEVICELISTENER_HPP

#include <OISMouse.h>
#include <OISJoyStick.h>
#include <OISKeyboard.h>

namespace MysticGE {
namespace Input {
	class InputDeviceListener : public OIS::KeyListener, OIS::MouseListener, OIS::JoyStickListener
	{
		//Keyboard
		virtual bool keyPressed(const OIS::KeyEvent &e) = 0;
		virtual bool keyReleased(const OIS::KeyEvent &e) = 0;

		//Mouse
		virtual bool mouseMoved(const OIS::MouseEvent &e) = 0;
		virtual bool mousePressed(const OIS::MouseEvent &e, OIS::MouseButtonID id) = 0;
		virtual bool mouseReleased(const OIS::MouseEvent &e, OIS::MouseButtonID id) = 0;

		//Joystick
		virtual bool povMoved(const OIS::JoyStickEvent &e, int pov) = 0;
		virtual bool axisMoved(const OIS::JoyStickEvent &e, int axis) = 0;
		virtual bool sliderMoved(const OIS::JoyStickEvent &e, int sliderID) = 0;
		virtual bool buttonPressed(const OIS::JoyStickEvent &e, int button) = 0;
		virtual bool buttonReleased(const OIS::JoyStickEvent &e, int button) = 0;
	};
}
}

#endif // INPUTDEVICELISTENER_HPP
