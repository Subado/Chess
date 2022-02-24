#ifndef WORLD_HPP
#define WORLD_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <ResourceIdentifiers.hpp>
#include <ResourceHolder.hpp>
#include <SceneNode.hpp>
#include <array>

class World : private sf::NonCopyable
{
public:
	explicit World(sf::RenderWindow& window);
	void update(sf::Time dt);
	void draw(sf::RenderWindow &window);

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
	TextureHolder m_textures;

	SceneNode m_sceneGraph;
	std::array<SceneNode*, LayerCount>	m_sceneLayers;

	sf::Vector2f m_scaleFactors;

	sf::View m_sceneView;
};

#endif // WORLD_HPP
