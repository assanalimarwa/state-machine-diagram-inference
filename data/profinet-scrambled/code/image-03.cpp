#include <stdexcept>
struct Event
{
};

enum class State
{
  RAM,
  EEP,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::RAM:
      return "RAM";
    case State::EEP:
      return "EEP";
  }
  return "?";
}

State handle_EEP(Event const & event)
{
  // Check the event and return one of the following states:
  // - RAM
  // - EEP
  return State::EEP;
}

State handle_RAM(Event const & event)
{
  // Check the event and return one of the following states:
  // - EEP
  // - RAM
  return State::RAM;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::RAM:
    return handle_RAM(event);
  case State::EEP:
    return handle_EEP(event);
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
  State state = State::EEP;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
