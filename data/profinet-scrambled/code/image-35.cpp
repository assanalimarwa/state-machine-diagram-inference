#include <stdexcept>
struct Event
{
};

enum class State
{
  DOS,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::DOS:
      return "DOS";
  }
  return "?";
}

State handle_DOS(Event const & event)
{
  // Check the event and return one of the following states:
  // - DOS
  return State::DOS;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::DOS:
    return handle_DOS(event);
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
