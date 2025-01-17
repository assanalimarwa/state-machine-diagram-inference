#include <stdexcept>
struct Event
{
};

enum class State
{
  SDK,
  HDD,
  SLA,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::SDK:
      return "SDK";
    case State::HDD:
      return "HDD";
    case State::SLA:
      return "SLA";
  }
  return "?";
}

State handle_SLA(Event const & event)
{
  // Check the event and return one of the following states:
  // - SLA
  // - HDD
  return State::SLA;
}

State handle_HDD(Event const & event)
{
  // Check the event and return one of the following states:
  // - SLA
  // - HDD
  // - SDK
  return State::HDD;
}

State handle_SDK(Event const & event)
{
  // Check the event and return one of the following states:
  // - SDK
  // - SLA
  return State::SDK;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::SDK:
    return handle_SDK(event);
  case State::HDD:
    return handle_HDD(event);
  case State::SLA:
    return handle_SLA(event);
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
  State state = State::SLA;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
