/*
 * Copyright (c) 2014 <copyright holder> <email>
 * 
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 * 
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 * 
 */

#ifndef INPUTDEVICELISTENER_H
#define INPUTDEVICELISTENER_H

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

#endif // INPUTDEVICELISTENER_H
