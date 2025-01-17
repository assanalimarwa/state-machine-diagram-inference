#include <gtest/gtest.h>
struct Event{};
enum class State
{
  GPU,
  MAC,
  EDI,
  AIK,
  CPL,
  LAN,
  SIP,
};
State handle_event(State const state, Event const & evnet);

TEST(App, CPL)
{
  // CHeck path ['CPL']
  Event event;
  auto state = State::CPL;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::CPL);
}

TEST(App, LAN)
{
  // CHeck path ['CPL', 'LAN', 'CPL']
  Event event;
  auto state = State::CPL;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::CPL);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::LAN);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::CPL);
}

TEST(App, SIP)
{
  // CHeck path ['CPL', 'LAN', 'SIP', 'CPL']
  Event event;
  auto state = State::CPL;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::CPL);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::LAN);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SIP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::CPL);
}

TEST(App, MAC)
{
  // CHeck path ['CPL', 'LAN', 'SIP', 'MAC', 'CPL']
  Event event;
  auto state = State::CPL;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::CPL);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::LAN);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SIP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::MAC);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::CPL);
}

TEST(App, AIK)
{
  // CHeck path ['CPL', 'LAN', 'SIP', 'MAC', 'AIK', 'CPL']
  Event event;
  auto state = State::CPL;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::CPL);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::LAN);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SIP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::MAC);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::AIK);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::CPL);
}

TEST(App, EDI)
{
  // CHeck path ['CPL', 'LAN', 'SIP', 'MAC', 'AIK', 'EDI', 'CPL']
  Event event;
  auto state = State::CPL;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::CPL);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::LAN);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SIP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::MAC);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::AIK);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::EDI);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::CPL);
}

TEST(App, GPU)
{
  // CHeck path ['CPL', 'LAN', 'SIP', 'MAC', 'AIK', 'EDI', 'GPU', 'CPL']
  Event event;
  auto state = State::CPL;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::CPL);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::LAN);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SIP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::MAC);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::AIK);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::EDI);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::GPU);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::CPL);
}

