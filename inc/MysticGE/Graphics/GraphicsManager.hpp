#ifndef GRAPHICSMANAGER_HPP
#define GRAPHICSMANAGER_HPP

#include <Ogre.h>
#include <OgreRenderWindow.h>
#include <OgreException.h>

namespace MysticGE {
namespace Graphics {
	class GraphicsManager
	{
		public:
			~GraphicsManager(void);
			static GraphicsManager* getSingletonPtr(void);
			
			void initialiseWithSettingsDialog(Ogre::String inWindowTitle);
			void render(void);
			
			static Ogre::String PLUGIN_CONFIG   = "../../../resources/plugins.cfg";
			static Ogre::String GRAPHICS_CONFIG = "../../../resources/ogre.cfg";
			static Ogre::String RESOURCE_CONFIG = "../../../resources/resources.cfg";
			
			Ogre::Root*			getRootNode(void);
			Ogre::RenderWindow*	getRenderWindow(void);
			Ogre::SceneManager*	getSceneManager(void);
			Ogre::SceneNode*	createSceneNode(Ogre::String inNodeName);
			Ogre::Entity*		createMesh(Ogre::String inNodeName, Ogre::String inMeshFilename);
			
			void destroySceneNode(Ogre::String inNodeName);
			void destroyMesh(Ogre::Entity* inMesh); 
			
		private:
			GraphicsManager(void);
			GraphicsManager( const GraphicsManager& ) {}
			GraphicsManager & operator = ( const GraphicsManager& );
			
			void setupResources(void);
			
			Ogre::Root			*mRootNode;
			Ogre::RenderWindow	*mRenderWindow;
			Ogre::SceneManager	*mSceneManager;
			
			static GraphicsManager *mGraphicsManager;
	};
}
}

#endif // GRAPHICSMANAGER_OGRE_H
