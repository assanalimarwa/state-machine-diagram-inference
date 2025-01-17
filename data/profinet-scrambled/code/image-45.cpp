#include <stdexcept>
struct Event
{
};

enum class State
{
  WWW,
  VNC,
  VPS,
  EHR,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::WWW:
      return "WWW";
    case State::VNC:
      return "VNC";
    case State::VPS:
      return "VPS";
    case State::EHR:
      return "EHR";
  }
  return "?";
}

State handle_WWW(Event const & event)
{
  // Check the event and return one of the following states:
  // - VNC
  return State::WWW;
}

State handle_VNC(Event const & event)
{
  // Check the event and return one of the following states:
  // - VNC
  // - VPS
  // - EHR
  return State::VNC;
}

State handle_VPS(Event const & event)
{
  // Check the event and return one of the following states:
  // - VPS
  // - EHR
  return State::VPS;
}

State handle_EHR(Event const & event)
{
  // Check the event and return one of the following states:
  // - WWW
  return State::EHR;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::WWW:
    return handle_WWW(event);
  case State::VNC:
    return handle_VNC(event);
  case State::VPS:
    return handle_VPS(event);
  case State::EHR:
    return handle_EHR(event);
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
  State state = State::WWW;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
