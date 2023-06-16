#include "yaSceneManager.h"
#include "yaPlayScene.h"


namespace ya
{
	Scene* SceneManager::mActiveScene = nullptr;
	void SceneManager::Initialize()
	{
		//PlayScene* test = new PlayScene();

		mActiveScene = new PlayScene();
		mActiveScene->Initialize();
	}
	void SceneManager::Update()
	{
		mActiveScene->Update();
	}
	void SceneManager::LateUpdate()
	{
		mActiveScene->LateUpdate();
	}
	void SceneManager::Render()
	{
		mActiveScene->Render();
	}
}
