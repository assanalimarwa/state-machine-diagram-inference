#include <stdexcept>
struct Event
{
};

enum class State
{
  EXE,
  MAC,
  ERP,
  SDK,
  XSS,
  AIK,
  BIOS,
  WAP,
  LAN,
  GIF,
  SQL,
  CPL,
  VPS,
  JSO,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::EXE:
      return "EXE";
    case State::MAC:
      return "MAC";
    case State::ERP:
      return "ERP";
    case State::SDK:
      return "SDK";
    case State::XSS:
      return "XSS";
    case State::AIK:
      return "AIK";
    case State::BIOS:
      return "BIOS";
    case State::WAP:
      return "WAP";
    case State::LAN:
      return "LAN";
    case State::GIF:
      return "GIF";
    case State::SQL:
      return "SQL";
    case State::CPL:
      return "CPL";
    case State::VPS:
      return "VPS";
    case State::JSO:
      return "JSO";
  }
  return "?";
}

State handle_SDK(Event const & event)
{
  // Check the event and return one of the following states:
  // - AIK
  return State::SDK;
}

State handle_AIK(Event const & event)
{
  // Check the event and return one of the following states:
  // - MAC
  return State::AIK;
}

State handle_BIOS(Event const & event)
{
  // Check the event and return one of the following states:
  // - SDK
  return State::BIOS;
}

State handle_MAC(Event const & event)
{
  // Check the event and return one of the following states:
  // - BIOS
  // - VPS
  // - CPL
  // - EXE
  return State::MAC;
}

State handle_JSO(Event const & event)
{
  // Check the event and return one of the following states:
  // - CPL
  return State::JSO;
}

State handle_XSS(Event const & event)
{
  // Check the event and return one of the following states:
  // - MAC
  return State::XSS;
}

State handle_EXE(Event const & event)
{
  // Check the event and return one of the following states:
  // - SQL
  return State::EXE;
}

State handle_SQL(Event const & event)
{
  // Check the event and return one of the following states:
  // - XSS
  return State::SQL;
}

State handle_LAN(Event const & event)
{
  // Check the event and return one of the following states:
  // - JSO
  return State::LAN;
}

State handle_VPS(Event const & event)
{
  // Check the event and return one of the following states:
  // - LAN
  return State::VPS;
}

State handle_WAP(Event const & event)
{
  // Check the event and return one of the following states:
  // - LAN
  // - JSO
  return State::WAP;
}

State handle_ERP(Event const & event)
{
  // Check the event and return one of the following states:
  // - WAP
  return State::ERP;
}

State handle_GIF(Event const & event)
{
  // Check the event and return one of the following states:
  // - ERP
  return State::GIF;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::EXE:
    return handle_EXE(event);
  case State::MAC:
    return handle_MAC(event);
  case State::ERP:
    return handle_ERP(event);
  case State::SDK:
    return handle_SDK(event);
  case State::XSS:
    return handle_XSS(event);
  case State::AIK:
    return handle_AIK(event);
  case State::BIOS:
    return handle_BIOS(event);
  case State::WAP:
    return handle_WAP(event);
  case State::LAN:
    return handle_LAN(event);
  case State::GIF:
    return handle_GIF(event);
  case State::SQL:
    return handle_SQL(event);
  case State::CPL:
    return handle_CPL(event);
  case State::VPS:
    return handle_VPS(event);
  case State::JSO:
    return handle_JSO(event);
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
  State state = State::SDK;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
