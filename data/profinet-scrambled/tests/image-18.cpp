#include <gtest/gtest.h>
struct Event{};
enum class State
{
  SAS,
  ASP,
  XSS,
  CPU,
  SLA,
};
State handle_event(State const state, Event const & evnet);

TEST(App, SLA)
{
  // CHeck path ['SLA']
  Event event;
  auto state = State::SLA;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SLA);
}

TEST(App, CPU)
{
  // CHeck path ['SLA', 'CPU', 'SLA']
  Event event;
  auto state = State::SLA;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SLA);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::CPU);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SLA);
}

TEST(App, XSS)
{
  // CHeck path ['SLA', 'CPU', 'XSS', 'SAS', 'SLA']
  Event event;
  auto state = State::SLA;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SLA);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::CPU);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::XSS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SAS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SLA);
}

TEST(App, ASP)
{
  // CHeck path ['SLA', 'CPU', 'ASP', 'SLA']
  Event event;
  auto state = State::SLA;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SLA);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::CPU);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::ASP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SLA);
}

TEST(App, SAS)
{
  // CHeck path ['SLA', 'CPU', 'XSS', 'SAS', 'SLA']
  Event event;
  auto state = State::SLA;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SLA);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::CPU);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::XSS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SAS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SLA);
}

