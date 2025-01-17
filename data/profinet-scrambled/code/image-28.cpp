#include <stdexcept>
struct Event
{
};

enum class State
{
  EEP,
  PPT,
  IDE,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::EEP:
      return "EEP";
    case State::PPT:
      return "PPT";
    case State::IDE:
      return "IDE";
  }
  return "?";
}

State handle_EEP(Event const & event)
{
  // Check the event and return one of the following states:
  // - IDE
  return State::EEP;
}

State handle_IDE(Event const & event)
{
  // Check the event and return one of the following states:
  // - IDE
  // - PPT
  return State::IDE;
}

State handle_PPT(Event const & event)
{
  // Check the event and return one of the following states:
  // - IDE
  // - PPT
  return State::PPT;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::EEP:
    return handle_EEP(event);
  case State::PPT:
    return handle_PPT(event);
  case State::IDE:
    return handle_IDE(event);
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
  State state = State::EEP;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
