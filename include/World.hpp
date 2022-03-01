#ifndef WORLD_HPP
#define WORLD_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <ResourceHolder.hpp>
#include <CommandQueue.hpp>
#include <ResourceIDs.hpp>
#include <SceneNode.hpp>
#include <array>

class World : private sf::NonCopyable
{
public:
	explicit World(sf::RenderWindow& window);
	void update(sf::Time dt);
	void draw();

	CommandQueue &getCommandQueue();

private:
	void loadTextures();
	void buildWorld();

	enum Layer
	{
		Background,
		Foreground,
		LayerCount
	};

	sf::RenderWindow& m_window;
	sf::View m_worldView;
	TextureHolder m_textures;

	SceneNode m_sceneGraph;
	std::array<SceneNode*, LayerCount>	m_sceneLayers;
	CommandQueue m_commandQueue;

	float m_lengthOfSquare;
};

#endif // WORLD_HPP
