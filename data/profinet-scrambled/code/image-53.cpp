#include <stdexcept>
struct Event
{
};

enum class State
{
  AES,
  IVR,
  DNS,
  IDE,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::AES:
      return "AES";
    case State::IVR:
      return "IVR";
    case State::DNS:
      return "DNS";
    case State::IDE:
      return "IDE";
  }
  return "?";
}

State handle_AES(Event const & event)
{
  // Check the event and return one of the following states:
  // - DNS
  return State::AES;
}

State handle_DNS(Event const & event)
{
  // Check the event and return one of the following states:
  // - IVR
  // - IDE
  return State::DNS;
}

State handle_IVR(Event const & event)
{
  // Check the event and return one of the following states:
  // - IVR
  // - IDE
  return State::IVR;
}

State handle_IDE(Event const & event)
{
  // Check the event and return one of the following states:
  // - IVR
  // - IDE
  return State::IDE;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::AES:
    return handle_AES(event);
  case State::IVR:
    return handle_IVR(event);
  case State::DNS:
    return handle_DNS(event);
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
  State state = State::AES;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
