#include <stdexcept>
struct Event
{
};

enum class State
{
  JDK,
  AES,
  GPU,
  PPT,
  PHP,
  OSX,
  EDI,
  SDK,
  SSD,
  RAM,
  ERP,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::JDK:
      return "JDK";
    case State::AES:
      return "AES";
    case State::GPU:
      return "GPU";
    case State::PPT:
      return "PPT";
    case State::PHP:
      return "PHP";
    case State::OSX:
      return "OSX";
    case State::EDI:
      return "EDI";
    case State::SDK:
      return "SDK";
    case State::SSD:
      return "SSD";
    case State::RAM:
      return "RAM";
    case State::ERP:
      return "ERP";
  }
  return "?";
}

State handle_ERP(Event const & event)
{
  // Check the event and return one of the following states:
  // - PHP
  return State::ERP;
}

State handle_OSX(Event const & event)
{
  // Check the event and return one of the following states:
  // - ERP
  return State::OSX;
}

State handle_PHP(Event const & event)
{
  // Check the event and return one of the following states:
  // - AES
  return State::PHP;
}

State handle_AES(Event const & event)
{
  // Check the event and return one of the following states:
  // - OSX
  // - EDI
  // - PPT
  return State::AES;
}

State handle_JDK(Event const & event)
{
  // Check the event and return one of the following states:
  // - PPT
  return State::JDK;
}

State handle_EDI(Event const & event)
{
  // Check the event and return one of the following states:
  // - RAM
  return State::EDI;
}

State handle_RAM(Event const & event)
{
  // Check the event and return one of the following states:
  // - JDK
  return State::RAM;
}

State handle_SDK(Event const & event)
{
  // Check the event and return one of the following states:
  // - JDK
  // - RAM
  return State::SDK;
}

State handle_SSD(Event const & event)
{
  // Check the event and return one of the following states:
  // - GPU
  return State::SSD;
}

State handle_GPU(Event const & event)
{
  // Check the event and return one of the following states:
  // - SDK
  return State::GPU;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::JDK:
    return handle_JDK(event);
  case State::AES:
    return handle_AES(event);
  case State::GPU:
    return handle_GPU(event);
  case State::PPT:
    return handle_PPT(event);
  case State::PHP:
    return handle_PHP(event);
  case State::OSX:
    return handle_OSX(event);
  case State::EDI:
    return handle_EDI(event);
  case State::SDK:
    return handle_SDK(event);
  case State::SSD:
    return handle_SSD(event);
  case State::RAM:
    return handle_RAM(event);
  case State::ERP:
    return handle_ERP(event);
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
  State state = State::ERP;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
