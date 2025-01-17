#include <stdexcept>
struct Event
{
};

enum class State
{
  JVM,
  SAS,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::JVM:
      return "JVM";
    case State::SAS:
      return "SAS";
  }
  return "?";
}

State handle_SAS(Event const & event)
{
  // Check the event and return one of the following states:
  // - SAS
  // - JVM
  return State::SAS;
}

State handle_JVM(Event const & event)
{
  // Check the event and return one of the following states:
  // - SAS
  // - JVM
  return State::JVM;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::JVM:
    return handle_JVM(event);
  case State::SAS:
    return handle_SAS(event);
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
  State state = State::SAS;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
