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

#ifndef GRAPHICSMANAGER_OGRE_H
#define GRAPHICSMANAGER_OGRE_H

#include <Ogre.h>
#include <OgreRenderWindow.h>
#include <OgreException.h>

namespace MysticGE {
namespace Graphics {
namespace OGRE {
	
	#define PLUGIN_CONFIG "Plugins.cfg";
	#define GRAPHICS_CONFIG "Ogre.cfg";
	#define RESOURCE_CONFIG "resources.cfg";
	
	class GraphicsManager_OGRE
	{
		public:
			GraphicsManager_OGRE(void);
			~GraphicsManager_OGRE(void);
			
			void initialiseWithSettingsDialog(Ogre::String inWindowTitle);
			void render(void);
			
			Ogre::Root*			getRootNode(void);
			Ogre::RenderWindow*	getRenderWindow(void);
			Ogre::SceneManager*	getSceneManager(void);
			
			Ogre::SceneNode*	createSceneNode(Ogre::String inNodeName);
			Ogre::Entity*		createMesh(Ogre::String inNodeName, Ogre::String inMeshFilename);
			
			void	destroySceneNode(Ogre::String inNodeName);
			void	destroyMesh(Ogre::Entity *inMesh);
			
		private:
			void setupResources(void);
			void loadResources(void);
			
			Ogre::Root			*mRootNode;
			Ogre::RenderWindow	*mRenderWindow;
			Ogre::SceneManager	*mSceneManager;
	};
}
}

#endif // GRAPHICSMANAGER_OGRE_H
