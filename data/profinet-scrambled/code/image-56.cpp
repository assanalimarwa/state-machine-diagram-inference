#include <stdexcept>
struct Event
{
};

enum class State
{
  SDK,
  AIX,
  IOT,
  ASP,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::SDK:
      return "SDK";
    case State::AIX:
      return "AIX";
    case State::IOT:
      return "IOT";
    case State::ASP:
      return "ASP";
  }
  return "?";
}

State handle_ASP(Event const & event)
{
  // Check the event and return one of the following states:
  // - AIX
  return State::ASP;
}

State handle_AIX(Event const & event)
{
  // Check the event and return one of the following states:
  // - AIX
  // - ASP
  // - SDK
  return State::AIX;
}

State handle_IOT(Event const & event)
{
  // Check the event and return one of the following states:
  // - IOT
  // - SDK
  // - ASP
  return State::IOT;
}

State handle_SDK(Event const & event)
{
  // Check the event and return one of the following states:
  // - IOT
  // - ASP
  return State::SDK;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::SDK:
    return handle_SDK(event);
  case State::AIX:
    return handle_AIX(event);
  case State::IOT:
    return handle_IOT(event);
  case State::ASP:
    return handle_ASP(event);
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
  State state = State::ASP;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
