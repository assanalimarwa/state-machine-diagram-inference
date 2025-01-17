#include <stdexcept>
struct Event
{
};

enum class State
{
  DOS,
  RDS,
  ROM,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::DOS:
      return "DOS";
    case State::RDS:
      return "RDS";
    case State::ROM:
      return "ROM";
  }
  return "?";
}

State handle_DOS(Event const & event)
{
  // Check the event and return one of the following states:
  // - ROM
  return State::DOS;
}

State handle_ROM(Event const & event)
{
  // Check the event and return one of the following states:
  // - ROM
  // - RDS
  return State::ROM;
}

State handle_RDS(Event const & event)
{
  // Check the event and return one of the following states:
  // - ROM
  // - RDS
  return State::RDS;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::DOS:
    return handle_DOS(event);
  case State::RDS:
    return handle_RDS(event);
  case State::ROM:
    return handle_ROM(event);
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
  State state = State::DOS;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
