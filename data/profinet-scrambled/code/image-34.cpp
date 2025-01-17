#include <stdexcept>
struct Event
{
};

enum class State
{
  SSH,
  DOS,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::SSH:
      return "SSH";
    case State::DOS:
      return "DOS";
  }
  return "?";
}

State handle_SSH(Event const & event)
{
  // Check the event and return one of the following states:
  // - SSH
  // - DOS
  return State::SSH;
}

State handle_DOS(Event const & event)
{
  // Check the event and return one of the following states:
  // - SSH
  // - DOS
  return State::DOS;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::SSH:
    return handle_SSH(event);
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
  State state = State::SSH;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
