#include <stdexcept>
struct Event
{
};

enum class State
{
  GUI,
  AIX,
  YML,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::GUI:
      return "GUI";
    case State::AIX:
      return "AIX";
    case State::YML:
      return "YML";
  }
  return "?";
}

State handle_YML(Event const & event)
{
  // Check the event and return one of the following states:
  // - GUI
  return State::YML;
}

State handle_GUI(Event const & event)
{
  // Check the event and return one of the following states:
  // - GUI
  // - AIX
  return State::GUI;
}

State handle_AIX(Event const & event)
{
  // Check the event and return one of the following states:
  // - GUI
  // - AIX
  return State::AIX;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::GUI:
    return handle_GUI(event);
  case State::AIX:
    return handle_AIX(event);
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
  State state = State::YML;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
