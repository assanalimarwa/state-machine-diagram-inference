#include <stdexcept>
struct Event
{
};

enum class State
{
  MIM,
  VNC,
  XSS,
  IDE,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::MIM:
      return "MIM";
    case State::VNC:
      return "VNC";
    case State::XSS:
      return "XSS";
    case State::IDE:
      return "IDE";
  }
  return "?";
}

State handle_IDE(Event const & event)
{
  // Check the event and return one of the following states:
  // - IDE
  // - VNC
  return State::IDE;
}

State handle_VNC(Event const & event)
{
  // Check the event and return one of the following states:
  // - VNC
  // - IDE
  // - MIM
  return State::VNC;
}

State handle_MIM(Event const & event)
{
  // Check the event and return one of the following states:
  // - MIM
  // - XSS
  // - IDE
  return State::MIM;
}

State handle_XSS(Event const & event)
{
  // Check the event and return one of the following states:
  // - XSS
  // - IDE
  return State::XSS;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::MIM:
    return handle_MIM(event);
  case State::VNC:
    return handle_VNC(event);
  case State::XSS:
    return handle_XSS(event);
  case State::IDE:
    return handle_IDE(event);
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
  State state = State::IDE;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
