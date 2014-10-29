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

#ifndef INPUTDEVICEMANAGER_H
#define INPUTDEVICEMANAGER_H

#include <OISInputManager.h>
#include <OISMouse.h>
#include <OISJoyStick.h>
#include <OISKeyboard.h>
#include "include/Input/InputDeviceListener.h"

namespace MysticGE {
namespace Input {
	class InputDeviceManager
	{
		public:
			InputDeviceManager(std::size_t inWindowHandle);
			InputDeviceManager(std::size_t inWindowHandle, unsigned int inWidth, unsigned int inHeight);
			~InputDeviceManager(void);
			
			void capture(void);
			void setWindowExtents(unsigned int inWidth, unsigned int inHeight);
			void setEventCallbackWatcher(InputDeviceListener *inListener);
			//void clearPreviousStates();
			
			OIS::Mouse* getMouse(void);
			OIS::Keyboard* getKeyboard(void);
			OIS::JoyStick* getJoyStick(unsigned int inIndex);
			int getNumberOfJoySticks(void) const;
			
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
			
		private:
			void initialiseDevices(void);
			
			OIS::InputManager	*mInputSystem;
			OIS::Mouse			*mMouse;
			OIS::Keyboard		*mKeyboard;
			
			std::vector<OIS::JoyStick*>	mJoySticks;
	};
}
}

#endif // INPUTDEVICEMANAGER_H
