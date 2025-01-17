#include <gtest/gtest.h>
struct Event{};
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
State handle_event(State const state, Event const & evnet);

TEST(App, ERP)
{
  // CHeck path ['ERP']
  Event event;
  auto state = State::ERP;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::ERP);
}

TEST(App, PHP)
{
  // CHeck path ['ERP', 'PHP', 'AES', 'OSX', 'ERP']
  Event event;
  auto state = State::ERP;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::ERP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::PHP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::AES);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::OSX);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::ERP);
}

TEST(App, OSX)
{
  // CHeck path ['ERP', 'PHP', 'AES', 'OSX', 'ERP']
  Event event;
  auto state = State::ERP;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::ERP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::PHP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::AES);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::OSX);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::ERP);
}

TEST(App, AES)
{
  // CHeck path ['ERP', 'PHP', 'AES', 'OSX', 'ERP']
  Event event;
  auto state = State::ERP;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::ERP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::PHP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::AES);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::OSX);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::ERP);
}

