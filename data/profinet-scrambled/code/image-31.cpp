#include <stdexcept>
struct Event
{
};

enum class State
{
  JVM,
  OSX,
  PIP,
  ASP,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::JVM:
      return "JVM";
    case State::OSX:
      return "OSX";
    case State::PIP:
      return "PIP";
    case State::ASP:
      return "ASP";
  }
  return "?";
}

State handle_JVM(Event const & event)
{
  // Check the event and return one of the following states:
  // - PIP
  // - OSX
  // - ASP
  return State::JVM;
}

State handle_PIP(Event const & event)
{
  // Check the event and return one of the following states:
  // - PIP
  // - OSX
  // - ASP
  return State::PIP;
}

State handle_OSX(Event const & event)
{
  // Check the event and return one of the following states:
  // - PIP
  // - OSX
  // - ASP
  return State::OSX;
}

State handle_ASP(Event const & event)
{
  // Check the event and return one of the following states:
  // - OSX
  // - ASP
  // - PIP
  return State::ASP;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::JVM:
    return handle_JVM(event);
  case State::OSX:
    return handle_OSX(event);
  case State::PIP:
    return handle_PIP(event);
  case State::ASP:
    return handle_ASP(event);
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
  State state = State::JVM;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
