#include <stdexcept>
struct Event
{
};

enum class State
{
  AIX,
  IIS,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::AIX:
      return "AIX";
    case State::IIS:
      return "IIS";
  }
  return "?";
}

State handle_AIX(Event const & event)
{
  // Check the event and return one of the following states:
  // - IIS
  return State::AIX;
}

State handle_IIS(Event const & event)
{
  // Check the event and return one of the following states:
  // - AIX
  // - IIS
  return State::IIS;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::AIX:
    return handle_AIX(event);
  case State::IIS:
    return handle_IIS(event);
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
  State state = State::AIX;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
