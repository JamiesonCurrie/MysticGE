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

#ifndef INPUTWATCHER_H
#define INPUTWATCHER_H

#include <OISMouse.h>
#include <OISJoyStick.h>
#include <OISKeyboard.h>
#include "include/Input/InputDeviceListener.h"

namespace MysticGE {
namespace Input {
	class InputWatcher : public InputDeviceListener
	{
		public:
			InputWatcher(void);
			virtual ~InputWatcher(void);
			
			void addKeyListener(OIS::KeyListener *inKeyListener, const std::string& inInstanceName);
			void addMouseListener(OIS::MouseListener *inMouseListener, const std::string& inInstanceName);
			void addJoyStickListener(OIS::JoyStickListener *inJoyStickListener, const std::string& inInstanceName);
			
			void removeKeyListener(const std::string& inInstanceName);
			void removeMouseListener(const std::string& inInstanceName);
			void removeJoyStickListener(const std::string& inInstanceName);
			
			void removeKeyListener(OIS::KeyListener *inKeyListener);
			void removeMouseListener(OIS::MouseListener *inMouseListener);
			void removeJoyStickListener(OIS::JoyStickListener *inJoyStickListener);
			
			void removeAllListeners(void);
			void removeAllKeyListeners(void);
			void removeAllMouseListeners(void);
			void removeAllJoyStickListeners(void);
			
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

#endif // INPUTWATCHER_H
