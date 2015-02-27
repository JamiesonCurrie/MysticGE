#include "../inc/MysticGE/Input/InputManager.hpp"

namespace MysticGE {
namespace Input {
	
	InputManager* InputManager::mInputManager;

	InputManager::InputManager( void ) : 
		mInputDeviceManager( 0 ),
		mInputwatcher( 0 )
	{}

	void InputManager::initialise( Ogre::RenderWindow *renderWindow )
	{
		mInputDeviceManager	= InputDeviceManager::getSingletonPtr();
		mInputWatcher		= new InputWatcher();
		
		mInputDeviceManager->initialise(renderWindow);
		mInputDeviceManager->setEventCallbackWatcher(&mInputWatcher);

		return;
	}

	InputManager::~InputManager() {
		delete mInputWatcher;
		delete mInputDeviceManager;
	}

	InputManager* InputManager::getSingletonPtr(void) {
		if (!mInputManager) {
			mInputManager = new InputManager();
		}
		
		return mInputManager;
	}


	void InputManager::capture(void) {
		mInputDeviceManager->capture();
		
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
