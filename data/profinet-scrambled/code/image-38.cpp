#include <stdexcept>
struct Event
{
};

enum class State
{
  PPP,
  TCP,
  DOS,
  YML,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::PPP:
      return "PPP";
    case State::TCP:
      return "TCP";
    case State::DOS:
      return "DOS";
    case State::YML:
      return "YML";
  }
  return "?";
}

State handle_PPP(Event const & event)
{
  // Check the event and return one of the following states:
  // - PPP
  // - DOS
  return State::PPP;
}

State handle_DOS(Event const & event)
{
  // Check the event and return one of the following states:
  // - PPP
  // - DOS
  // - YML
  return State::DOS;
}

State handle_YML(Event const & event)
{
  // Check the event and return one of the following states:
  // - YML
  // - TCP
  // - PPP
  return State::YML;
}

State handle_TCP(Event const & event)
{
  // Check the event and return one of the following states:
  // - YML
  // - TCP
  // - PPP
  return State::TCP;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::PPP:
    return handle_PPP(event);
  case State::TCP:
    return handle_TCP(event);
  case State::DOS:
    return handle_DOS(event);
  case State::YML:
    return handle_YML(event);
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
  State state = State::PPP;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
