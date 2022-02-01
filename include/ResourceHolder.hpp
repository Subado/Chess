#ifndef RESOURCE_HOLDER_
#define RESOURCE_HOLDER_

#include <SFML/Graphics/Texture.hpp>
#include <stdexcept>
#include <cassert>
#include <string>
#include <memory>
#include <map>

template <typename Resource, typename Identifier>
class ResourceHolder
{
	std::map<Identifier, std::unique_ptr<Resource>> m_resourceMap;
public:
	void load(Identifier id, const std::string& filename);
	template <typename Parameter>
	void load(Identifier id, const std::string& filename, const Parameter &secondParam);
	Resource& get(Identifier id);
	const Resource& get(Identifier id) const;
	void insertResource(Identifier id, std::unique_ptr<Resource> resource);
};

#include <ResourceHolder.inl>


namespace Textures
{
	enum class ID { Board, PossibleMove, Pawn, Rook, Knight, Bishop, King, Queen};
}
typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;


#endif // RESOURCE_HOLDER_
