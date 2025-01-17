#include <stdexcept>
struct Event
{
};

enum class State
{
  IOS,
  IPX,
  DOS,
  SAS,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::IOS:
      return "IOS";
    case State::IPX:
      return "IPX";
    case State::DOS:
      return "DOS";
    case State::SAS:
      return "SAS";
  }
  return "?";
}

State handle_IPX(Event const & event)
{
  // Check the event and return one of the following states:
  // - IPX
  // - IOS
  return State::IPX;
}

State handle_IOS(Event const & event)
{
  // Check the event and return one of the following states:
  // - IPX
  // - IOS
  // - SAS
  return State::IOS;
}

State handle_SAS(Event const & event)
{
  // Check the event and return one of the following states:
  // - SAS
  // - DOS
  // - IPX
  return State::SAS;
}

State handle_DOS(Event const & event)
{
  // Check the event and return one of the following states:
  // - DOS
  // - IPX
  // - IOS
  return State::DOS;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::IOS:
    return handle_IOS(event);
  case State::IPX:
    return handle_IPX(event);
  case State::DOS:
    return handle_DOS(event);
  case State::SAS:
    return handle_SAS(event);
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
  State state = State::IPX;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
