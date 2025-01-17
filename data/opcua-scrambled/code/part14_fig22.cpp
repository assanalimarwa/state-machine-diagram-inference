#include <stdexcept>
struct Event
{
};

enum class State
{
  SSH,
  EDI,
  HDD,
  WAF,
  BIOS,
  KV,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::SSH:
      return "SSH";
    case State::EDI:
      return "EDI";
    case State::HDD:
      return "HDD";
    case State::WAF:
      return "WAF";
    case State::BIOS:
      return "BIOS";
    case State::KV:
      return "KV";
  }
  return "?";
}

State handle_SSH(Event const & event)
{
  // Check the event and return one of the following states:
  // - KV
  // - BIOS
  return State::SSH;
}

State handle_HDD(Event const & event)
{
  // Check the event and return one of the following states:
  // - SSH
  // - KV
  return State::HDD;
}

State handle_BIOS(Event const & event)
{
  // Check the event and return one of the following states:
  // - SSH
  // - KV
  // - HDD
  return State::BIOS;
}

State handle_WAF(Event const & event)
{
  // Check the event and return one of the following states:
  // - SSH
  // - BIOS
  return State::WAF;
}

State handle_EDI(Event const & event)
{
  // Check the event and return one of the following states:
  // - WAF
  return State::EDI;
}

State handle_KV(Event const & event)
{
  // Check the event and return one of the following states:
  // - HDD
  // - BIOS
  return State::KV;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::SSH:
    return handle_SSH(event);
  case State::EDI:
    return handle_EDI(event);
  case State::HDD:
    return handle_HDD(event);
  case State::WAF:
    return handle_WAF(event);
  case State::BIOS:
    return handle_BIOS(event);
  case State::KV:
    return handle_KV(event);
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
  State state = State::SSH;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
