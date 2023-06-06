#pragma once

class Scene
{
public:
	// Called when the scene is activated. Used to load graphics, textures, etc.
	virtual void init() = 0;

	// Called when the scene is deactivated. Used to free any resources, reset scene, etc.
	virtual void dispose() = 0;

	// Called when a scene is pushed to the stack.
	virtual void pause() = 0;

	// Called after a scene is popped from the stack.
	virtual void resume() = 0;

	/**
	 *
	 * First function call in the game loop. Used to handle all input, scene changes, etc.
	 * 
	 * @param dt - Change in time between function calls (between frames)
	 */
	virtual void processInput(float dt) = 0;

	/**
	 *
	 * Second function call in the game loop. Used to update the game's state.
	 *
	 * @param dt - Change in time between functionc alls (between frames)
	 */
	virtual void update(float dt) = 0;

	// Final function call in the game loop. Used to draw all vertices/elements.
	virtual void render() = 0;

	/**
	 * 
	 * Called upon GLFW window size callback event
	 * 
	 * @param
	 * width, height - New window dimensions
	 */
	virtual void resize(float width, float height) = 0;

	// Access scene ID
	const char* getSceneID() const
	{
		return m_scene_ID;
	}

protected:
	Scene(const char* scene_ID) : m_scene_ID(scene_ID) {}

	// Store scene name ID for debugging
	const char* m_scene_ID = "null";
};
