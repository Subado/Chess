#include <StateStack.hpp>
#include <cassert>

State::Ptr StateStack::createState(States::ID stateID)
{
	auto found = m_factories.find(stateID);
#ifdef DEBUG
	assert(found != m_factories.end());
#endif

	return found->second();
}
