#include "../inc/MysticGE/Input/InputWatcher.hpp"

namespace MysticGE {
namespace Input {
	InputWatcher* InputWatcher::mInputWatcher;

	InputWatcher::InputWatcher(void) :
		mKeyListeners( 0 ),
		mMouseListeners( 0 ),
		mJoyStickListeners( 0 )
	{}

	InputWatcher::~InputWatcher(void)
	{
		removeAllListeners();
	}
	
	InputWatcher* InputWatcher::getSingletonPtr(void)
	{
		if (!mInputWatcher) {
			mInputWatcher = new InputWatcher();
		}
		
		return mInputWatcher;
	}

	void InputWatcher::addKeyListener(const OIS::KeyListener*& keyListener, const std::string& instanceName)
	{
		std::map<std::string, OIS::KeyListener*>::iterator itKeyListener = mKeyListeners.find(instanceName);
		if (itKeyListener == mKeyListeners.end()) {
			mKeyListeners[ instanceName ] = keyListener;
		}

		return;
	}

	void InputWatcher::addMouseListener(const OIS::MouseListener*& mouseListener, const std::string& instanceName)
	{
		std::map<std::string, OIS::MouseListener*>::iterator itMouseListener = mMouseListeners.find(instanceName);
		
		if (itMouseListener == mMouseListeners.end()) {
			mMouseListeners[ instanceName ] = mouseListener;
		}
		
		return;
	}

	void InputWatcher::addJoyStickListener(const OIS::JoyStickListener*& joyStickListener, const std::string& instanceName)
	{
		std::map<std::string, OIS::JoyStickListener*>::iterator itJoyStickListener = mJoyStickListeners.find(instanceName);
		
		if (itJoyStickListener == mJoyStickListeners.end()) {
			mJoyStickListeners[ instanceName ] = joyStickListener;
		}
		
		return;
	}
	
	void InputWatcher::removeKeyListener( const std::string& instanceName )
	{
		std::map<std::string, OIS::KeyListener*>::iterator itKeyListener = mKeyListeners.begin();
		
		for (; itKeyListener != mKeyListeners.end(); itKeyListener++) {
			if (itKeyListener->first == instanceName) {
				mKeyListeners.erase(itKeyListener);
				break;
			}
		}
		
		return;
	}
	
	void InputWatcher::removeMouseListener( const std::string& instanceName )
	{
		std::map<std::string, OIS::MouseListener*>::iterator itMouseListener = mMouseListeners.begin();
		
		for (; itMouseListener != mMouseListeners.end(); itMouseListener++) {
			if (itMouseListener->first == instanceName) {
				mMouseListeners.erase(itMouseListener);
				break;
			}
		}
		
		return;
	}
	
	void InputWatcher::removeJoyStickListener( const std::string& instanceName )
	{
		std::map<std::string, OIS::JoyStickListener*>::iterator itJoyStickListener
			= mJoyStickListeners.begin();
		
		for (; itJoyStickListener != mJoyStickListeners.end(); itJoyStickListener++) {
			if (itJoyStickListener->first == instanceName) {
				mJoyStickListeners.erase(itJoyStickListener);
				break;
			}
		}
		
		return;
	}
	
	void InputWatcher::removeKeyListener(const OIS::KeyListener*& keyListener)
	{
		std::map<std::string, OIS::KeyListener*>::iterator itKeyListener = mKeyListeners.begin();
		
		for (; itKeyListener != mKeyListeners.end(); itKeyListener++) {
			if (itKeyListener->second == keyListener) {
				mKeyListeners.erase(itKeyListener);
				break;
			}
		}
		
		return;
	}
	
	void InputWatcher::removeMouseListener(const OIS::MouseListener*& mouseListener)
	{
		std::map<std::string, OIS::MouseListener*>::iterator itMouseListener = mMouseListeners.begin();
		
		for (; itMouseListener != mMouseListeners.end(); itMouseListener++) {
			if (itMouseListener->second == mouseListener) {
				mMouseListeners.erase(itMouseListener);
				break;
			}
		}
		
		return;
	}

	void InputWatcher::removeJoyStickListener(const OIS::JoyStickListener*& joyStickListener)
	{
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

	void InputWatcher::removeAllListeners(void)
	{
		mKeyListeners.clear();
		mMouseListeners.clear();
		mJoyStickListeners.clear();
		
		return;
	}

	void InputWatcher::removeAllKeyListeners(void)
	{
		mKeyListeners.clear();
		
		return;
	}

	void InputWatcher::removeAllMouseListeners(void)
	{
		mMouseListeners.clear();
		
		return;
	}

	void InputWatcher::removeAllJoyStickListeners(void)
	{
		mJoyStickListeners.clear();
		
		return;
	}

	bool InputWatcher::keyPressed(const OIS::KeyEvent &e)
	{
		std::map<std::string, OIS::KeyListener*>::iterator itKeyListener = mKeyListeners.begin();
		
		for (; itKeyListener != mKeyListeners.end(); itKeyListener++) {
			itKeyListener->second->keyPressed(e);
		}
		
		return true;
	}

	bool InputWatcher::keyReleased(const OIS::KeyEvent &e)
	{
		std::map<std::string, OIS::KeyListener*>::iterator itKeyListener = mKeyListeners.begin();
		
		for (; itKeyListener != mKeyListeners.end(); itKeyListener++) {
			itKeyListener->second->keyReleased(e);
		}
		
		return true;
	}

	bool InputWatcher::mouseMoved(const OIS::MouseEvent &e)
	{
		std::map<std::string, OIS::MouseListener*>::iterator itMouseListener = mMouseListeners.begin();
		
		for (; itMouseListener != mMouseListeners.end(); itMouseListener++) {
			itMouseListener->second->mouseMoved(e);
		}
		
		return true;
	}

	bool InputWatcher::mousePressed(const OIS::MouseEvent &e, OIS::MouseButtonID id) 
	{
		std::map<std::string, OIS::MouseListener*>::iterator itMouseListener = mMouseListeners.begin();
		
		for (; itMouseListener != mMouseListeners.end(); itMouseListener++) {
			itMouseListener->second->mousePressed(e, id);
		}
		
		return true;
	}

	bool InputWatcher::mouseReleased(const OIS::MouseEvent &e, OIS::MouseButtonID id) 
	{
		std::map<std::string, OIS::MouseListener*>::iterator itMouseListener = mMouseListeners.begin();
		
		for (; itMouseListener != mMouseListeners.end(); itMouseListener++) {
			itMouseListener->second->mouseReleased(e, id);
		}
		
		return true;
	}

	bool InputWatcher::povMoved(const OIS::JoyStickEvent &e, int pov) 
	{
		std::map<std::string, OIS::JoyStickListener*>::iterator itJoyStickListener = mJoyStickListeners.end();
		
		for (; itJoyStickListener != mJoyStickListeners.end(); itJoyStickListener++) {
			itJoyStickListener->second->povMoved(e, pov);
		}
		
		return true;
	}

	bool InputWatcher::axisMoved(const OIS::JoyStickEvent &e, int axis) 
	{
		std::map<std::string, OIS::JoyStickListener*>::iterator itJoyStickListener = mJoyStickListeners.end();
		
		for (; itJoyStickListener != mJoyStickListeners.end(); itJoyStickListener++) {
			itJoyStickListener->second->axisMoved(e, axis);
		}
		
		return true;
	}

	bool InputWatcher::sliderMoved(const OIS::JoyStickEvent &e, int sliderID)
	{
		std::map<std::string, OIS::JoyStickListener*>::iterator itJoyStickListener = mJoyStickListeners.end();
		
		for (; itJoyStickListener != mJoyStickListeners.end(); itJoyStickListener++) {
			itJoyStickListener->second->sliderMoved(e, sliderID);
		}
		
		return true;
	}

	bool InputWatcher::buttonPressed(const OIS::JoyStickEvent &e, int button)
	{
		std::map<std::string, OIS::JoyStickListener*>::iterator itJoyStickListener = mJoyStickListeners.end();
		
		for (; itJoyStickListener != mJoyStickListeners.end(); itJoyStickListener++) {
			itJoyStickListener->second->buttonPressed(e, button);
		}
		
		return true;
	}

	bool InputWatcher::buttonReleased(const OIS::JoyStickEvent &e, int button)
	{
		std::map<std::string, OIS::JoyStickListener*>::iterator itJoyStickListener = mJoyStickListeners.end();
		
		for (; itJoyStickListener != mJoyStickListeners.end(); itJoyStickListener++) {
			itJoyStickListener->second->buttonReleased(e, button);
		}
		
		return true;
	}

}
}
