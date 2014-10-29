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

#include "include/Input/InputManager.h"

namespace MysticGE {
namespace Input {
	
//InputManager* InputManager::mInputManager;

InputManager::InputManager(size_t inWindowHandle, unsigned int inWidth, unsigned int inHeight) {
	mInputDeviceManager	= new InputDeviceManager(inWindowHandle, inWidth, inHeight);
	mInputWatcher		= new InputWatcher();
	
	mInputDeviceManager.setEventCallbackWatcher(&mInputWatcher);
}

InputManager::~InputManager() {
	delete mInputWatcher;
	delete mInputDeviceManager;
}

/*
InputManager* InputManager::getSingletonPtr(void) {
	if (!mInputManager) {
		mInputManager = new InputManager();
	}
	
	return mInputManager;
}
*/

void InputManager::capture(void) {
	mInputDeviceManager.capture();
	
	return;
}

void InputManager::addKeyListener(OIS::KeyListener *inKeyListener, const std::string& inInstanceName) {
	mInputWatcher.addKeyListener(inKeyListener, inInstanceName);
	
	return;
}

void InputManager::addMouseListener(OIS::MouseListener *inMouseListener, const std::string& inInstanceName) {
	mInputWatcher.addMouseListener(inMouseListener, inInstanceName);
	
	return;
}

void InputManager::addJoyStickListener(OIS::JoyStickListener *inJoyStickListener, const std::string& inInstanceName) {
	mInputWatcher.addJoyStickListener(inJoyStickListener, inInstanceName);
	
	return;
}

void InputManager::removeKeyListener(const std::string& inInstanceName) {
	mInputWatcher.removeKeyListener(inInstanceName);
	
	return;
}

void InputManager::removeKeyListener(OIS::KeyListener *inKeyListener) {
	mInputWatcher.removeKeyListener(inKeyListener);
	
	return;
}

void InputManager::removeMouseListener(const std::string& inInstanceName) {
	mInputWatcher.removeMouseListener(inInstanceName);
	
	return;
}

void InputManager::removeMouseListener(OIS::MouseListener *inMouseListener) {
	mInputWatcher.removeMouseListener(inMouseListener);
	
	return;
}

void InputManager::removeJoyStickListener(const std::string& inInstanceName) {
	mInputWatcher.removeJoyStickListener(inInstanceName);
	
	return;
}

void InputManager::removeJoyStickListener(OIS::JoyStickListener *inJoyStickListener) {
	mInputWatcher.removeJoyStickListener(inJoyStickListener);
	
	return;
}


void InputManager::removeAllListeners(void) {
	mInputWatcher.removeAllListeners();
	
	return;
}

void InputManager::removeAllKeyListeners(void) {
	mInputWatcher.removeAllKeyListeners();
	
	return;
}

void InputManager::removeAllMouseListeners(void) {
	mInputWatcher.removeAllMouseListeners();
	
	return;
}

void InputManager::removeAllJoyStickListeners(void) {
	mInputWatcher.removeAllMouseListeners();
	
	return;
}

}
}