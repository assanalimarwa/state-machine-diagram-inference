#include <stdexcept>
struct Event
{
};

enum class State
{
  JDK,
  SLA,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::JDK:
      return "JDK";
    case State::SLA:
      return "SLA";
  }
  return "?";
}

State handle_JDK(Event const & event)
{
  // Check the event and return one of the following states:
  // - JDK
  // - SLA
  return State::JDK;
}

State handle_SLA(Event const & event)
{
  // Check the event and return one of the following states:
  // - SLA
  // - JDK
  return State::SLA;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::JDK:
    return handle_JDK(event);
  case State::SLA:
    return handle_SLA(event);
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
  State state = State::JDK;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
