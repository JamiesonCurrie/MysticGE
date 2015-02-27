#include "../inc/MysticGE/Input/InputWatcher.hpp"

namespace MysticGE {
namespace Input {
	InputWatcher::InputWatcher(void)
	{}

	InputWatcher::~InputWatcher(void) {
		removeAllListeners();
	}

	void InputWatcher::addKeyListener(OIS::KeyListener *keyListener, const std::string& instanceName) {
		std::map<std::string, OIS::KeyListener*>::iterator itKeyListener = mKeyListeners.find(instanceName);
		if (itKeyListener == mKeyListeners.end()) {
			mKeyListeners[ instanceName ] = keyListener;
		}

		return;
	}

	void InputWatcher::addMouseListener(OIS::MouseListener *mouseListener, const std::string& instanceName) {
		std::map<std::string, OIS::MouseListener*>::iterator itMouseListener = mMouseListeners.find(instanceName);
		
		if (itMouseListener == mMouseListeners.end()) {
			mMouseListeners[ instanceName ] = mouseListener;
		}
		
		return;
	}

	void InputWatcher::addJoyStickListener(OIS::JoyStickListener *joyStickListener, const std::string& instanceName) {
		std::map<std::string, OIS::JoyStickListener*>::iterator itJoyStickListener = mJoyStickListeners.find(instanceName);
		
		if (itJoyStickListener == mJoyStickListeners.end()) {
			mJoyStickListeners[ instanceName ] = joyStickListener;
		}
		
		return;
	}

	void InputWatcher::removeKeyListener(OIS::KeyListener *keyListener) {
		std::map<std::string, OIS::KeyListener*>::iterator itKeyListener = mKeyListeners.begin();
		
		for (; itKeyListener != mKeyListeners.end(); itKeyListener++) {
			if (itKeyListener->second == keyListener) {
				mKeyListeners.erase(itKeyListener);
				break;
			}
		}
		
		return;
	}

	void InputWatcher::removeMouseListener(OIS::MouseListener *mouseListener) {
		std::map<std::string, OIS::MouseListener*>::iterator itMouseListener = mMouseListeners.begin();
		
		for (; itMouseListener != mMouseListeners.end(); itMouseListener++) {
			if (itMouseListener->second == mouseListener) {
				mMouseListeners.erase(itMouseListener);
				break;
			}
		}
		
		return;
	}

	void InputWatcher::removeJoyStickListener(OIS::JoyStickListener *joyStickListener) {
		std::map<std::string, OIS::JoyStickListener*>::iterator itJoyStickListener
			= mJoyStickListeners.begin();
		
		for (; itJoyStickListener != mJoyStickListeners.end(); itJoyStickListener++) {
			if (itJoyStickListener->second == joyStickListener) {
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
		
		for (; itKeyListener != mKeyListeners.end(); itKeyListener++) {
			itKeyListener->second->keyPressed(e);
		}
		
		return true;
	}

	bool InputWatcher::keyReleased(const OIS::KeyEvent &e) {
		std::map<std::string, OIS::KeyListener*>::iterator itKeyListener = mKeyListeners.begin();
		
		for (; itKeyListener != mKeyListeners.end(); itKeyListener++) {
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
