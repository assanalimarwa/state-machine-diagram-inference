#include <stdexcept>
struct Event
{
};

enum class State
{
  X,
  GUI,
  CSS,
  RAM,
  CP,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::X:
      return "X";
    case State::GUI:
      return "GUI";
    case State::CSS:
      return "CSS";
    case State::RAM:
      return "RAM";
    case State::CP:
      return "CP";
  }
  return "?";
}

State handle_X(Event const & event)
{
  // Check the event and return one of the following states:
  // - RAM
  // - CSS
  return State::X;
}

State handle_RAM(Event const & event)
{
  // Check the event and return one of the following states:
  // - CP
  // - GUI
  return State::RAM;
}

State handle_GUI(Event const & event)
{
  // Check the event and return one of the following states:
  // - CP
  // - X
  return State::GUI;
}

State handle_CSS(Event const & event)
{
  // Check the event and return one of the following states:
  // - X
  // - CP
  return State::CSS;
}

State handle_CP(Event const & event)
{
  // Check the event and return one of the following states:
  // - X
  return State::CP;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::X:
    return handle_X(event);
  case State::GUI:
    return handle_GUI(event);
  case State::CSS:
    return handle_CSS(event);
  case State::RAM:
    return handle_RAM(event);
  case State::CP:
    return handle_CP(event);
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
  State state = State::X;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
