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

#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include "InputDeviceManager.h"
#include "InputWatcher.h"

namespace MysticGE {
namespace Input {
	class InputManager
	{
		public:
			InputManager(size_t inWindowHandle, unsigned int inWidth, unsigned int inHeight);
			virtual ~InputManager(void);
			//static InputManager  getSingleton(void);
			//static InputManager* getSingletonPtr(void);
			
			//void initialise(size_t inWindowHandle, unsigned int inWidth, unsigned int inHeight);
			void capture(void);
			
			//InputWatcher Accesors
			void addKeyListener(OIS::KeyListener *inKeyListener, const std::string& inInstanceName);
			void addMouseListener(OIS::MouseListener *inMouseListener, const std::string& inInstanceName);
			void addJoyStickListener(OIS::JoyStickListener *inJoyStickListener, const std::string& inInstanceName);
			
			void removeKeyListener(const std::string& inInstanceName);
			void removeKeyListener(OIS::KeyListener *inKeyListener);
			void removeMouseListener(const std::string& inInstanceName);
			void removeMouseListener(OIS::MouseListener *inMouseListener);
			void removeJoyStickListener(const std::string& inInstanceName);
			void removeJoyStickListener(OIS::JoyStickListener *inJoyStickListener);
			
			void removeAllListeners(void);
			void removeAllKeyListeners(void);
			void removeAllMouseListeners(void);
			void removeAllJoyStickListeners(void);
			
		private:
			//InputManager(void) {}
			
			InputDeviceManager	mInputDeviceManager;
			InputWatcher		mInputWatcher;
			
			//static InputManager *mInputManager;
	};
}
}

#endif // INPUTMANAGER_H
