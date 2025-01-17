#include <stdexcept>
struct Event
{
};

enum class State
{
  DNS,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::DNS:
      return "DNS";
  }
  return "?";
}

State handle_DNS(Event const & event)
{
  // Check the event and return one of the following states:
  // - DNS
  return State::DNS;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::DNS:
    return handle_DNS(event);
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
  State state = State::DNS;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
