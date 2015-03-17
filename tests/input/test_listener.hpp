/*#include <OISMouse.h>
#include <OISJoyStick.h>
#include <OISKeyboard.h>*/

#include "../../inc/MysticGE/Game/GameManager.hpp"
//#include "../../inc/MysticGE/Input/InputManager.hpp"

namespace MysticGE {
namespace InputTest {
	class TestListener : public OIS::KeyListener, OIS::MouseListener, OIS::JoyStickListener
	{
		public:
			TestListener(void);
			~TestListener(void);
			
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
	};
}
}
