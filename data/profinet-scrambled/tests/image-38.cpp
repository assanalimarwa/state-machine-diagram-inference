#include <gtest/gtest.h>
struct Event{};
enum class State
{
  PPP,
  TCP,
  DOS,
  YML,
};
State handle_event(State const state, Event const & evnet);

TEST(App, PPP)
{
  // CHeck path ['PPP']
  Event event;
  auto state = State::PPP;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::PPP);
}

TEST(App, DOS)
{
  // CHeck path ['PPP', 'DOS', 'PPP']
  Event event;
  auto state = State::PPP;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::PPP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DOS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::PPP);
}

TEST(App, YML)
{
  // CHeck path ['PPP', 'DOS', 'YML', 'PPP']
  Event event;
  auto state = State::PPP;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::PPP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DOS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::YML);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::PPP);
}

TEST(App, TCP)
{
  // CHeck path ['PPP', 'DOS', 'YML', 'TCP', 'PPP']
  Event event;
  auto state = State::PPP;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::PPP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DOS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::YML);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::TCP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::PPP);
}

