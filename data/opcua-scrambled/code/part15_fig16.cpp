#include <stdexcept>
struct Event
{
};

enum class State
{
  SLQ,
  SSH,
  IAM,
  PHP,
  SDK,
  WAF _DV,
  RDP,
  MFA,
  SQL,
  CDN,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::SLQ:
      return "SLQ";
    case State::SSH:
      return "SSH";
    case State::IAM:
      return "IAM";
    case State::PHP:
      return "PHP";
    case State::SDK:
      return "SDK";
    case State::WAF _DV:
      return "WAF _DV";
    case State::RDP:
      return "RDP";
    case State::MFA:
      return "MFA";
    case State::SQL:
      return "SQL";
    case State::CDN:
      return "CDN";
  }
  return "?";
}

State handle_IAM(Event const & event)
{
  // Check the event and return one of the following states:
  // - SQL
  return State::IAM;
}

State handle_SQL(Event const & event)
{
  // Check the event and return one of the following states:
  // - SQL
  // - WAF _DV
  // - SSH
  return State::SQL;
}

State handle_PHP(Event const & event)
{
  // Check the event and return one of the following states:
  // - SLQ
  // - MFA
  return State::PHP;
}

State handle_WAF _DV(Event const & event)
{
  // Check the event and return one of the following states:
  // - SDK
  return State::WAF _DV;
}

State handle_MFA(Event const & event)
{
  // Check the event and return one of the following states:
  // - SDK
  // - SSH
  return State::MFA;
}

State handle_SDK(Event const & event)
{
  // Check the event and return one of the following states:
  // - SLQ
  return State::SDK;
}

State handle_SLQ(Event const & event)
{
  // Check the event and return one of the following states:
  // - CDN
  return State::SLQ;
}

State handle_CDN(Event const & event)
{
  // Check the event and return one of the following states:
  // - SSH
  // - SDK
  // - RDP
  return State::CDN;
}

State handle_RDP(Event const & event)
{
  // Check the event and return one of the following states:
  // - SDK
  // - SSH
  // - PHP
  return State::RDP;
}

State handle_SSH(Event const & event)
{
  // Check the event and return one of the following states:
  // - PHP
  return State::SSH;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::SLQ:
    return handle_SLQ(event);
  case State::SSH:
    return handle_SSH(event);
  case State::IAM:
    return handle_IAM(event);
  case State::PHP:
    return handle_PHP(event);
  case State::SDK:
    return handle_SDK(event);
  case State::WAF _DV:
    return handle_WAF _DV(event);
  case State::RDP:
    return handle_RDP(event);
  case State::MFA:
    return handle_MFA(event);
  case State::SQL:
    return handle_SQL(event);
  case State::CDN:
    return handle_CDN(event);
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
  State state = State::IAM;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
