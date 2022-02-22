#ifndef SCENE_NODE_HPP
#define SCENE_NODE_HPP

#include <SFML/Graphics/Transformable.hpp>
#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Transform.hpp>
#include <vector>
#include <memory>

class SceneNode : public sf::Transformable, public sf::Drawable,
				  private sf::NonCopyable
{
	SceneNode *m_parent;
	std::vector<std::unique_ptr<SceneNode>> m_children;

	virtual void updateCurrent(sf::Time dt);
	void updateChildren(sf::Time dt);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const final;
	virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
	void drawChildren(sf::RenderTarget& target, sf::RenderStates states) const;

public:
	SceneNode();

	void attachChild(std::unique_ptr<SceneNode> child);
	std::unique_ptr<SceneNode> detachChild(const SceneNode& node);

	void update(sf::Time dt);

	sf::Transform getWorldTransform() const;
	sf::Vector2f getWorldPosition() const;
};

#endif // SCENE_NODE_HPP
