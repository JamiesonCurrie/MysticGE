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

#include "include/Input/InputDeviceManager.h"

namespace MysticGE {
namespace Input {

InputDeviceManager::InputDeviceManager(std::size_t inWindowHandle, unsigned int inWidth, unsigned int inHeight) {
	mInputSystem = OIS::InputManager::createInputSystem(inWindowHandle);
	
	if (mInputSystem->getNumberOfDevices(OIS::OISKeyboard) > 0) {
		mKeyboard = static_cast<OIS::Keyboard*>(mInputSystem->createInputObject(OIS::OISKeyboard, true));
		mKeyboard->setTextTranslation(OIS::Keyboard::Ascii);
	}
	
	if (mInputSystem->getNumberOfDevices(OIS::OISMouse) > 0) {
		mMouse = static_cast<OIS::Mouse*>(mInputSystem->createInputObject(OIS::OISMouse, true));
		setWindowExtents(inWidth, inHeight);
	}
	
	if (mInputSystem->getNumberOfDevices(OIS::OISJoyStick) > 0) {
		mJoySticks.resize(mInputSystem->getNumberOfDevices(OIS::OISJoyStick));
		std::vector<OIS::JoyStick*>::iterator itJoySticks = mJoySticks.begin();
		for (; itJoySticks != mJoySticks.end(); mJoySticks++) {
			(*itJoySticks) = static_cast<OIS::JoyStick*>(mInputSystem->createInputObject(OIS::OISJoyStick, true));
		}
	}
}

InputDeviceManager::~InputDeviceManager(void) {
	if (mInputSystem) {
		if (mMouse) {
			mInputSystem->destroyInputObject(mMouse);
			mMouse = 0;
		}
		if (mKeyboard) {
			mInputSystem->destroyInputObject(mKeyboard);
		}
		if (getNumberOfJoySticks() > 0) {
			std::vector<OIS::JoyStick*>::iterator itJoySticks = mJoySticks.begin();
			for (; itJoySticks != mJoySticks.end(); mJoySticks++) {
				mInputSystem->destroyInputObject(*itJoySticks);
			}
			mJoySticks.clear();
		}
		
		OIS::InputManager::destroyInputSystem(mInputSystem);
		mInputSystem = 0;
	}
}

void InputDeviceManager::capture(void) {
	if (mMouse) {
		mMouse->capture();
	}
	if (mKeyboard) {
		mKeyboard->capture();
	}
	if (getNumberOfJoySticks() > 0) {
		std::vector<OIS::JoyStick*>::iterator itJoySticks = mJoySticks.begin();
		for (; itJoySticks != mJoySticks.end(); mJoySticks++) {
			(*itJoySticks)->capture();
		}
	}
	
	return;
}

void InputDeviceManager::setWindowExtents(unsigned int inWidth, unsigned int inHeight) {
	mMouse->getMouseState().width = inWidth;
	mMouse->getMouseState().height = inHeight;
	
	return;
}

void InputDeviceManager::setEventCallbackWatcher(InputDeviceListener *inListener) {
	if (mKeyboard) {
		mKeyboard->setEventCallback(inListener);
	}
	if (mMouse) {
		mMouse->setEventCallback(inListener);
	}
	if (getNumberOfJoySticks() > 0) {
		std::vector<OIS::JoyStick*>::iterator itJoySticks = mJoySticks.begin();
		for (; itJoySticks != mJoySticks.end(); mJoySticks++) {
			(*itJoySticks)->setEventCallback(inListener);
		}
	}
}

OIS::Mouse* InputDeviceManager::getMouse(void) {
	return mMouse;
}

OIS::Keyboard* InputDeviceManager::getKeyboard(void) {
	return mKeyboard;
}

OIS::JoyStick* InputDeviceManager::getJoyStick(unsigned int inIndex) {
	if (inIndex > 0 && inIndex < mJoySticks.size()) {
		return mJoySticks[inIndex];
	}
	
	return 0;
}

int InputDeviceManager::getNumberOfJoySticks(void) {
	return (int) mJoySticks.size();
}



}
}