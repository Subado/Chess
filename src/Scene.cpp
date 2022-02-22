#include <SpriteNode.hpp>
#include <Scene.hpp>
#include <Pawn.hpp>
#include <iostream>
#include <cmath>

Scene::Scene(sf::RenderWindow &window)
	: m_window(window),
	m_sceneView(m_window.getDefaultView())
{
	loadTextures();
	buildScene();
}

void Scene::loadTextures()
{
	m_textures.load(Textures::ID::BlackPawn, "assets/images/black-pawn.png");
	m_textures.load(Textures::ID::WhitePawn, "assets/images/white-pawn.png");
	m_textures.load(Textures::ID::Board, "assets/images/chess-board.png");
}

void Scene::buildScene()
{

	m_sceneGraph.setScale(static_cast<float>(m_window.getSize().x) / m_textures.get(Textures::ID::Board).getSize().x,
						static_cast<float>(m_window.getSize().y) / m_textures.get(Textures::ID::Board).getSize().y);
	for (size_t i = 0; i < LayerCount; i++)
	{
		std::unique_ptr<SceneNode> layer(new SceneNode());

		m_sceneLayers[i] = layer.get();

		m_sceneGraph.attachChild(std::move(layer));
	}

	std::unique_ptr<SpriteNode> board(new SpriteNode(m_textures.get(Textures::ID::Board)));
	
	float m_lengthOfSquare = m_window.getSize().x / 8.f;

	m_sceneLayers[Background]->attachChild(std::move(board));

	std::unique_ptr<Piece> pawn(new Pawn(m_textures, 8, 0, Piece::Color::White, 8));

	pawn->setPosition(m_lengthOfSquare, m_lengthOfSquare * 8);

	m_sceneLayers[Foreground]->attachChild(std::move(pawn));
}

void Scene::buildBoard()
{
}

void Scene::draw(sf::RenderWindow &window)
{
	window.draw(m_sceneGraph);
}

void Scene::update(sf::Time dt)
{

	m_sceneGraph.update(dt);
}
