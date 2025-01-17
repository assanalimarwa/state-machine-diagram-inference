#include <stdexcept>
struct Event
{
};

enum class State
{
  ICQ,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::ICQ:
      return "ICQ";
  }
  return "?";
}

State handle_ICQ(Event const & event)
{
  // Check the event and return one of the following states:
  // - ICQ
  return State::ICQ;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::ICQ:
    return handle_ICQ(event);
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
  State state = State::ICQ;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
