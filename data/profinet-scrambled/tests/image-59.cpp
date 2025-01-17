#include <gtest/gtest.h>
struct Event{};
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
State handle_event(State const state, Event const & evnet);

TEST(App, UDP)
{
  // CHeck path ['UDP']
  Event event;
  auto state = State::UDP;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::UDP);
}

TEST(App, ASP)
{
  // CHeck path ['UDP', 'ASP', 'UDP']
  Event event;
  auto state = State::UDP;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::UDP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::ASP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::UDP);
}

TEST(App, IoT)
{
  // CHeck path ['UDP', 'ASP', 'IoT', 'UDP']
  Event event;
  auto state = State::UDP;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::UDP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::ASP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::IoT);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::UDP);
}

TEST(App, VPS)
{
  // CHeck path ['UDP', 'ASP', 'VPS', 'UDP']
  Event event;
  auto state = State::UDP;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::UDP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::ASP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::VPS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::UDP);
}

TEST(App, HTML)
{
  // CHeck path ['UDP', 'ASP', 'VPS', 'HTML', 'UDP']
  Event event;
  auto state = State::UDP;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::UDP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::ASP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::VPS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::HTML);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::UDP);
}

TEST(App, RDS)
{
  // CHeck path ['UDP', 'ASP', 'VPS', 'HTML', 'RDS', 'UDP']
  Event event;
  auto state = State::UDP;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::UDP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::ASP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::VPS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::HTML);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::RDS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::UDP);
}

TEST(App, KVM)
{
  // CHeck path ['UDP', 'ASP', 'VPS', 'HTML', 'KVM', 'UDP']
  Event event;
  auto state = State::UDP;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::UDP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::ASP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::VPS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::HTML);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::KVM);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::UDP);
}

TEST(App, ERP)
{
  // CHeck path ['UDP', 'ASP', 'VPS', 'HTML', 'RDS', 'ERP', 'UDP']
  Event event;
  auto state = State::UDP;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::UDP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::ASP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::VPS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::HTML);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::RDS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::ERP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::UDP);
}

TEST(App, DVR)
{
  // CHeck path ['UDP', 'ASP', 'VPS', 'HTML', 'RDS', 'ERP', 'DVR', 'UDP']
  Event event;
  auto state = State::UDP;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::UDP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::ASP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::VPS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::HTML);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::RDS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::ERP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DVR);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::UDP);
}

TEST(App, PNG)
{
  // CHeck path ['UDP', 'ASP', 'VPS', 'HTML', 'RDS', 'ERP', 'PNG', 'UDP']
  Event event;
  auto state = State::UDP;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::UDP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::ASP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::VPS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::HTML);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::RDS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::ERP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::PNG);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::UDP);
}

TEST(App, PPT)
{
  // CHeck path ['UDP', 'ASP', 'VPS', 'HTML', 'RDS', 'ERP', 'DVR', 'PPT', 'UDP']
  Event event;
  auto state = State::UDP;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::UDP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::ASP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::VPS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::HTML);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::RDS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::ERP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DVR);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::PPT);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::UDP);
}

TEST(App, IVR)
{
  // CHeck path ['UDP', 'ASP', 'VPS', 'HTML', 'RDS', 'ERP', 'DVR', 'PPT', 'IVR', 'UDP']
  Event event;
  auto state = State::UDP;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::UDP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::ASP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::VPS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::HTML);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::RDS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::ERP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DVR);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::PPT);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::IVR);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::UDP);
}

