#include <stdexcept>
struct Event
{
};

enum class State
{
  CPU,
  LTE,
  CRT,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::CPU:
      return "CPU";
    case State::LTE:
      return "LTE";
    case State::CRT:
      return "CRT";
  }
  return "?";
}

State handle_LTE(Event const & event)
{
  // Check the event and return one of the following states:
  // - LTE
  // - CRT
  return State::LTE;
}

State handle_CRT(Event const & event)
{
  // Check the event and return one of the following states:
  // - LTE
  // - CRT
  // - CPU
  return State::CRT;
}

State handle_CPU(Event const & event)
{
  // Check the event and return one of the following states:
  // - CRT
  // - CPU
  // - LTE
  return State::CPU;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::CPU:
    return handle_CPU(event);
  case State::LTE:
    return handle_LTE(event);
  case State::CRT:
    return handle_CRT(event);
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
  State state = State::LTE;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
