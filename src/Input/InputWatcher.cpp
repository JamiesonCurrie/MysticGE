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

#include "include/Input/InputWatcher.h"

namespace MysticGE {
namespace Input {
InputWatcher::InputWatcher(void)
{}

InputWatcher::~InputWatcher(void) {
	removeAllListeners();
}

void InputWatcher::addKeyListener(OIS::KeyListener *inKeyListener, const std::string& inInstanceName) {
	std::map<std::string, OIS::KeyListener*>::iterator itKeyListener = mKeyListeners.find(inInstanceName);
	if (itKeyListener == mKeyListeners.end()) {
		mKeyListeners[ inInstanceName ] = inKeyListener;
	}

	return;
}

void InputWatcher::addMouseListener(OIS::MouseListener *inMouseListener, const std::string& inInstanceName) {
	std::map<std::string, OIS::MouseListener*>::iterator itMouseListener = mMouseListeners.find(inInstanceName);
	
	if (itMouseListener == mMouseListeners.end()) {
		mMouseListeners[ inInstanceName ] = inMouseListener;
	}
	
	return;
}

void InputWatcher::addJoyStickListener(OIS::JoyStickListener *inJoyStickListener, const std::string& inInstanceName) {
	std::map<std::string, OIS::JoyStickListener*>::iterator itJoyStickListener = mJoyStickListeners.find(inInstanceName);
	
	if (itJoyStickListener == mJoyStickListeners.end()) {
		mJoyStickListeners[ inInstanceName ] = inJoyStickListener;
	}
	
	return;
}

void InputWatcher::removeKeyListener(OIS::KeyListener *inKeyListener) {
	std::map<std::string, OIS::KeyListener*>::iterator itKeyListener = mKeyListeners.begin();
	
	for ( ; itKeyListener != mKeyListeners.end();; itKeyListener) {
		if (itKeyListener->second == inKeyListener) {
			mKeyListeners.erase(itKeyListener);
			break;
		}
	}
	
	return;
}

void InputWatcher::removeMouseListener(OIS::MouseListener *inMouseListener) {
	std::map<std::string, OIS::MouseListener*>::iterator itMouseListener = mMouseListeners.begin();
	
	for (; itMouseListener != mMouseListeners.end(); itMouseListener++) {
		if (itMouseListener->second == inMouseListener) {
			mMouseListeners.erase(itMouseListener);
			break;
		}
	}
	
	return;
}

void InputWatcher::removeJoyStickListener(OIS::JoyStickListener *inJoyStickListener) {
	std::map<std::string, OIS::JoyStickListener*>::iterator itJoyStickListener
		= mJoyStickListeners.begin();
	
	for (; itJoyStickListener != mJoyStickListeners.end(); itJoyStickListener++) {
		if (itJoyStickListener->second == inJoyStickListener) {
			mJoyStickListeners.erase(itJoyStickListener);
			break;
		}
	}
	
	return;
}

void InputWatcher::removeAllListeners(void) {
	mKeyListeners.clear();
	mMouseListeners.clear();
	mJoyStickListeners.clear();
	
	return;
}

void InputWatcher::removeAllKeyListeners(void) {
	mKeyListeners.clear();
	
	return;
}

void InputWatcher::removeAllMouseListeners(void) {
	mMouseListeners.clear();
	
	return;
}

void InputWatcher::removeAllJoyStickListeners(void) {
	mJoyStickListeners.clear();
	
	return;
}

bool InputWatcher::keyPressed(const OIS::KeyEvent &e) {
	std::map<std::string, OIS::KeyListener*>::iterator itKeyListener = mKeyListeners.begin();
	
	for ( ; itKeyListener != mKeyListeners.end(); itKeyListener) {
		itKeyListener->second->keyPressed(e);
	}
	
	return true;
}

bool InputWatcher::keyReleased(const OIS::KeyEvent &e) {
	std::map<std::string, OIS::KeyListener*>::iterator itKeyListener = mKeyListeners.begin();
	
	for ( ; itKeyListener != mKeyListeners.end(); itKeyListener) {
		itKeyListener->second->keyReleased(e);
	}
	
	return true;
}

bool InputWatcher::mouseMoved(const OIS::MouseEvent &e) {
	std::map<std::string, OIS::MouseListener*>::iterator itMouseListener = mMouseListeners.begin();
	
	for (; itMouseListener != mMouseListeners.end(); itMouseListener++) {
		itMouseListener->second->mouseMoved(e);
	}
	
	return true;
}

bool InputWatcher::mousePressed(const OIS::MouseEvent &e, OIS::MouseButtonID id) {
	std::map<std::string, OIS::MouseListener*>::iterator itMouseListener = mMouseListeners.begin();
	
	for (; itMouseListener != mMouseListeners.end(); itMouseListener++) {
		itMouseListener->second->mousePressed(e, id);
	}
	
	return true;
}

bool InputWatcher::mouseReleased(const OIS::MouseEvent &e, OIS::MouseButtonID id) {
	std::map<std::string, OIS::MouseListener*>::iterator itMouseListener = mMouseListeners.begin();
	
	for (; itMouseListener != mMouseListeners.end(); itMouseListener++) {
		itMouseListener->second->mouseReleased(e, id);
	}
	
	return true;
}

bool InputWatcher::povMoved(const OIS::JoyStickEvent &e, int pov) {
	std::map<std::string, OIS::JoyStickListener*>::iterator itJoyStickListener = mJoyStickListeners.end();
	
	for (; itJoyStickListener != mJoyStickListeners.end(); itJoyStickListener++) {
		itJoyStickListener->second->povMoved(e, pov);
	}
	
	return true;
}

bool InputWatcher::axisMoved(const OIS::JoyStickEvent &e, int axis) {
	std::map<std::string, OIS::JoyStickListener*>::iterator itJoyStickListener = mJoyStickListeners.end();
	
	for (; itJoyStickListener != mJoyStickListeners.end(); itJoyStickListener++) {
		itJoyStickListener->second->axisMoved(e, axis);
	}
	
	return true;
}

bool InputWatcher::sliderMoved(const OIS::JoyStickEvent &e, int sliderID) {
	std::map<std::string, OIS::JoyStickListener*>::iterator itJoyStickListener = mJoyStickListeners.end();
	
	for (; itJoyStickListener != mJoyStickListeners.end(); itJoyStickListener++) {
		itJoyStickListener->second->sliderMoved(e, sliderID);
	}
	
	return true;
}

bool InputWatcher::buttonPressed(const OIS::JoyStickEvent &e, int button) {
	std::map<std::string, OIS::JoyStickListener*>::iterator itJoyStickListener = mJoyStickListeners.end();
	
	for (; itJoyStickListener != mJoyStickListeners.end(); itJoyStickListener++) {
		itJoyStickListener->second->buttonPressed(e, button);
	}
	
	return true;
}

bool InputWatcher::buttonReleased(const OIS::JoyStickEvent &e, int button) {
	std::map<std::string, OIS::JoyStickListener*>::iterator itJoyStickListener = mJoyStickListeners.end();
	
	for (; itJoyStickListener != mJoyStickListeners.end(); itJoyStickListener++) {
		itJoyStickListener->second->buttonReleased(e, button);
	}
	
	return true;
}

}
}
