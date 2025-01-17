#include <stdexcept>
struct Event
{
};

enum class State
{
  IOS,
  VMX,
  VPS,
  WAP,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::IOS:
      return "IOS";
    case State::VMX:
      return "VMX";
    case State::VPS:
      return "VPS";
    case State::WAP:
      return "WAP";
  }
  return "?";
}

State handle_VMX(Event const & event)
{
  // Check the event and return one of the following states:
  // - WAP
  return State::VMX;
}

State handle_WAP(Event const & event)
{
  // Check the event and return one of the following states:
  // - VPS
  // - IOS
  return State::WAP;
}

State handle_VPS(Event const & event)
{
  // Check the event and return one of the following states:
  // - VPS
  // - IOS
  return State::VPS;
}

State handle_IOS(Event const & event)
{
  // Check the event and return one of the following states:
  // - VPS
  return State::IOS;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::IOS:
    return handle_IOS(event);
  case State::VMX:
    return handle_VMX(event);
  case State::VPS:
    return handle_VPS(event);
  case State::WAP:
    return handle_WAP(event);
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
  State state = State::VMX;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
