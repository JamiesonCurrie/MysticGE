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

#include "include/Graphics/OGRE/GraphicsManager_OGRE.h"

namespace MysticGE {
namespace Graphics {
namespace OGRE {
	
GraphicsManager_OGRE::GraphicsManager_OGRE(void) {
	mRootNode = new Ogre::Root(PLUGIN_CONFIG, GRAPHICS_CONFIG);
}

GraphicsManager_OGRE::~GraphicsManager_OGRE(void) {
	delete mRootNode;
}

void GraphicsManager_OGRE::initialiseWithSettingsDialog(Ogre::String inWindowTitle) {
	mRootNode->showConfigDialog();
	mRootNode->initialise(true, inWindowTitle);
	mRootNode->saveConfig();
	mRenderWindow = mRootNode->getAutoCreatedWindow();
	
	setupResources();
	
	mSceneManager = mRootNode->createSceneManager(Ogre::ST_GENERIC, "DefaultSceneManager");
	
	return;
}

void GraphicsManager_OGRE::render(void) {
	mRootNode->renderOneFrame();
	return;
}

void GraphicsManager_OGRE::setupResources(void) {
	Ogre::ConfigFile cf;
	cf.load(RESOURCE_CONFIG);
	
	Ogre::ConfigFile::SectionIterator itSection = cf.getSectionIterator();
	
	Ogre::String section, type, arch;
	while (itSection.hasMoreElements()) {
		section = itSection.peekNextKey();
		Ogre::ConfigFile::SettingsMultiMap *mapSettings = itSection.getNext();
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

Ogre::Root* GraphicsManager_OGRE::getRootNode(void) {
	return mRootNode;
}

Ogre::RenderWindow* GraphicsManager_OGRE::getRenderWindow(void) {
	return mRenderWindow;
}

Ogre::SceneManager* GraphicsManager_OGRE::getSceneManager(void) {
	return mSceneManager;
}

Ogre::SceneNode* GraphicsManager_OGRE::createSceneNode(Ogre::String inNodeName) {
	return mSceneManager->getRootSceneNode()->createChildSceneNode(inNodeName);
}

Ogre::Entity* GraphicsManager_OGRE::createMesh(Ogre::String inNodeName, Ogre::String inMeshFilename) {
	return mSceneManager->createEntity(inNodeName, inMeshFilename);
}

void GraphicsManager_OGRE::destroySceneNode(Ogre::String inNodeName) {
	mSceneManager->destroySceneNode(inNodeName);
	return;
}

void GraphicsManager_OGRE::destroyMesh(Ogre::Entity* inMesh) {
	mSceneManager->destroyEntity(inMesh);
	return;
}

}
}
}
