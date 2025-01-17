#include <gtest/gtest.h>
struct Event{};
enum class State
{
  SDK,
  PPT,
  SSD,
};
State handle_event(State const state, Event const & evnet);

TEST(App, PPT)
{
  // CHeck path ['PPT']
  Event event;
  auto state = State::PPT;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::PPT);
}

TEST(App, SDK)
{
  // CHeck path ['PPT', 'SDK', 'PPT']
  Event event;
  auto state = State::PPT;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::PPT);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SDK);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::PPT);
}

TEST(App, SSD)
{
  // CHeck path ['PPT', 'SDK', 'SSD', 'PPT']
  Event event;
  auto state = State::PPT;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::PPT);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SDK);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SSD);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::PPT);
}

