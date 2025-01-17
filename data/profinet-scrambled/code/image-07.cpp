#include <stdexcept>
struct Event
{
};

enum class State
{
  DPI,
  SSH,
  IDE,
  CLI,
  RAM,
  CRT,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::DPI:
      return "DPI";
    case State::SSH:
      return "SSH";
    case State::IDE:
      return "IDE";
    case State::CLI:
      return "CLI";
    case State::RAM:
      return "RAM";
    case State::CRT:
      return "CRT";
  }
  return "?";
}

State handle_DPI(Event const & event)
{
  // Check the event and return one of the following states:
  // - SSH
  return State::DPI;
}

State handle_SSH(Event const & event)
{
  // Check the event and return one of the following states:
  // - SSH
  // - RAM
  return State::SSH;
}

State handle_RAM(Event const & event)
{
  // Check the event and return one of the following states:
  // - SSH
  // - RAM
  // - IDE
  // - CRT
  return State::RAM;
}

State handle_IDE(Event const & event)
{
  // Check the event and return one of the following states:
  // - RAM
  // - IDE
  // - SSH
  return State::IDE;
}

State handle_CRT(Event const & event)
{
  // Check the event and return one of the following states:
  // - CRT
  // - CLI
  // - SSH
  return State::CRT;
}

State handle_CLI(Event const & event)
{
  // Check the event and return one of the following states:
  // - CRT
  // - CLI
  // - SSH
  return State::CLI;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::DPI:
    return handle_DPI(event);
  case State::SSH:
    return handle_SSH(event);
  case State::IDE:
    return handle_IDE(event);
  case State::CLI:
    return handle_CLI(event);
  case State::RAM:
    return handle_RAM(event);
  case State::CRT:
    return handle_CRT(event);
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
  State state = State::DPI;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
