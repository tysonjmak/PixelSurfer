#include "InputManager.h"

InputManager::InputManager() : 
	m_key_states(),
	m_prev_key_states() { }

void InputManager::setKeyState(int key, bool state)
{
	m_key_states[key] = state;
}

void InputManager::setPrevKeyState(int key, bool state)
{
	m_prev_key_states[key] = state;
}

bool InputManager::isKeyDown(int key)
{
	return m_key_states[key];
}

bool InputManager::isKeyUp(int key)
{
	return !m_key_states[key];
}

bool InputManager::isKeyPressed(int key)
{
	if (m_key_states[key] && !m_prev_key_states[key])
	{
		m_prev_key_states[key] = true;
		return true;
	}

	return false;
}

bool InputManager::isKeyReleased(int key)
{
	if (!m_key_states[key] && m_prev_key_states[key])
	{
		m_prev_key_states[key] = false;
		return true;
	}

	return false;
}
