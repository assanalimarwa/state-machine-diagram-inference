#include <stdexcept>
struct Event
{
};

enum class State
{
  SDK,
  IPX,
  SSD,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::SDK:
      return "SDK";
    case State::IPX:
      return "IPX";
    case State::SSD:
      return "SSD";
  }
  return "?";
}

State handle_IPX(Event const & event)
{
  // Check the event and return one of the following states:
  // - IPX
  // - SSD
  return State::IPX;
}

State handle_SSD(Event const & event)
{
  // Check the event and return one of the following states:
  // - SSD
  // - IPX
  // - SDK
  return State::SSD;
}

State handle_SDK(Event const & event)
{
  // Check the event and return one of the following states:
  // - SSD
  // - SDK
  // - IPX
  return State::SDK;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::SDK:
    return handle_SDK(event);
  case State::IPX:
    return handle_IPX(event);
  case State::SSD:
    return handle_SSD(event);
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
  State state = State::IPX;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
