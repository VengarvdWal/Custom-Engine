#include "Game.h"

//TODO: Declare all the functions and fill up with copy/pasted code from main.cpp


void Game::CreateShaders()
{
	objectShader = Shader();
	objectShader.CreateFromFiles("Shaders/shader.vert", "Shaders/shader.frag");

	directionalShadowShader = Shader();
	directionalShadowShader.CreateFromFiles("Shaders/directional_shadow_map.vert", "Shaders/directional_shadow_map.frag");
	omniShadowShader = Shader();
	omniShadowShader.CreateFromFiles("Shaders/omni_directional_shadow_map.vert", "Shaders/omni_directional_shadow_map.geom", "Shaders/omni_directional_shadow_map.frag");
}

Game::Game(GLWindow* mainWindow)
{
	this->mainWindow = mainWindow;
}

void Game::Init()
{
	

	brickTexture = Texture("Textures/brick.png");
	brickTexture.LoadTextureA();
	dirtTexture = Texture("Textures/dirt.png");
	dirtTexture.LoadTextureA();
	plainTexture = Texture("Textures/plain.png");
	plainTexture.LoadTextureA();

	shinyMaterial = RenderMaterial(1.0f, 32);
	dullMaterial = RenderMaterial(0.3f, 4);

	mainLight = DirectionalLight(2048, 2048, 1.0f, 1.0f, 1.0f, 0.5f, 0.25f, 0.0f, -15.0f, -10.0f);
	pointLights[0] = PointLight(1024, 1024, 0.1f, 100.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.4f, -2.0f, 2.0f, 0.0f, 0.3f, 0.01f, 0.01f);
	pointLightCount++;
	pointLights[1] = PointLight(1024, 1024, 0.1f, 100.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.4f, 2.0f, 2.0f, 0.0f, 0.3f, 0.01f, 0.01f);
	pointLightCount++;

	spotLights[0] = SpotLight(1024, 1024, 0.1f, 100.0f, 1.0f, 1.0f, 1.0f, 0.0f, 2.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 20.0f);
	spotLightCount++;
	spotLights[1] = SpotLight(1024, 1024, 0.1f, 100.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, -1.5f, 0.0f, -100.0f, -1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 20.0f);
	spotLightCount++;

	camera = Camera(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), -60.0f, 0.0f, 5.0f, 0.5f);

	std::vector<std::string> skyboxFaces;
	skyboxFaces.push_back("Textures/Skybox/cupertin-lake_rt.tga");
	skyboxFaces.push_back("Textures/Skybox/cupertin-lake_lf.tga");
	skyboxFaces.push_back("Textures/Skybox/cupertin-lake_up.tga");
	skyboxFaces.push_back("Textures/Skybox/cupertin-lake_dn.tga");
	skyboxFaces.push_back("Textures/Skybox/cupertin-lake_bk.tga");
	skyboxFaces.push_back("Textures/Skybox/cupertin-lake_ft.tga");

	skybox = Skybox(skyboxFaces);
	

	AddGameObject(std::make_shared<GameObject>("Models/Ground.obj", Vector3(0.0, 5.5, 0.0)));
	AddGameObject(std::make_shared<GameObject>("Models/Ant Hill.obj", Vector3(0.0, 5.5, 0.0)));
	AddGameObject(std::make_shared<Player>("Models/ant.obj", Vector3(0.0, -0.35, 0.0), &physicsManager));
	AddGameObject(std::make_shared<Enemy>("Models/Spiders.obj", Vector3(0.0, -0.35, 0.0), &physicsManager));
	//AddGameObject(std::make_shared<GameObject>("Models/Plantain.obj", Vector3(0.0, -0.35, 0.0), physicsCommon, world));
	//AddGameObject(new GameObject("Models/ant.obj", Vector3(5.0f, 0.0f, 0.0f)));

	CreateShaders();
}

void Game::DirectionalShadowMapPass(DirectionalLight* light)
{
	directionalShadowShader.UseShader();

	glViewport(0, 0, light->GetShadowMap()->GetShadowWidth(), light->GetShadowMap()->GetShadowHeight());

	light->GetShadowMap()->Write();
	glClear(GL_DEPTH_BUFFER_BIT);

	uniformModel = directionalShadowShader.GetModelLocation();
	directionalShadowShader.SetDirectionalLightTransform(&light->CalculateLightTransform());

	directionalShadowShader.Validate();
	RenderScene();

	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void Game::OmniShadowMapPass(PointLight* light)
{
	glViewport(0, 0, light->GetShadowMap()->GetShadowWidth(), light->GetShadowMap()->GetShadowHeight());

	omniShadowShader.UseShader();
	uniformModel = omniShadowShader.GetModelLocation();
	uniformOmniLightPos = omniShadowShader.GetOmniLightPosLocation();
	uniformFarPlane = omniShadowShader.GetFarPlaneLocation();

	light->GetShadowMap()->Write();

	glClear(GL_DEPTH_BUFFER_BIT);

	glUniform3f(uniformOmniLightPos, light->GetPosition().x, light->GetPosition().y, light->GetPosition().z);
	glUniform1f(uniformFarPlane, light->GetFarPlane());
	omniShadowShader.SetOmniLightMatrices(light->CalculateLightTransform());

	omniShadowShader.Validate();
	RenderScene();

	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void Game::RenderScene()
{
	glm::mat4 matrix(1.0f);
	for (size_t i = 0; i < gameObjects.size(); i++)
	{
		matrix = glm::mat4(1.0f);
		//matrix = glm::translate(matrix, glm::vec3(gameObjects[i]->transform.getPosition().x, gameObjects[i]->transform.getPosition().y, gameObjects[i]->transform.getPosition().z));
		//std::cout << "Render Position Object " << i << " " << gameObjects[i]->transform.getPosition().x << " " << gameObjects[i]->transform.getPosition().y << " " << gameObjects[i]->transform.getPosition().z << std::endl;
		matrix = glm::translate(matrix, glm::vec3(gameObjects[i]->getTransform().getPosition().x, gameObjects[i]->getTransform().getPosition().y, gameObjects[i]->getTransform().getPosition().z));
		//matrix = glm::scale(matrix, glm::vec3(1.0f, 1.0f, 1.0f));
		
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(matrix));
		shinyMaterial.UseMaterial(uniformSpecularIntensity, uniformShininess);
		gameObjects[i]->render();
	}
}

void Game::RenderPass(glm::mat4 projectionMatrix, glm::mat4 viewMatrix)
{
	glViewport(0, 0, 1920, 1080);

	// Clear the window
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	skybox.DrawSkybox(viewMatrix, projectionMatrix);

	objectShader.UseShader();

	uniformModel = objectShader.GetModelLocation();
	uniformProjection = objectShader.GetProjectionLocation();
	uniformView = objectShader.GetViewLocation();
	uniformEyePosition = objectShader.GetEyePositionLocation();
	uniformSpecularIntensity = objectShader.GetSpecularIntensityLocation();
	uniformShininess = objectShader.GetShininessLocation();

	glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
	glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(viewMatrix));
	glUniform3f(uniformEyePosition, camera.getCameraPosition().x, camera.getCameraPosition().y, camera.getCameraPosition().z);

	objectShader.SetDirectionalLight(&mainLight);
	objectShader.SetPointLights(pointLights, pointLightCount, 3, 0);
	objectShader.SetSpotLights(spotLights, spotLightCount, 3 + pointLightCount, pointLightCount);
	objectShader.SetDirectionalLightTransform(&mainLight.CalculateLightTransform());

	mainLight.GetShadowMap()->Read(GL_TEXTURE2);
	objectShader.SetTexture(1);
	objectShader.SetDirectionalShadowMap(2);

	/*glm::vec3 lowerLight = camera.getCameraPosition();
	lowerLight.y -= 0.3f;
	spotLights[0].SetFlash(lowerLight, camera.getCameraDirection());*/

	objectShader.Validate();
	RenderScene();
}

void Game::AddGameObject(std::shared_ptr<GameObject> go)
{
	gameObjects.push_back(go);
}

void Game::RemoveGameObject()
{
	//Don't forget to remove memory of gameObject
}

void Game::Run()
{
	glm::mat4 projection = glm::perspective(glm::radians(60.0f), (GLfloat)mainWindow->getBufferWidth() / mainWindow->getBufferHeight(), 0.1f, 1000.0f);
	while (!mainWindow->getShouldClose())
	{
		GLfloat now = glfwGetTime();
		deltaTime = now - lastTime;
		lastTime = now;

		const float timeStep = 1.0f / 60.0f;
				
		// Add the time difference in the accumulator
		accumulator += deltaTime;
		// While there is enough accumulated time to take
		// one or several physics steps
		while (accumulator >= timeStep) {
			// Update the Dynamics world with a constant time step
			physicsManager.update(timeStep);
			// Decrease the accumulated time
			accumulator -= timeStep;
		}

		factor = accumulator / timeStep;

		// Get + Handle User Input
		glfwPollEvents();

		camera.keyControl(mainWindow->getsKeys(), deltaTime);
		camera.mouseControl(mainWindow->getXChange(), mainWindow->getYChange());

		/*if (mainWindow->getsKeys()[GLFW_KEY_L])
		{
			spotLights[0].Toggle();
			mainWindow->getsKeys()[GLFW_KEY_L] = false;
		}*/

		DirectionalShadowMapPass(&mainLight);
		for (size_t i = 0; i < pointLightCount; i++)
		{
			OmniShadowMapPass(&pointLights[i]);
		}
		for (size_t i = 0; i < spotLightCount; i++)
		{
			OmniShadowMapPass(&spotLights[i]);
		}
		RenderPass(projection, camera.calculateViewMatrix());

		glUseProgram(0);

		mainWindow->swapBuffers();
	}
}