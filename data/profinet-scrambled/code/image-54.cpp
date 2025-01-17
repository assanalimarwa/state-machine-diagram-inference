#include <stdexcept>
struct Event
{
};

enum class State
{
  TCP,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::TCP:
      return "TCP";
  }
  return "?";
}

State handle_TCP(Event const & event)
{
  // Check the event and return one of the following states:
  // - TCP
  return State::TCP;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::TCP:
    return handle_TCP(event);
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
  State state = State::TCP;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
