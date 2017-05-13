# Newton Engine
The Newton Engine is a 2-D Game Engine being developed for a project at Universidade Federal do Rio Grande (http://furg.br) by Giovgiac. This engine has the intention of creating a simple Space Invaders-like game, with basic graphics, audio and font rendering capabilities.

### Example Code
The following snippet of code shows a Main.cpp that utilizes the NEngine for creating a simple scene where there's a player that can move around with the W, A, S and D keys. The scene also presents another GameObject which is stationary.
This code could be easily extended, to draw even up to more than 50.000 sprites (tested on a GTX 1080) and it does not showcase the full capabilities of the NEngine. For instance, the GameObject class can be inherited from and overriding the Start and Tick methods allow for more diversified behavior of different objects.
```cpp
/**
 * Main.cpp
 *
 * Copyright (c) Giovanni Giacomo. All Rights Reserved.
 *
 */

#include <Core/Game.h>

using namespace Newton;

class MyPlayer : public NPlayer {
public:
	MyPlayer(const NVector& InPosition, const GLfloat InRotation, const NVector& InSize, NTexture* InTexture)
		: NPlayer(InPosition, InRotation, InSize, NColor::White(), InTexture) {}

	virtual void OnKeyDown(GLint InKey, GLint InScancode, GLint InAction, GLint InMods) override {
		// Handle Input for Movement and Game Exit
		if (InKey == GLFW_KEY_W && (InAction == GLFW_PRESS || InAction == GLFW_REPEAT))
			Translate(NVector(0.0f, 2.0f));
		else if (InKey == GLFW_KEY_S && (InAction == GLFW_PRESS || InAction == GLFW_REPEAT))
			Translate(NVector(0.0f, -2.0f));
		else if (InKey == GLFW_KEY_A && (InAction == GLFW_PRESS || InAction == GLFW_REPEAT))
			Translate(NVector(-2.0f, 0.0f));
		else if (InKey == GLFW_KEY_D && (InAction == GLFW_PRESS || InAction == GLFW_REPEAT))
			Translate(NVector(2.0f, 0.0f));
		else if (InKey == GLFW_KEY_ESCAPE && InAction == GLFW_PRESS)
			exit(EXIT_SUCCESS);
	}

	virtual void OnMouseDown(GLint InButton, GLint InAction, GLint InMods) override {}
	virtual void OnMouseMove(GLdouble InX, GLdouble InY) override {}
};

class MyGame : public NGame {
public:
	MyGame(void)
		: NGame() {}

	void BeforePlay(void) override {
		NScene Scene;
		
		// Create Objects
		NTexture* GokuTexture = new NTexture("goku.png");
		NPlayer* NewPlayer = new MyPlayer(NVector(640.0f, 384.0f), 0.0f, NVector(50.f, 50.f), GokuTexture);
		NGameObject* Object0 = new NGameObject(NVector(320.0f, 192.0f), 0.0f, NVector(50.0f, 50.0f), NColor(), GokuTexture);

		// Add Objects to Scene
		SetPlayer(NewPlayer);
		Scene.AddObject(NewPlayer);
		Scene.AddObject(Object0);

		// Send Scene to World
		World->LoadScene(Scene);
	}
};

int main(void) {
	MyGame Game;
	Game.Play();
}
```