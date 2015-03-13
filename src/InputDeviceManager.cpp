#include "../inc/MysticGE/Input/InputDeviceManager.hpp"

namespace MysticGE {
namespace Input {

	InputDeviceManager* InputDeviceManager::mInputDeviceManager;

	InputDeviceManager::InputDeviceManager( void ) :
		mMouse( 0 ),
		mKeyboard( 0 ),
		mInputSystem( 0 )
	{}
	
	InputDeviceManager::~InputDeviceManager(void) 
	{
		if (mInputSystem) {
			if (mMouse) {
				mInputSystem->destroyInputObject(mMouse);
				mMouse = 0;
			}
			if (mKeyboard) {
				mInputSystem->destroyInputObject(mKeyboard);
				mKeyboard = 0;
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

	InputDeviceManager* InputDeviceManager::getSingletonPtr( void )
	{
		if ( !mInputdeviceManager ) {
			mInputDeviceManager = new InputDeviceManager();
		}

		return mInputDeviceManager;
	}

	InputDeviceManager::initialise( const Ogre::RenderWindow& renderWindow )
	{
		OIS::ParamList paramList;
		size_t windowHnd = 0;
		std::ostringstream windowHndStr;

#if defined OIS_WIN32_PLATFORM
		renderWindow.getcustomAttribute( "WINDOW", &windowHnd );
#elif defined OIS_LINUX_PLATFORM
		renderWindow.getCustomeAttribute( "GLXWINDOW", &windowHnd );
#endif

		windowHndStr << (unsigned int) windowHnd;
		paramList.insert(std::make_pair(std::string("WINDOW"), windowHndStr.str()));

		mInputSystem = OIS::InputManager::createInputSystem( paramList );
		
		if (mInputSystem->getNumberOfDevices(OIS::OISKeyboard) > 0) {
			mKeyboard = static_cast<OIS::Keyboard*>(mInputSystem->createInputObject(OIS::OISKeyboard, true));
			mKeyboard->setTextTranslation(OIS::Keyboard::Ascii);
		}
		
		if (mInputSystem->getNumberOfDevices(OIS::OISMouse) > 0) {
			mMouse = static_cast<OIS::Mouse*>(mInputSystem->createInputObject(OIS::OISMouse, true));

			unsigned int width, height, depth;
			int left, top;
			renderWindow.getMetrics(width, height, depth, left, top);
			setWindowExtents(width, height);
		}
		
		if (mInputSystem->getNumberOfDevices(OIS::OISJoyStick) > 0) {
			mJoySticks.resize(mInputSystem->getNumberOfDevices(OIS::OISJoyStick));
			std::vector<OIS::JoyStick*>::iterator itJoySticks = mJoySticks.begin();
			for (; itJoySticks != mJoySticks.end(); mJoySticks++) {
				(*itJoySticks) = static_cast<OIS::JoyStick*>(mInputSystem->createInputObject(OIS::OISJoyStick, true));
			}
		}
	}
	
	void InputDeviceManager::capture(void) 
	{
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

	void InputDeviceManager::setWindowExtents(unsigned int width, unsigned int height)
	{
		mMouse->getMouseState().width = width;
		mMouse->getMouseState().height = height;
		
		return;
	}
	
	void InputDeviceManager::setKeyboardEventListener(const OIS::KeyListener*& listener)
	{
		if (mKeyboard) {
			mKeyboard->setEventCallback(listener);
		}
	}
	
	void InputDeviceManager::setMouseEventListener(const OIS::MouseListener*& listener)
	{
		if (mMouse) {
			mMouse->setEventCallback(listener);
		}
	}
	
	void InputDeviceManager::setJoyStickEventListener(const OIS::JoyStickListener*& listener)
	{
		if (getNumberOfJoySticks() > 0) {
			std::vector<OIS::JoyStick*>::iterator itJoySticks = mJoySticks.begin();
			for (; itJoySticks != mJoySticks.end(); mJoySticks++) {
				(*itJoySticks)->setEventCallback(listener);
			}
		}
	}

	OIS::Mouse* InputDeviceManager::getMouse(void)
	{
		return mMouse;
	}

	OIS::Keyboard* InputDeviceManager::getKeyboard(void)
	{
		return mKeyboard;
	}

	OIS::JoyStick* InputDeviceManager::getJoyStick(unsigned int index)
	{
		if (index > 0 && index < mJoySticks.size()) {
			return mJoySticks[index];
		}
		
		return NULL;
	}

	int InputDeviceManager::getNumberOfJoySticks(void)
	{
		return (int) mJoySticks.size();
	}

}
}
