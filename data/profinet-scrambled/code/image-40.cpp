#include <stdexcept>
struct Event
{
};

enum class State
{
  SDK,
  PPT,
  SSD,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::SDK:
      return "SDK";
    case State::PPT:
      return "PPT";
    case State::SSD:
      return "SSD";
  }
  return "?";
}

State handle_PPT(Event const & event)
{
  // Check the event and return one of the following states:
  // - PPT
  // - SDK
  return State::PPT;
}

State handle_SDK(Event const & event)
{
  // Check the event and return one of the following states:
  // - PPT
  // - SDK
  // - SSD
  return State::SDK;
}

State handle_SSD(Event const & event)
{
  // Check the event and return one of the following states:
  // - SDK
  // - SSD
  // - PPT
  return State::SSD;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::SDK:
    return handle_SDK(event);
  case State::PPT:
    return handle_PPT(event);
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
  State state = State::PPT;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
