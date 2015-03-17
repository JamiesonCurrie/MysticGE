#include "test_listener.hpp"

namespace {
namespace {
	
	using namespace std;
	
	TestListener::TestListener(void)
	{
		InputManager::getSingletonPtr()->addKeyListener(this, 'Test Key Listener');
		InputManager::getSingletonPtr()->addMouseListener(this, 'Test Mouse Listener');
	}
	
	TestListener::~TestListener(void)
	{
		InputManager::getSingletonPtr()->removeKeyListener('Test Key Listener');
		InputManager::getSingletonPtr()->removeMouseListener('Test Mouse Listener');
		//InputManager::getSingletonPtr()->removeKeyListener(&tester);
		//InputManager::getSingletonPtr()->removeMouseListener(&tester);
	}
	
	//Keyboard
	bool TestListener::keyPressed(const OIS::KeyEvent &e)
	{
		cout << "keyPressed: " << e.key << endl;
	}
	
	bool TestListener::keyReleased(const OIS::KeyEvent &e)
	{
		cout << "keyReleased: " << e.key << endl;
		
		if ( e.key == OIS::KC_ESCAPE ) {
			GameManager::getSingletonPtr()->requestShutdown();
		}
		
		return;
	}
	
	//Mouse
	bool TestListener::mouseMoved(const OIS::MouseEvent &e)
	{
		cout << "mouseMoved: " << endl;
	}
	
	bool TestListener::mousePressed(const OIS::MouseEvent &e, OIS::MouseButtonID id)
	{
		cout << "mousePressed: " << id << endl;
	}
	
	bool TestListener::mouseReleased(const OIS::MouseEvent &e, OIS::MouseButtonID id)
	{
		cout << "mouseReleased: " << id << endl;
	}
	
	//Joystick
	bool TestListener::povMoved(const OIS::JoyStickEvent &e, int pov)
	{}
	
	bool TestListener::axisMoved(const OIS::JoyStickEvent &e, int axis)
	{}
	
	bool TestListener::sliderMoved(const OIS::JoyStickEvent &e, int sliderID)
	{}
	
	bool TestListener::buttonPressed(const OIS::JoyStickEvent &e, int button)
	{}
	
	bool TestListener::buttonReleased(const OIS::JoyStickEvent &e, int button)
	{}
}
}
		