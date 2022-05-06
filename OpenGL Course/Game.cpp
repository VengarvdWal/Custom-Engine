#include "Game.h"

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
	physicsManager = std::make_unique<PhysicsManager>();

	camera = Camera(glm::vec3(4.0f, 2.0f, 4.0f), glm::vec3(0.0f, 1.0f, 0.0f), 0.0f, 0.0f, 5.0f, 0.5f);
	shinyMaterial = RenderMaterial(1.0f, 32);
	dullMaterial = RenderMaterial(0.3f, 4);

#pragma region Lights Init

	mainLight = DirectionalLight(2048, 2048, 1.0f, 1.0f, 1.0f, 0.5f, 0.25f, 0.0f, -15.0f, -10.0f);
	pointLights[0] = PointLight(1024, 1024, 0.1f, 100.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.4f, -2.0f, 2.0f, 0.0f, 0.3f, 0.01f, 0.01f);
	pointLightCount++;
	pointLights[1] = PointLight(1024, 1024, 0.1f, 100.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.4f, 2.0f, 2.0f, 0.0f, 0.3f, 0.01f, 0.01f);
	pointLightCount++;

	spotLights[0] = SpotLight(1024, 1024, 0.1f, 100.0f, 1.0f, 1.0f, 1.0f, 0.0f, 2.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 20.0f);
	spotLightCount++;
	spotLights[1] = SpotLight(1024, 1024, 0.1f, 100.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, -1.5f, 0.0f, -100.0f, -1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 20.0f);
	spotLightCount++;
#pragma endregion

#pragma region Skybox Init

	std::vector<std::string> skyboxFaces;
	skyboxFaces.push_back("Textures/Skybox/CosmicCoolCloudLeft.tga");
	skyboxFaces.push_back("Textures/Skybox/CosmicCoolCloudRight.tga");
	skyboxFaces.push_back("Textures/Skybox/CosmicCoolCloudTop.tga");
	skyboxFaces.push_back("Textures/Skybox/CosmicCoolCloudBottom.tga");
	skyboxFaces.push_back("Textures/Skybox/CosmicCoolCloudFront.tga");
	skyboxFaces.push_back("Textures/Skybox/CosmicCoolCloudBack.tga");
	skybox = Skybox(skyboxFaces);
#pragma endregion

#pragma region GameObjects Init

	AddGameObject(std::make_shared<GameObject>("Models/Plane.obj", physicsManager.get(), BodyType::STATIC, Vector3(10, 0.05, 10), Vector3(0, 0, 0)));
	AddGameObject(std::make_shared<GameObject>("Models/Target.obj", physicsManager.get(), BodyType::STATIC, Vector3(0.8, 2, 0.8), Vector3(5, 2, 5)));
	AddGameObject(std::make_shared<GameObject>("Models/igloo.obj", physicsManager.get(), BodyType::STATIC, Vector3(0.8, 2, 0.8), Vector3(0, 0, 0)));
	AddGameObject(std::make_shared<GameObject>("Models/tree.obj", physicsManager.get(), BodyType::STATIC, Vector3(0.8, 2, 0.8), Vector3(1.5, 0, 1.5)));
	AddGameObject(std::make_shared<GameObject>("Models/tree.obj", physicsManager.get(), BodyType::STATIC, Vector3(0.8, 2, 0.8), Vector3(8.75, 0, 8.75)));
	AddGameObject(std::make_shared<GameObject>("Models/tree.obj", physicsManager.get(), BodyType::STATIC, Vector3(0.8, 2, 0.8), Vector3(7.5, 0, 9.5)));
	AddGameObject(std::make_shared<GameObject>("Models/tree.obj", physicsManager.get(), BodyType::STATIC, Vector3(0.8, 2, 0.8), Vector3(-7.5, 0, 9.5)));
	AddGameObject(std::make_shared<GameObject>("Models/tree.obj", physicsManager.get(), BodyType::STATIC, Vector3(0.8, 2, 0.8), Vector3(-8.75, 0, 8.75)));

	AddGameObject(std::make_shared<GameObject>("Models/snowman.obj", physicsManager.get(), BodyType::STATIC, Vector3(0.8, 2, 0.8), Vector3(-1.5, 0, -1.5)));
#pragma endregion

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
		matrix = glm::translate(matrix, glm::vec3(gameObjects[i]->getTransform().getPosition().x, gameObjects[i]->getTransform().getPosition().y, gameObjects[i]->getTransform().getPosition().z));

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

	objectShader.Validate();
	RenderScene();
}

void Game::AddGameObject(std::shared_ptr<GameObject> go)
{
	gameObjects.push_back(go);
}

void Game::RemoveGameObject(std::shared_ptr<GameObject> go)
{
	physicsManager->DestroyGameObject(go->getRigidBody());
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
			physicsManager->update(timeStep);
			// Decrease the accumulated time
			accumulator -= timeStep;
		}

		factor = accumulator / timeStep;

		// Get + Handle User Input
		glfwPollEvents();

		camera.keyControl(mainWindow->getsKeys(), deltaTime);
		camera.mouseControl(mainWindow->getXChange(), mainWindow->getYChange());

		float currentTime = glfwGetTime();
		const float cooldown = 0.5;

		if (mainWindow->getClick())
		{
			if (currentTime - snowballLastTime >= cooldown)
			{
				ThrowableSnowball = std::make_shared<GameObject>("Models/Snowball.obj", physicsManager.get(), BodyType::DYNAMIC, Vector3(0.05, 0.05, 0.05),
					Vector3(camera.getCameraPosition3D() + offset));

				currentSnowball = ThrowableSnowball;
				AddGameObject(currentSnowball);
				currentSnowball->moveControl(mainWindow->getClick(), camera.getCameraDirection());
				snowballLastTime = currentTime;
			}
		}

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