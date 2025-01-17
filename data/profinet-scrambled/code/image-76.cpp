#include <stdexcept>
struct Event
{
};

enum class State
{
  GUI,
  EEP,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::GUI:
      return "GUI";
    case State::EEP:
      return "EEP";
  }
  return "?";
}

State handle_EEP(Event const & event)
{
  // Check the event and return one of the following states:
  // - EEP
  // - GUI
  return State::EEP;
}

State handle_GUI(Event const & event)
{
  // Check the event and return one of the following states:
  // - EEP
  // - GUI
  return State::GUI;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::GUI:
    return handle_GUI(event);
  case State::EEP:
    return handle_EEP(event);
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
