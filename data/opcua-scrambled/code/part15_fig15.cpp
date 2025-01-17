#include <stdexcept>
struct Event
{
};

enum class State
{
  MIM,
  TCP,
  TLD,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::MIM:
      return "MIM";
    case State::TCP:
      return "TCP";
    case State::TLD:
      return "TLD";
  }
  return "?";
}

State handle_MIM(Event const & event)
{
  // Check the event and return one of the following states:
  // - TLD
  return State::MIM;
}

State handle_TLD(Event const & event)
{
  // Check the event and return one of the following states:
  // - TCP
  return State::TLD;
}

State handle_TCP(Event const & event)
{
  // Check the event and return one of the following states:
  // - TLD
  return State::TCP;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::MIM:
    return handle_MIM(event);
  case State::TCP:
    return handle_TCP(event);
  case State::TLD:
    return handle_TLD(event);
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
  State state = State::MIM;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
