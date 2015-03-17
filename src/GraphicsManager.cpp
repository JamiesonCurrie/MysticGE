#include "../inc/MysticGE/Graphics/GraphicsManager.hpp"

namespace MysticGE {
namespace Graphics {
	
	GraphicsManager::GraphicsManager(void) : 
		mRootNode( 0 ),
		mRenderWindow( 0 ),
		mSceneManager( 0 )
	{ }

	GraphicsManager::~GraphicsManager(void) 
	{
		delete mRootNode;
	}

	void GraphicsManager::initialiseWithSettingsDialog(Ogre::String inWindowTitle) 
	{
		mRootNode = new Ogre::Root(PLUGIN_CONFIG, GRAPHICS_CONFIG);
		mRootNode->showConfigDialog();
		mRootNode->initialise(true, inWindowTitle);
		mRootNode->saveConfig();
		mRenderWindow = mRootNode->getAutoCreatedWindow();
		
		setupResources();
		
		mSceneManager = mRootNode->createSceneManager(Ogre::ST_GENERIC, "DefaultSceneManager");
		
		return;
	}

	void GraphicsManager::render(void) 
	{
		mRootNode->renderOneFrame();
		
		return;
	}

	void GraphicsManager::setupResources(void) 
	{
		Ogre::ConfigFile cf;
		cf.load(RESOURCE_CONFIG);
		
		Ogre::ConfigFile::SectionIterator itSection = cf.getSectionIterator();
		
		Ogre::String section, type, arch;
		while (itSection.hasMoreElements()) {
			section = itSection.peekNextKey();
			Ogre::ConfigFile::SettingsMultiMap* mapSettings = itSection.getNext();
			Ogre::ConfigFile::SettingsMultiMap::iterator itSettings = mapSettings->begin();
			while (itSettings != mapSettings->end()) {
				type = itSettings->first;
				arch = itSettings->second;
				
				Ogre::ResourceGroupManager::getSingleton().addResourceLocation(arch, type, section);
				
				++itSettings;
			}
		}
		
		Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
		
		return;
	}

	Ogre::Root* GraphicsManager::getRootNode(void) 
	{
		return mRootNode;
	}

	Ogre::RenderWindow* GraphicsManager::getRenderWindow(void) 
	{
		return mRenderWindow;
	}

	Ogre::SceneManager* GraphicsManager::getSceneManager(void) 
	{
		return mSceneManager;
	}

	Ogre::SceneNode* GraphicsManager::createSceneNode(Ogre::String inNodeName) 
	{
		return mSceneManager->getRootSceneNode()->createChildSceneNode(inNodeName);
	}

	Ogre::Entity* GraphicsManager::createMesh(Ogre::String inNodeName, Ogre::String inMeshFilename) 
	{
		return mSceneManager->createEntity(inNodeName, inMeshFilename);
	}

	void GraphicsManager::destroySceneNode(Ogre::String inNodeName) 
	{
		mSceneManager->destroySceneNode(inNodeName);
		
		return;
	}

	void GraphicsManager::destroyMesh(Ogre::Entity* inMesh) 
	{
		mSceneManager->destroyEntity(inMesh);
		
		return;
	}

}
}
