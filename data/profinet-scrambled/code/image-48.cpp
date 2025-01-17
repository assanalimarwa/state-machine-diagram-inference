#include <stdexcept>
struct Event
{
};

enum class State
{
  DNS,
  DVR,
  PHP,
  AIK,
  MFA,
  DOS,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::DNS:
      return "DNS";
    case State::DVR:
      return "DVR";
    case State::PHP:
      return "PHP";
    case State::AIK:
      return "AIK";
    case State::MFA:
      return "MFA";
    case State::DOS:
      return "DOS";
  }
  return "?";
}

State handle_DVR(Event const & event)
{
  // Check the event and return one of the following states:
  // - DVR
  // - DOS
  return State::DVR;
}

State handle_DOS(Event const & event)
{
  // Check the event and return one of the following states:
  // - DVR
  // - DOS
  // - AIK
  // - PHP
  return State::DOS;
}

State handle_AIK(Event const & event)
{
  // Check the event and return one of the following states:
  // - DOS
  // - AIK
  // - DVR
  return State::AIK;
}

State handle_PHP(Event const & event)
{
  // Check the event and return one of the following states:
  // - PHP
  // - MFA
  // - DVR
  return State::PHP;
}

State handle_MFA(Event const & event)
{
  // Check the event and return one of the following states:
  // - MFA
  // - DNS
  // - DVR
  return State::MFA;
}

State handle_DNS(Event const & event)
{
  // Check the event and return one of the following states:
  // - MFA
  // - DNS
  // - DVR
  return State::DNS;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::DNS:
    return handle_DNS(event);
  case State::DVR:
    return handle_DVR(event);
  case State::PHP:
    return handle_PHP(event);
  case State::AIK:
    return handle_AIK(event);
  case State::MFA:
    return handle_MFA(event);
  case State::DOS:
    return handle_DOS(event);
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
  State state = State::DVR;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
