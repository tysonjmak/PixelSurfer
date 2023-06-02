#pragma once

const unsigned short NUM_KEYS = 349;

class InputManager
{
private:
    // Booleans of all GLFW keys that return up/down states
	bool m_key_states[NUM_KEYS];

    // Booleans of the previous stored key states
    bool m_prev_key_states[NUM_KEYS];

public:
	InputManager();
	
	/**
     *
     * Sets the boolean value state of a key given the GLFW key index
     *
     * @param key - GLFW key index to set state of
     * @param state - Boolean value of key state to set
     */
	void setKeyState(int key, bool state);

    /**
     * 
     * Sets the boolean value state of a key's previous state
     * 
     * @param key - GLFW key index to set previous state of
     * @param state - Boolean value of previous key state to set
     */
    void setPrevKeyState(int key, bool state);

	/**
     *
     * Returns whether the passed key index is in a pressed state
     *
     * @param key - GLFW key index to get state of
     * 
     * @return Whether given key is in a pressed state
     */
	bool isKeyDown(int key);
	
	/**
     *
     * Returns whether the passed key index is in a released state
     *
     * @param key - GLFW key index to get state of
     * 
     * @return Whether given key is in a released state
     */
	bool isKeyUp(int key);

    /**
     * 
     * Returns whether the passed key index has been pressed just once
     * 
     * @param key - GLFW key index to get state of
     * 
     * @return Whether given key has just been pressed
     */
	bool isKeyPressed(int key);

    /**
     * 
     * Returns whether the passed key index has been released just once
     *
     * @param key - GLFW key index to get state of
     * 
     * @return Whether given key has just been released
     */
	bool isKeyReleased(int key);
};
