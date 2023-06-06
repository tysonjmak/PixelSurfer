#pragma once

#include "Resource.h"

class Texture : public Resource
{
public:
	// Inherited via Resource
	virtual void load(const std::string& path) override;
	virtual void dispose() override;

	// Bind texture to state machine
	void bind() const;
	void bind(unsigned int slot) const;

	// Unbind texture from state machine
	void unbind() const;

	inline int getWidth() const { return m_width; }
	inline int getHeight() const { return m_height; }

private:
	// OpenGL texture ID
	unsigned int m_ID;

	// Texture info
	int m_width;
	int m_height;
	int m_channels;
	unsigned char* m_data;
};
