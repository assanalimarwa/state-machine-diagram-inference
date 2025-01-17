#include <stdexcept>
struct Event
{
};

enum class State
{
  PHP,
  IDE,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::PHP:
      return "PHP";
    case State::IDE:
      return "IDE";
  }
  return "?";
}

State handle_PHP(Event const & event)
{
  // Check the event and return one of the following states:
  // - PHP
  // - IDE
  return State::PHP;
}

State handle_IDE(Event const & event)
{
  // Check the event and return one of the following states:
  // - IDE
  return State::IDE;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::PHP:
    return handle_PHP(event);
  case State::IDE:
    return handle_IDE(event);
  default:
    throw std::runtime_error("Unknown state " + format_state(last_state));
  }
}

Event wait_for_event()
{
  // TODO fetch next event
  return Event();
}

int main()
{
  State state = State::PHP;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
