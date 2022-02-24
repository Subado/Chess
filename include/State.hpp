#ifndef STATE_HPP
#define STATE_HPP

#include <SFML/Window/Event.hpp>
#include <SFML/System/Time.hpp>
#include <StateIdentifiers.hpp>

class StateStack;

class State
{
public:
	typedef std::unique_ptr<State> Ptr;

	struct Context
	{

	};

	State(StateStack& stack, Context context);
	virtual ~State();

	virtual void draw() = 0;
	virtual bool update(sf::Time dt);
	virtual bool handleEvent(const sf::Event& event) = 0;

protected:
	void requestStackPush(States::ID stateID);
	void requestStackPop();
	void requestStackClear();

	Context getContext() const;

private:
	StateStack *m_stack;
	Context m_context;
};

#endif // STATE_HPP
