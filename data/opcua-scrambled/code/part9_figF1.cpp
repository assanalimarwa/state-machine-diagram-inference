#include <stdexcept>
struct Event
{
};

enum class State
{
  TCP,
  IOT,
  OOP,
  IOS,
  IVR,
  API,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::TCP:
      return "TCP";
    case State::IOT:
      return "IOT";
    case State::OOP:
      return "OOP";
    case State::IOS:
      return "IOS";
    case State::IVR:
      return "IVR";
    case State::API:
      return "API";
  }
  return "?";
}

State handle_TCP(Event const & event)
{
  // Check the event and return one of the following states:
  // - IOS
  // - API
  // - OOP
  return State::TCP;
}

State handle_OOP(Event const & event)
{
  // Check the event and return one of the following states:
  // - API
  return State::OOP;
}

State handle_API(Event const & event)
{
  // Check the event and return one of the following states:
  // - IOS
  // - TCP
  // - IOT
  return State::API;
}

State handle_IOS(Event const & event)
{
  // Check the event and return one of the following states:
  // - IVR
  // - API
  // - TCP
  return State::IOS;
}

State handle_IVR(Event const & event)
{
  // Check the event and return one of the following states:
  // - IOS
  return State::IVR;
}

State handle_IOT(Event const & event)
{
  // Check the event and return one of the following states:
  // - TCP
  return State::IOT;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::TCP:
    return handle_TCP(event);
  case State::IOT:
    return handle_IOT(event);
  case State::OOP:
    return handle_OOP(event);
  case State::IOS:
    return handle_IOS(event);
  case State::IVR:
    return handle_IVR(event);
  case State::API:
    return handle_API(event);
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
  State state = State::TCP;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
