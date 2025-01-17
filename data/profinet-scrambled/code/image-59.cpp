#include <stdexcept>
struct Event
{
};

enum class State
{
  PNG,
  IoT,
  PPT,
  UDP,
  HTML,
  ERP,
  DVR,
  KVM,
  VPS,
  RDS,
  IVR,
  ASP,
};

std::string format_state(State const state)
{
  switch(state)
  {
    case State::PNG:
      return "PNG";
    case State::IoT:
      return "IoT";
    case State::PPT:
      return "PPT";
    case State::UDP:
      return "UDP";
    case State::HTML:
      return "HTML";
    case State::ERP:
      return "ERP";
    case State::DVR:
      return "DVR";
    case State::KVM:
      return "KVM";
    case State::VPS:
      return "VPS";
    case State::RDS:
      return "RDS";
    case State::IVR:
      return "IVR";
    case State::ASP:
      return "ASP";
  }
  return "?";
}

State handle_UDP(Event const & event)
{
  // Check the event and return one of the following states:
  // - UDP
  // - ASP
  return State::UDP;
}

State handle_ASP(Event const & event)
{
  // Check the event and return one of the following states:
  // - UDP
  // - IoT
  // - VPS
  return State::ASP;
}

State handle_IoT(Event const & event)
{
  // Check the event and return one of the following states:
  // - IoT
  // - VPS
  // - UDP
  return State::IoT;
}

State handle_VPS(Event const & event)
{
  // Check the event and return one of the following states:
  // - VPS
  // - HTML
  // - UDP
  return State::VPS;
}

State handle_HTML(Event const & event)
{
  // Check the event and return one of the following states:
  // - RDS
  // - UDP
  // - KVM
  return State::HTML;
}

State handle_RDS(Event const & event)
{
  // Check the event and return one of the following states:
  // - ERP
  // - UDP
  // - KVM
  return State::RDS;
}

State handle_ERP(Event const & event)
{
  // Check the event and return one of the following states:
  // - DVR
  // - UDP
  // - KVM
  // - PNG
  return State::ERP;
}

State handle_DVR(Event const & event)
{
  // Check the event and return one of the following states:
  // - PNG
  // - UDP
  // - KVM
  // - PPT
  return State::DVR;
}

State handle_PNG(Event const & event)
{
  // Check the event and return one of the following states:
  // - PPT
  // - UDP
  // - KVM
  return State::PNG;
}

State handle_PPT(Event const & event)
{
  // Check the event and return one of the following states:
  // - PPT
  // - IVR
  // - UDP
  // - KVM
  return State::PPT;
}

State handle_IVR(Event const & event)
{
  // Check the event and return one of the following states:
  // - IVR
  // - KVM
  // - UDP
  return State::IVR;
}

State handle_KVM(Event const & event)
{
  // Check the event and return one of the following states:
  // - KVM
  // - UDP
  return State::KVM;
}

State handle_event(State const last_state, Event const & event)
{
  switch(last_state)
  {
  case State::PNG:
    return handle_PNG(event);
  case State::IoT:
    return handle_IoT(event);
  case State::PPT:
    return handle_PPT(event);
  case State::UDP:
    return handle_UDP(event);
  case State::HTML:
    return handle_HTML(event);
  case State::ERP:
    return handle_ERP(event);
  case State::DVR:
    return handle_DVR(event);
  case State::KVM:
    return handle_KVM(event);
  case State::VPS:
    return handle_VPS(event);
  case State::RDS:
    return handle_RDS(event);
  case State::IVR:
    return handle_IVR(event);
  case State::ASP:
    return handle_ASP(event);
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
  State state = State::UDP;
  for(;;)
  {
    auto event = wait_for_event();
    state = handle_event(state, event);
  }
}
