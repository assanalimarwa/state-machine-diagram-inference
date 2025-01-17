#include <stdexcept>
struct Event
{
};

enum class State
{
  API,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::API:
      return "API";
  }
  return "?";
}

State handle_API(Event const & event)
{
  // Check the event and return one of the following states:
  // - API
  return State::API;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::API:
    return handle_API(event);
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
  State state = State::API;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
