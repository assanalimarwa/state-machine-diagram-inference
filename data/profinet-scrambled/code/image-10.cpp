#include <stdexcept>
struct Event
{
};

enum class State
{
  GIF,
  SSH,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::GIF:
      return "GIF";
    case State::SSH:
      return "SSH";
  }
  return "?";
}

State handle_SSH(Event const & event)
{
  // Check the event and return one of the following states:
  // - SSH
  // - GIF
  return State::SSH;
}

State handle_GIF(Event const & event)
{
  // Check the event and return one of the following states:
  // - GIF
  return State::GIF;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::GIF:
    return handle_GIF(event);
  case State::SSH:
    return handle_SSH(event);
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
