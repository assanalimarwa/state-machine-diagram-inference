#include <stdexcept>
struct Event
{
};

enum class State
{
  DAC,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::DAC:
      return "DAC";
  }
  return "?";
}

State handle_DAC(Event const & event)
{
  // Check the event and return one of the following states:
  // - DAC
  return State::DAC;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::DAC:
    return handle_DAC(event);
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
  State state = State::DAC;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
