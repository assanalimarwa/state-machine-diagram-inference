#include <stdexcept>
struct Event
{
};

enum class State
{
  CSS,
  HDD,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::CSS:
      return "CSS";
    case State::HDD:
      return "HDD";
  }
  return "?";
}

State handle_CSS(Event const & event)
{
  // Check the event and return one of the following states:
  // - HDD
  return State::CSS;
}

State handle_HDD(Event const & event)
{
  // Check the event and return one of the following states:
  // - HDD
  return State::HDD;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::CSS:
    return handle_CSS(event);
  case State::HDD:
    return handle_HDD(event);
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
  State state = State::CSS;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
