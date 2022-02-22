#ifndef SCENE_HPP
#define SCENE_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <ResourceHolder.hpp>
#include <SceneNode.hpp>
#include <array>

class Scene : private sf::NonCopyable
{
	enum Layer
	{
		Background,
		Foreground,
		LayerCount
	};

	void loadTextures();
	void buildScene();
	void buildBoard();

	sf::RenderWindow& m_window;
	TextureHolder m_textures;

	SceneNode m_sceneGraph;
	std::array<SceneNode*, LayerCount>	m_sceneLayers;

	sf::Vector2f m_scaleFactors;

	sf::View m_sceneView;
public:
	explicit Scene(sf::RenderWindow& window);
	void update(sf::Time dt);
	void draw(sf::RenderWindow &window);
};

#endif // SCENE_HPP
