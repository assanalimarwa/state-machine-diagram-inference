#include <gtest/gtest.h>
struct Event{};
enum class State
{
  IOS,
  IPX,
  DOS,
  SAS,
};
State handle_event(State const state, Event const & evnet);

TEST(App, IPX)
{
  // CHeck path ['IPX']
  Event event;
  auto state = State::IPX;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::IPX);
}

TEST(App, IOS)
{
  // CHeck path ['IPX', 'IOS', 'IPX']
  Event event;
  auto state = State::IPX;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::IPX);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::IOS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::IPX);
}

TEST(App, SAS)
{
  // CHeck path ['IPX', 'IOS', 'SAS', 'IPX']
  Event event;
  auto state = State::IPX;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::IPX);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::IOS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SAS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::IPX);
}

TEST(App, DOS)
{
  // CHeck path ['IPX', 'IOS', 'SAS', 'DOS', 'IPX']
  Event event;
  auto state = State::IPX;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::IPX);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::IOS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SAS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DOS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::IPX);
}

