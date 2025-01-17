#include <gtest/gtest.h>
struct Event{};
enum class State
{
  TCP,
  IOT,
  OOP,
  IOS,
  IVR,
  API,
};
State handle_event(State const state, Event const & evnet);

TEST(App, TCP)
{
  // CHeck path ['TCP']
  Event event;
  auto state = State::TCP;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::TCP);
}

TEST(App, IOS)
{
  // CHeck path ['TCP', 'IOS', 'TCP']
  Event event;
  auto state = State::TCP;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::TCP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::IOS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::TCP);
}

TEST(App, API)
{
  // CHeck path ['TCP', 'API', 'TCP']
  Event event;
  auto state = State::TCP;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::TCP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::API);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::TCP);
}

TEST(App, OOP)
{
  // CHeck path ['TCP', 'OOP', 'API', 'TCP']
  Event event;
  auto state = State::TCP;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::TCP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::OOP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::API);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::TCP);
}

TEST(App, IOT)
{
  // CHeck path ['TCP', 'API', 'IOT', 'TCP']
  Event event;
  auto state = State::TCP;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::TCP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::API);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::IOT);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::TCP);
}

TEST(App, IVR)
{
  // CHeck path ['TCP', 'IOS', 'IVR', 'IOS', 'TCP']
  Event event;
  auto state = State::TCP;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::TCP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::IOS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::IVR);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::IOS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::TCP);
}

