#include <stdexcept>
struct Event
{
};

enum class State
{
  SSH,
  TLD,
  GIF,
  SSD,
  NTP,
  SLA,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::SSH:
      return "SSH";
    case State::TLD:
      return "TLD";
    case State::GIF:
      return "GIF";
    case State::SSD:
      return "SSD";
    case State::NTP:
      return "NTP";
    case State::SLA:
      return "SLA";
  }
  return "?";
}

State handle_NTP(Event const & event)
{
  // Check the event and return one of the following states:
  // - TLD
  return State::NTP;
}

State handle_TLD(Event const & event)
{
  // Check the event and return one of the following states:
  // - TLD
  // - SSD
  return State::TLD;
}

State handle_SSD(Event const & event)
{
  // Check the event and return one of the following states:
  // - TLD
  // - SSD
  // - GIF
  // - SLA
  return State::SSD;
}

State handle_GIF(Event const & event)
{
  // Check the event and return one of the following states:
  // - SSD
  // - GIF
  return State::GIF;
}

State handle_SLA(Event const & event)
{
  // Check the event and return one of the following states:
  // - SLA
  // - SSH
  // - SSD
  return State::SLA;
}

State handle_SSH(Event const & event)
{
  // Check the event and return one of the following states:
  // - SSH
  // - TLD
  // - SSD
  return State::SSH;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::SSH:
    return handle_SSH(event);
  case State::TLD:
    return handle_TLD(event);
  case State::GIF:
    return handle_GIF(event);
  case State::SSD:
    return handle_SSD(event);
  case State::NTP:
    return handle_NTP(event);
  case State::SLA:
    return handle_SLA(event);
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
  State state = State::NTP;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
